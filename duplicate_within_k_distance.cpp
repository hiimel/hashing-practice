#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, int k) {
    unordered_map<int, int> m;

    for(int i = 0; i < a.size(); i++) {

        if(m.find(a[i]) != m.end()) {

            if(i - m[a[i]] <= k) {
                
                return true;
            }
        }

        m[a[i]] = i;
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(check(a, k)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}