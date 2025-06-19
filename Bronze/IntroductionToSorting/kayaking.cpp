// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

int main() {
	int n; cin >> n;

    int min = INT32_MAX;
    // one simple solution is to check all pairs after sorting and adding alternating difference
    vector<int> weights(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    vector<int> vals(2 * n - 2);

    // to compute instability, alternate sum and difference and take absolute value of result
    // we have that k == i: 
    int instability = 0;
    int offset = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            // construct vals;
            for (int k = 0; k < 2 * n; k++) {
                if (k == i) {
                    offset += 1;
                    continue;
                }
                if (k == j) {
                    offset++;
                    continue;
                }
                vals[k - offset] = weights[k];
            }
            offset = 0;

            for (int k = 0; k < 2 * n - 3; k += 2) {
                instability += vals[k + 1] - vals[k];
            }
            if (instability < min) {
                min = instability;
            }
            instability = 0;
        }
    }
    cout << min << endl;
}
