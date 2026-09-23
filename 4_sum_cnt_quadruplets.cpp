#include<bits/stdc++.h>
using namespace std;

#define ll long long

int check(vector<int>& a, int n, int t) {
    int cnt = 0;

    for(int i = 0; i < n - 3; i++) {
        for(int j = i + 1; j < n - 2; j++) {
            for(int k = j + 1; k < n - 1; k++) {
                for(int h = k + 1; h < n; h++) {
                    if(a[i] + a[j] + a[k] + a[h] == t) {
                        cnt++;
                    }
                }
            }
        }
    }

    return cnt;
}

int check2(vector<int>& a, int n, int target) {
    ll cnt = 0;
    unordered_map<ll, ll> m;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int need = target - a[i] - a[j];

            if(m.find(need) != m.end()) {
                cnt += m[need];
            }
        }

        for(int k = 0; k < i; k++) {
            int ps = a[i] + a[k];
            m[ps]++;
        }
    }

    return cnt;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    cout << check2(a, n, target) << endl;

    return 0;
}