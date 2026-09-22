#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& a, int n) {
    sort(a.begin(), a.end());

    int cnt = 1;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            continue;
        }

        if(a[i] + 1 != a[i + 1]) {
            cnt++;
        }
    }

    return cnt;
}

int check2(vector<int>& a, int n) {
    unordered_set<int> hashset(a.begin(), a.end());

    int cnt = 0;
    for(int x: a) {
        if(hashset.find(x - 1) == hashset.end()) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    cout << check2(a, n) << endl;

    return 0;
}