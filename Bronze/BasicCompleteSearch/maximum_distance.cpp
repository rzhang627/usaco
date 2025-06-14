// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b; cin >> n;
    vector<int> x;
    vector<int> y;
	for (int i = 0; i < n; i++) {
        cin >> a;
        x.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> b;
        y.push_back(b);
    }
    int max = 0, dist;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // cout << "here" << endl;
            dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dist > max){
                max = dist;
            }
        }
    }
    cout << max << endl;
}
