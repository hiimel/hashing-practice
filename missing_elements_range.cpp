#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& a) {
    int minEl = INT_MAX, maxEl = INT_MIN;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] > maxEl) {
            maxEl = a[i];
        } 

        if(a[i] < minEl) {
            minEl = a[i];
        }
    }

    int cnt = 0;
    unordered_set<int> s(a.begin(), a.end());
    for(int i = minEl; i <= maxEl; i++) {
        if(s.find(i) == s.end()) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int  n;
    cin >> n;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    cout << check(a) << endl;

    return 0;
}