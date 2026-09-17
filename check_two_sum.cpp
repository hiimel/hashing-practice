#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, int t) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = i + 1; j < a.size(); j++) {
            if(a[i] + a[j] == t) {
                return true;
            }
        }
    }

    return false;
}

bool check2(vector<int>& a, int t) {
    unordered_set<int> s;

    for(int i = 0; i < a.size(); i++) {
        int c = t - a[i];

        if(s.find(c) != s.end()) {
            return true;
        }

        s.insert(a[i]);
    }

    return false;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(check(a, target)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}