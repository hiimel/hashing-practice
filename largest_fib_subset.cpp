#include<bits/stdc++.h>
using namespace std;

vector<int> check(vector<int>& a, int n) {
    int largest = *max_element(a.begin(), a.end());

    int x = 0, y = 1;
    unordered_set<int> st;
    st.insert(x);
    st.insert(y);

    while(y < largest) {
        int c = x + y;
        x = y;
        y = c;
        
        st.insert(y);
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(st.find(a[i]) != st.end()) {
            ans.push_back(a[i]);
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

    vector<int> el = check(a, n);
    for(int x: el) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}