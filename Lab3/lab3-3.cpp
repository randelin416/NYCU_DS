#include <iostream>
#include <sstream>
#include <memory>

using namespace std;

// You need to inherit from this class.
class HashTable {
public:
    virtual void insert(int key, int value) = 0;
    virtual bool search(int key, int &value) = 0;
    virtual bool remove(int key) = 0;
    virtual string str() const = 0;
    virtual ~HashTable() {}
};

// You need to implement this
shared_ptr<HashTable> buildTable(int size);

// You need to implement this
void processCommand(shared_ptr<HashTable> table, string& command);

int main() {
    int T; cin >> T;
    shared_ptr<HashTable> table = buildTable(T);
    string command;
    while (cin >> command) {
        if (command == "e") { cout << table->str(); break; } 
        else processCommand(table, command);
    }
    return 0;
}

// Your code starts here

class LinearProbingHashTable : public HashTable {
private:
    enum State {
        EMPTY,
        OCCUPIED,
        DELETED
    };

    struct Slot {
        int key;
        int value;
        State state;

        Slot() {
            key = 0;
            value = 0;
            state = EMPTY;
        }
    };

    int tableSize;
    Slot* table;

public:
    LinearProbingHashTable(int size) {
        tableSize = size;
        table = new Slot[tableSize];
    }

    ~LinearProbingHashTable() {
        delete[] table;
    }

    void insert(int key, int value) override {
        int start = key % tableSize;
        int firstDeleted = -1;

        for (int i = 0; i < tableSize; i++) {
            int idx = (start + i) % tableSize;

            if (table[idx].state == OCCUPIED) {
                if (table[idx].key == key) {
                    table[idx].value = value;
                    return;
                }
            } 
            else if (table[idx].state == DELETED) {
                if (firstDeleted == -1) {
                    firstDeleted = idx;
                }
            } 
            else if (table[idx].state == EMPTY) {
                if (firstDeleted != -1) {
                    idx = firstDeleted;
                }

                table[idx].key = key;
                table[idx].value = value;
                table[idx].state = OCCUPIED;
                return;
            }
        }

        if (firstDeleted != -1) {
            table[firstDeleted].key = key;
            table[firstDeleted].value = value;
            table[firstDeleted].state = OCCUPIED;
            return;
        }

        cout << "Hash Table is Full! Insert failed." << endl;
    }

    bool search(int key, int &value) override {
        int start = key % tableSize;

        for (int i = 0; i < tableSize; i++) {
            int idx = (start + i) % tableSize;

            if (table[idx].state == EMPTY) {
                return false;
            }

            if (table[idx].state == OCCUPIED && table[idx].key == key) {
                value = table[idx].value;
                return true;
            }
        }

        return false;
    }

    bool remove(int key) override {
        int start = key % tableSize;

        for (int i = 0; i < tableSize; i++) {
            int idx = (start + i) % tableSize;

            if (table[idx].state == EMPTY) {
                return false;
            }

            if (table[idx].state == OCCUPIED && table[idx].key == key) {
                table[idx].state = DELETED;
                return true;
            }
        }

        return false;
    }

    string str() const override {
        stringstream ss;

        for (int i = 0; i < tableSize; i++) {
            ss << "[" << i << "] ";

            if (table[i].state == EMPTY) {
                ss << "[Empty]";
            } 
            else if (table[i].state == DELETED) {
                ss << "[Deleted Slot]";
            } 
            else {
                ss << "Key: " << table[i].key 
                   << ", Value: " << table[i].value 
                   << " [Occupied]";
            }

            ss << "\n";
        }

        return ss.str();
    }
};

shared_ptr<HashTable> buildTable(int size) {
    return make_shared<LinearProbingHashTable>(size);
}

void processCommand(shared_ptr<HashTable> table, string& command) {
    if (command == "i") {
        int key, value;
        cin >> key >> value;
        table->insert(key, value);
    } 
    else if (command == "f") {
        int key;
        cin >> key;

        int value;
        if (table->search(key, value)) {
            cout << "Found: " << value << endl;
        } else {
            cout << "Not Found" << endl;
        }
    } 
    else if (command == "d") {
        int key;
        cin >> key;
        table->remove(key);
    }
}