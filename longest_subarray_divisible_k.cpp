#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& a, int k) {
    int ans = 0;
    
    for(int i = 0; i < a.size(); i++) {
        int sum = 0;

        for(int j = i; j < a.size(); j++) {
            sum += a[j];

            if(sum % k == 0) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    return ans;
}

int check2(vector<int>& a, int k) {
    int ans = 0, sum = 0;
    unordered_map<int, int> m;

    for(int i = 0; i < a.size(); i++) {
        sum += a[i];

        sum %= k;

        if(sum < 0) {
            sum += k;
        }

        if(sum == 0) {
            ans = i + 1;
        } else if(m.find(sum) != m.end()) {
            ans = max(ans, i - m[sum]);
        } else {
            m[sum] = i;
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    cout << check2(a, k) << endl;

    return 0;
}