#include<bits/stdc++.h>
using namespace std;

void check(vector<int>& a, int n, int sum) {
    for(int i = 0; i < n; i++) {
        int s = 0;

        for(int j = i; j < n; j++) {
            s += a[j];

            if(s == sum) {
                cout << i << " " << j << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

void check2(vector<int>& a, int n, int sum) {
    unordered_map<int, int> m;

    int s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];

        if(s == sum) {
            cout << 0 << " " << i << endl;
            return;
        }

        int need = s - sum;
        if(m.find(need) != m.end()) {
            cout << m[need] + 1 << " " << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    int n, sum;
    cin >> n >> sum;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    check2(a, n, sum);

    return 0;
}