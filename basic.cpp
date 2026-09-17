#include<iostream>
using namespace std;

int main() {
    int data[10];
    
    int key = 26;
    int idx = key % 10;

    data[idx] = 100;

    cout << "Key: " << key << endl;
    cout << "Index: " << idx << endl;
    cout << "Vaue: " << data[idx] << endl;

    return 0;
}