#include<bits/stdc++.h>
using namespace std;

vector<int> check(vector<int>& a, int l, int h) {
    vector<int> ans;

    for(int i = l; i <= h; i++) {

        bool found = false;
        for(int n: a) {
            if(n == i) {
                found = true;
                break;
            }
        }

        if(!found) {
            ans.push_back(i);
        }
    }

    return ans;
}

vector<int> check2(vector<int>& a, int l, int h) {
    unordered_set<int> s;

    for(auto x: a) {
        s.insert(x);
    }

    vector<int> ans;
    for(int i = l; i <= h; i++) {
        if(s.find(i) == s.end()) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    int n, low, high;
    cin >> n >> low >> high;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    vector<int> nums = check2(a, low, high);
    for(auto x: nums) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}