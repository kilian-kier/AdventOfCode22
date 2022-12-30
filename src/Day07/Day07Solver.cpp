#include "../../include/Day07Solver.h"

class Directory {
public:
    string name;
    int size = 0;
    Directory *parent{};
    list<Directory *> children = list<Directory *>(0);

    void addFile(int file_size) {
        size += file_size;

        Directory *p = parent;
        while (p != nullptr) {
            p->size += file_size;
            p = p->parent;
        }
    }

    void addDir(Directory *child) {
        child->parent = this;
        children.push_back(child);
    }

    Directory *findDir(const string &dir_name) {
        for (Directory *d: children) {
            if (d->name == dir_name)
                return d;
        }

        return nullptr;
    }
};

Directory *root;

int getTotalSize(Directory *d, int max_size) {
    if (d == nullptr) {
        return 0;
    }
    int size = 0;
    if (d->size <= max_size) {
        size = d->size;
    }

    for (Directory *child: d->children) {
        size += getTotalSize(child, max_size);
    }

    return size;
}

string Day07Solver::executePuzzle1() {
    root = new Directory;
    root->name = "/";

    Directory *current = root;
    for (string &line: input) {
        if (isdigit(line[0])) {
            current->addFile(Converter::StringToInt(line));
        } else if (line.find("dir") != string::npos) {
            auto *child = new Directory;
            child->name = line.substr(4);
            current->addDir(child);
        } else if (line.find("cd ..") != string::npos) {
            current = current->parent;
        } else if (line.find("cd") != string::npos) {
            Directory *sibling = current->findDir(line.substr(5));
            if (sibling != nullptr) {
                current = sibling;
            }
        }
    }

    return to_string(getTotalSize(root, 100'000));
}

int smallestDirToDelete(Directory *d, int curr_smallest, int needed) {
    if (d == nullptr) {
        return 0;
    }

    int ret = curr_smallest;

    if (d->size >= needed && d->size < curr_smallest) {
        ret = d->size;
    }

    if (d->children.empty())
        return ret;
    for (Directory *child: d->children) {
        ret = min(ret, smallestDirToDelete(child, curr_smallest, needed));
    }

    return ret;
}

string Day07Solver::executePuzzle2() {
    int unused_space = 70000000 - root->size;
    int needed = 30000000 - unused_space;
    int smallest = smallestDirToDelete(root, INT_MAX, needed);
    return to_string(smallest);
}
