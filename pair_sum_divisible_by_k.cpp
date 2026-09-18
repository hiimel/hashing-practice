#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, int k) {
    for(int i = 0; i < a.size(); i++) {
        int sum;
        int j = i + 1;
        
        while(j < a.size()) {
            sum = a[i] + a[j];

            if(sum % k == 0) {
                return true;
            }
            
            j++;
        }

    }

    return false;
}

bool check2(vector<int>& a, int k) {
    int n = a.size();

    if(n % 2 != 0){
        return false;
    }

    vector<bool> isUsed(n, false);
    for(int i = 0; i < a.size(); i++) {
        if(isUsed[i]) {
            continue;
        }

        bool fnd = true;
        for(int j = i + 1; j < n; j++) {
            if(!isUsed[j] && (a[i] + a[j] % k == 0)) {
                isUsed[i] = true;
                isUsed[j] = true;
                fnd = true;
                break;
            }
        }

        if(!fnd) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(auto& it: a) {
        cin >> it;
    }

    if(check2(a, k)){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}