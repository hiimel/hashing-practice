#include<bits/stdc++.h>
using namespace std;

int check1(vector<int>& a) {
    int ans = 0;
    for(int i = 0; i < a.size() - 1; i++) {
        for(int j = i + 1; j < a.size(); j++) {
            if(a[i] == a[j]) {
                ans = max(ans, j - i);
            }
        }
    }

    return ans;
}

int check2(vector<int>& a) {
    unordered_map<int, int> m;
    int res = 0;

    for(int i = 0; i < a.size(); i++) {
        if(m.find(a[i]) == m.end()) {
            m[a[i]] = i;
        } else {
            res = max(res, i - m[a[i]]);
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << check2(a) << endl;

    return 0;
}