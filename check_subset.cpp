#include<bits/stdc++.h>
using namespace std;

bool check1(const vector<int>& a, vector<int>& b) {
    for(int i = 0; i < a.size(); i++) {
        bool found = false;

        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j]) {
                found = true;
                b.erase(b.begin() + j);
                break;
            }
        }

        if(!found) {
            return false;
        }
    }

    return true;

}

bool check2(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j= 0;
    int n = a.size(), m = b.size();

    while(i < n && j < m) {
        if(a[i] == b[j]) {
            i++; j++;
        } else if(a[i] > b[j]) {
            j++;
        } else {
            return false;
        }
    }

    return i == n;
}

bool check3(const vector<int>& a, const vector<int>& b) {
    multiset<int> hashset(b.begin(), b.end());

    for(int n: a) {
        auto it = hashset.find(n);

        if(it == hashset.end()) {
            return false;
        }

        hashset.erase(it);
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

    if(check2(a, b)) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }

    return 0;
}