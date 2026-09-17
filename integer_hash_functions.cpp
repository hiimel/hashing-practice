#include<iostream>
using namespace std;

int hFDiv(int key, int size) {
    return key % size;
}

int hFMulti(int key, int size) {
    double A = 0.6180339887;
    return (int)(size * ((key * A) - (int)(key * A)));
}

int hFMidSq(int key, int size) {
    long sq = (long) key * key;
    int mid = (int)(sq / 100) % 100;
    return mid % size;
}

int main() {
    int key = 25;
    int size = 10;

    cout << "Division Method: " << hFDiv(key, size) << endl;
    cout << "Multiplication Method: " << hFMulti(key, size) << endl;
    cout << "Mid-Square Method: " << hFMidSq(key, size) << endl;

    return 0;
}