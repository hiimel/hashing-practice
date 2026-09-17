#include<bits/stdc++.h>
using namespace std;

vector<int>check(vector<int>& a, vector<int>& b) {
    unordered_set<int> hashset;

    for(int i = 0; i < a.size(); i++) {
        hashset.insert(a[i]);
    }

    for(int i = 0; i < b.size(); i++) {
        hashset.insert(b[i]);
    }

    vector<int> ans;
    for(auto it: hashset) {
        ans.push_back(it);
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> el = check(a, b);
    for(auto it: el) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}