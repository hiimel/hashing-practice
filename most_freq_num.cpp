#include<bits/stdc++.h>
using namespace std;

int check1(vector<int>& a) {
    int maxCnt = 0;
    int ans = a[0];

    for(int i = 0; i < a.size(); i++) {
        int cnt = 0;

        for(int j = 0; j < a.size(); j++) {
            if(a[i] == a[j]) {
                cnt++;
            }
        }

        if(cnt > maxCnt) {
            maxCnt = cnt;
            ans = a[i];
        }
    }

    return ans;
}

int check2(vector<int>& a) {
    unordered_map<int, int> f;
    for(int i = 0; i < a.size(); i++) {
        f[a[i]]++;
    }

    int maxCnt = 0, ans = -1;
    for(auto p: f) {
        int key = p.first, cnt = p.second;

        if(cnt > maxCnt) {
            ans = key;
            maxCnt = cnt;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << check1(a) << endl;

    return 0;
}