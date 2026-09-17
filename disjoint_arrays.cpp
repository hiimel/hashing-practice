#include<bits/stdc++.h>
using namespace std;

bool check1(const vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j]) {
                return false;
            }
        }
    }

    return true;
}

bool check2(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] == b[j]) {
            return false;
        }

        if(a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    return true;
}

bool check3(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> hashset(a.begin(), a.end());

    for(int x: b) {
        auto it = hashset.find(x);

        if(it != hashset.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    if(check3(a, b)) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }

    return 0;
}