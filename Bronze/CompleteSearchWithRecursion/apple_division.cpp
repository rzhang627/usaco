// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
    int mask = 1;
    long g1 = 0, g2 = 0;
    long diff = 1000000000;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    // using bitmasks
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (mask << j)) {
                g1 += weights[j];
            } else {
                g2 += weights[j];
            }
        }
        if (std::abs(g2 - g1) < diff) {
            diff = std::abs(g2 - g1);
        }
        g2 = 0;
        g1 = 0;
    }
    cout << diff;
}
