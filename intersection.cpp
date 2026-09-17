#include<bits/stdc++.h>
using namespace std;

vector<int> check2(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    unordered_map<int, int> seen;

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j] && seen.count(a[i]) == 0) {
                seen.insert({a[i], 1});
                ans.push_back(a[i]);
            }
        }
    }

    return ans;
}

vector<int> check1(vector<int>& a, vector<int>& b) {
    unordered_set<int> hashset(a.begin(), a.end());

    unordered_set<int> res;
    vector<int> ans;

    for(int i = 0; i < b.size(); i++) {
        if((hashset.find(b[i]) != hashset.end()) && res.find(b[i]) == res.end()) {
            res.insert(b[i]);
            ans.push_back(b[i]);
        }
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

    vector<int> el = check2(a, b);
    for(int x: el) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}