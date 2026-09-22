#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& a, int k) {
    int n = a.size();
    int res = 0;

    for(int i = 0; i < n; i++) {
        int cnt = 0;

        for(int j = i; j < n; j++) {
            if(a[i] > k) {
                cnt++;
            } else {
                cnt--;
            }

            if(cnt > 0) {
                res = max(res, j - i + 1);
            }
        }
    }

    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    cout << check(a, k) << endl;

    return 0;
}