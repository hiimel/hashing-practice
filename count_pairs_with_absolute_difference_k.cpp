#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& a, int d) {
    int cntPairs = 0;

    for(int i = 0; i < a.size(); i++) {
        for(int j = i + 1; j < a.size(); j++) {
            if(abs(a[i] - a[j]) == d) {
                cntPairs++;
            }
        }
    }

    return cntPairs;
}

int check2(vector<int>& a, int d) {
    unordered_map<int, int> m;
    int cnt = 0;

    for(int i = 0; i < a.size(); i++) {
        int c1 = a[i] + d;
        if(m.find(c1) != m.end()) {
            cnt += m[c1];
        }

        int c2 = a[i] - d;
        if(m.find(c2) != m.end()) {
            cnt += m[c2];
        }

        m[a[i]]++;
    }

    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    cout << check2(a, k) << endl;

    return 0;
}