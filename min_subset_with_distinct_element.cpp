#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& a) {
    int maxCnt = 0, temp = a[0];

    for(int i = 0; i < a.size(); i++) {
        int cnt = 0;

        for(int j = 0; j < a.size(); j++) {
            if(a[i] == a[j]) {
                cnt++;
            }
        }

        if(cnt > maxCnt) {
            maxCnt = cnt;
            temp = a[i];
        }
    }

    return maxCnt;
}

int check2(vector<int>& a) {
    unordered_map<int, int> f;
    for(int i = 0; i < a.size(); i++) {
        f[a[i]]++;
    }

    int maxCnt = 0, res = -1;
    for(auto p: f) {
        if(p.second > maxCnt) {
            res = p.first;
            maxCnt = p.second;
        }
    }

    return maxCnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    cout << check2(a) << endl;

    return 0;
}