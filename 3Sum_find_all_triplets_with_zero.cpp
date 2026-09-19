#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> check(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> ans;

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {

                if(a[i] + a[j] + a[k] == 0) {
                    ans.push_back({i, j, k});
                }
            }
        }
    }

    return ans;
}

vector<vector<int>> check2(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> ans;

    for(int i = 0; i < n - 2; i++) {
        unordered_map<int, int> m;

        for(int j = i + 1; j < n - 1; j++) {
            int need = - (a[i] + a[j]);

            if(m.find(need) != m.end()) {
                ans.push_back({i, m[need], j});
            }

            m[a[j]] = j;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    vector<vector<int>> ans = check(a);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }

    return 0;
}