// QUUESYION - https://codeforces.com/problemset/problem/1629/A

#include<iostream>
#include<vector>
using namespace std;

// a: 20, 30, 10
// b: 9, 100, 10
// k: 10
int increasing_range_to_maximum(vector<int> a, vector<int> b, int k){
    int currentRam = k;
    int n = a.size();
    vector<pair<int, int>> p;
    
    for(int i=0; i<n; i++){
        p.push_back({a[i], b[i]});
    }

    sort(p.begin(), p.end(), [](pair<int, int> x, pair<int, int> y){
        return x.first < y.first;
    });

    // a: 10 20 30
    // b: 10 9 100
    // k: 10
    // 10 + 10 + 9 + 0 ---

    for(int i=0; i<n; i++){
        if(k >= p[i].first){
            k+=p[i].second;
        }
    }

    return k;
}

int main(){
     int t;  // Number of test cases
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        cout << increasing_range_to_maximum(a, b, k) << endl;
    }

    return 0;
}