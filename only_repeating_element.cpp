#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& a) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = i + 1; j < a.size(); j++) {
            if(a[i] == a[j]) {
                return a[i];
            }
        }
    }

    return -1;
}

int check2(vector<int>& a) {
    int n = a.size();

    int sum = accumulate(a.begin(), a.end(), 0);

    int duplicate = sum - ((n - 1) * n / 2);

    return duplicate;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    cout << check2(a) << endl;

    return 0;
}