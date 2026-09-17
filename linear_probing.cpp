#include <iostream>
using namespace std;

const int SIZE = 10;

enum State {
    EMPTY,
    OCCUPIED,
    DELETED
};

int table[SIZE];
State state[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insertKey(int key) {
    int idx = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (idx + i) % SIZE;

        if(state[pos] == OCCUPIED && table[pos] == key) {
            cout << key << " is already exists!" << endl;
            return;
        }

        if (state[pos] == EMPTY || state[pos] == DELETED) {
            table[pos] = key;
            state[pos] = OCCUPIED;

            cout << key << " inserted at index " << pos << endl;
            return;
        }
    }

    cout << "Hash Table is full" << endl;
}

bool searchKey(int key) {
    int idx = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (idx + i) % SIZE;

        if (state[pos] == EMPTY) {
            return false;
        }

        if (state[pos] == OCCUPIED && table[pos] == key) {
            return true;
        }
    }

    return false;
}

void deleteKey(int key) {
    int idx = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (idx + i) % SIZE;

        if (state[pos] == EMPTY) {
            cout << key << " not found!" << endl;
            return;
        }

        if (state[pos] == OCCUPIED && table[pos] == key) {
            state[pos] = DELETED;

            cout << key << " deleted from index " << pos << endl;
            return;
        }
    }

    cout << key << " not found!" << endl;
}

void display() {
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";

        if (state[i] == OCCUPIED) {
            cout << table[i];
        }
        else if (state[i] == DELETED) {
            cout << "Deleted";
        }
        else {
            cout << "Empty";
        }

        cout << endl;
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) { //initialize
        state[i] = EMPTY;
    }

    insertKey(25);
    insertKey(35);
    insertKey(45);
    insertKey(22);

    display();

    cout << "\nSearching 45: ";

    if (searchKey(45)) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    deleteKey(35);

    display();

    cout << "\nSearching 45 after deleting 35: ";

    if (searchKey(45)) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    return 0;
}
