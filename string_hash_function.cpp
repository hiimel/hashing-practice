#include<iostream>
using namespace std;

// simple string hash function

int simpleString(string key, int size) {
    int hash = 0;
    for(char ch: key) {
        hash += ch;
    }

    return hash % size;
}

// Polynomial rolling hash function

int polynomialRolling(string key, int size) {
    int hash = 0;
    int prime = 31;

    for(int i = 0; i < key.length(); i++) {
        hash = (hash * prime + (int)key[i]) % size;
    }

    return hash;
}

//DJB2 hash function
int djb2(string key, int size) {
    unsigned long hash = 5381;
    for(char ch: key) {
        hash = ((hash << 5) + hash) + ch;
    }

    return hash % size;
}

int main() {
    string key = "hello";
    int size = 10;
    
    cout << "Simple: " << simpleString(key, size) << endl;
    cout << "Polynomial: " << polynomialRolling(key, size) << endl;
    cout << "DJB2: " << djb2(key, size) << endl;
    
    return 0;
}