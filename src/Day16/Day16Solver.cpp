#include "../../include/Day16Solver.h"

class Room {
public:
    int flow_rate{};
    vector<int> destinations;
};

class MoveP1 {
public:
    int minute;
    int score;
    int room;
    unordered_set<int> path;

    MoveP1(int turn, int score, int room) {
        this->minute = turn;
        this->score = score;
        this->room = room;
    }
};

class MoveP2 {
public:
    int minute;
    int score;
    int my_room;
    int elephant_room;
    int me_waiting;
    int elephant_waiting;
    unordered_set<int> remaining;

    MoveP2(int turn, int score, int start_room, int waiting, int elephant_waiting) {
        this->minute = turn;
        this->score = score;
        this->my_room = start_room;
        this->elephant_room = start_room;
        this->me_waiting = waiting;
        this->elephant_waiting = elephant_waiting;
    }

    bool operator==(const MoveP2 &m) const {
        if (minute == m.minute && score == m.score && my_room == m.my_room && elephant_room == m.elephant_room && me_waiting == elephant_waiting) {
            for (int room : remaining) {
                if (m.remaining.find(room) == m.remaining.end()) {
                    return false;
                }
            }

            return true;
        }
        return false;
    }
};

typedef unordered_map<int, int> DistType;

unordered_map<int, Room> rooms;
unordered_map<int, DistType> distances;
unordered_map<string, int> room_id;

int getRoomID(const string& room) {
    static int idx = 0;
    auto it = room_id.find(room);
    if (it == room_id.end()) {
        room_id[room] = idx;
        idx++;
        return idx - 1;
    } else {
        return it->second;
    }
}

DistType shortestPath(int start_room) {
    DistType dist;
    unordered_set<int> q;

    for (const auto& it : rooms) {
        dist[it.first] = INT_MAX;
        q.insert(it.first);
    }

    dist[start_room] = 0;
    int element;

    while (!q.empty()) {
        int distance = INT_MAX;
        for (const auto& it : q) {
            if (dist[it] < distance) {
                distance = dist[it];
                element = it;
            }
        }

        Room& room = rooms[element];

        for (const auto& next : room.destinations) {
            if (q.find(next) == q.end())
                continue;

            dist[next] = min(dist[next], distance + 1);
        }

        q.erase(element);
    }

    return dist;
}

DistType filter(const DistType& dist) {
    DistType remaining;

    for (const auto& it : dist) {
        if (it.second > 0 && rooms[it.first].flow_rate > 0) {
            remaining[it.first] = it.second;
        }
    }

    return remaining;
}

int findBestP1(int max_minutes) {
    int best = 0;
    list<MoveP1> moves;
    moves.emplace_back(0, 0, getRoomID("AA"));

    while (!moves.empty()) {
        MoveP1 move = moves.front();
        moves.pop_front();

        best = max(best, move.score);

        for (const auto& it : distances[move.room]) {
            if (move.minute + it.second + 1 >= max_minutes)
                continue;

            auto path_it = find(move.path.begin(), move.path.end(), it.first);
            if (path_it != move.path.end())
                continue;

            auto next_move = move;
            next_move.minute += it.second + 1;
            next_move.room = it.first;
            next_move.path.insert(it.first);
            next_move.score += rooms[it.first].flow_rate * (max_minutes - next_move.minute);

            moves.push_back(next_move);
        }
    }

    return best;
}

vector<pair<int, int>> getNextMoves(MoveP2& move, int room) {
    vector<pair<int, int>> next_moves;
    for (const auto& it : distances[room]) {
        if (find(move.remaining.begin(), move.remaining.end(), it.first) == move.remaining.end())
            continue;

        next_moves.emplace_back(it.first, it.second + 1);
    }

    return next_moves;
}

bool canBeBetter(MoveP2& move, int max_minutes, int current_minute, int best_score) {
    int current_score = move.score;

    for (auto room : move.remaining) {
        current_score += rooms[room].flow_rate * (max_minutes - current_minute);
    }

    return current_score > best_score;
}

int findBestP2(int max_minutes) {
    int best = 0;
    list<MoveP2> moves;
    int AA_ID = getRoomID("AA");
    auto m = MoveP2(0, 0, AA_ID, 0, 0);

    for (const auto& it : distances[AA_ID]) {
        m.remaining.insert(it.first);
    }

    moves.emplace_back(m);

    while (!moves.empty()) {
        m = moves.front();
        moves.pop_front();
        best = max(best, m.score);

        if (m.me_waiting == m.minute) {
            for (auto& it : getNextMoves(m, m.my_room)) {
                if (m.minute + it.second >= max_minutes)
                    continue;

                auto move = m;
                move.me_waiting = move.minute + it.second;
                move.minute = min(move.me_waiting, move.elephant_waiting);
                move.my_room = it.first;
                move.remaining.erase(it.first);
                move.score += rooms[it.first].flow_rate * (max_minutes - move.me_waiting);

                if (canBeBetter(move, max_minutes, move.minute, best))
                    moves.push_back(move);
            }

            if (m.elephant_waiting < max_minutes) {
                auto move = m;
                move.me_waiting = max_minutes;
                move.minute = min(move.elephant_waiting, max_minutes);

                if (canBeBetter(move, max_minutes, move.minute, best))
                    moves.push_back(move);
            }
        } else if (m.elephant_waiting == m.minute) {
            for (auto& it : getNextMoves(m, m.elephant_room)) {
                if (m.minute + it.second >= max_minutes)
                    continue;

                auto move = m;
                move.elephant_waiting = move.minute + it.second;
                move.minute = min(move.me_waiting, move.elephant_waiting);
                move.elephant_room = it.first;
                move.remaining.erase(it.first);
                move.score += rooms[it.first].flow_rate * (max_minutes - move.elephant_waiting);

                if (canBeBetter(move, max_minutes, move.minute, best))
                    moves.push_back(move);
            }

            if (m.me_waiting < max_minutes) {
                auto move = m;
                move.elephant_waiting = max_minutes;
                move.minute = min(move.me_waiting, max_minutes);

                if (canBeBetter(move, max_minutes, move.minute, best))
                    moves.push_back(move);
            }
        }
    }

    return best;
}

string Day16Solver::executePuzzle1() {
    rooms.clear();
    distances.clear();
    for (const auto &line: input) {
        vector<string> split = Utils::splitToString(line);
        int id = getRoomID(split[1]);
        rooms[id].flow_rate = Converter::StringToInt(split[4].substr(5));
        for (int j = 9; j < split.size(); j++) {
            string neighbor = split[j].substr(0, 2);
            rooms[id].destinations.push_back(getRoomID(neighbor));
        }
    }

    int AA_ID = getRoomID("AA");
    distances[AA_ID] = filter(shortestPath(AA_ID));
    for (const auto& room : rooms) {
        if (room.second.flow_rate > 0) {
            distances[room.first] = filter(shortestPath(room.first));
        }
    }

    int best = findBestP1(30);
    return to_string(best);
}

string Day16Solver::executePuzzle2() {
    int best = findBestP2(26);
    return to_string(best);
}