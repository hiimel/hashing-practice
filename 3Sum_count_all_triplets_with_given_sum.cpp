#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& a, int target) {
    int n = a.size();
    int cnt = 0;

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {

                if(a[i] + a[j] + a[k] == target) {
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int check2(vector<int>& a, int target) {
    int n= a.size();
    int cnt = 0;

    for(int i = 0; i < n - 2; i++) {
        unordered_map<int, int> m;
    
        for(int j = i + 1; j < n; j++) {
            int need = target - a[i] - a[j];

            if(m.find(need) != m.end()) {
                cnt += m[need];
            }

            m[a[j]]++;
        }
    }

    return cnt;
}

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    cout << check2(a, t) << endl;

    return 0;
}