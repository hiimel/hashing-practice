#include<iostream>
using namespace std;

const int SIZE = 10;
const int PRIME = 7;

enum State {
    EMPTY, OCCUPIED, DELETED
};

int table[SIZE];
State state[SIZE];

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return PRIME - (key % PRIME);
}

void insertKey(int key) {
    int idx = hash1(key);
    int step = hash2(key);

    for(int i = 0; i < SIZE; i++) {
        int pos = (idx + i * step) % SIZE;

        if(state[pos] == OCCUPIED && table[pos] == key) {
            cout << key << " is already exists!" << endl;
            return;
        }

        if(state[pos] == EMPTY || state[pos] == DELETED) {
            table[pos] = key;
            state[pos] = OCCUPIED;

            cout << key << " inserted at index" << pos << endl;

            return;
        }
    }

    cout << "Hash Table is full." << endl;
}

bool SearchingKey(int key) {
    int idx = hash1(key);
    int step = hash2(key);

    for(int i = 0; i < SIZE; i++) {
        int pos = (idx + i * step) % SIZE;

        if(state[pos] == EMPTY) {
            return false;
        }

        if(state[pos] == OCCUPIED && table[pos] == key) {
            return true;
        }
    }

    return false;
}

void deleteKey(int key) {
    int idx = hash1(key);
    int step = hash2(key);

    for(int i = 0; i < SIZE; i++) {
        int pos = (idx + i * step) % SIZE;

        if(state[pos] == EMPTY) {
            cout << "Not found!" << endl;
            return;
        }

        if(state[pos] == OCCUPIED && table[pos] == key) {
            state[pos] = DELETED;

            cout << key << " deleted from index " << pos << endl;

            return;
        }
    }

    cout << "Not found!" << endl;
}

void display() {
    cout << "\nHash Table:\n";

    for(int i = 0; i < SIZE; i++) {
        cout << i << " : ";

        if(state[i] == EMPTY) {
            cout << "EMPTY";
        } else if(state[i] == DELETED) {
            cout << "DELETED";
        } else {
            cout << table[i];
        }

        cout << endl;
    }
}

int main() {
    for(int i = 0; i < SIZE; i++) {
        state[i] = EMPTY;
    }

    insertKey(23);
    insertKey(25);
    insertKey(45);
    insertKey(35);
    insertKey(25);

    display();

    if(SearchingKey(35)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found!" << endl;
    }

    deleteKey(35);

    display();
    
    return 0;
}