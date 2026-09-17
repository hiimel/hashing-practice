#include<bits/stdc++.h>
using namespace std;

bool check1(vector<int>& a, vector<int>& b) {
    if(a.size() != b.size()) {
        return false;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

bool check2(vector<int>& a, vector<int>& b) {
    if(a.size() != b.size()) {
        return false;
    }

    unordered_map<int, int> el;
    for(int i = 0; i < a.size(); i++) {
        el[a[i]]++;
    }

    for(int i = 0; i < a.size(); i++) {
        if(el.find(b[i]) == el.end()) {
            return false;
        }

        if(el[b[i]] == 0) {
            return false;
        }

        el[b[i]]--;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    if(check2(a, b)) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }

    return 0;
}