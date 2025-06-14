// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	// want to find the number of consistent pairs, meaning the rankings
    // are consistent through all k sessions
    // go through all pairs and find the most
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n; cin >> k >> n;

    // traverse in 2D array until you find the first element in the pair
    vector<vector<int>> vals(k, vector<int>(n));
    int a;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vals[i][j];
        }
    }

    int first = 0;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (a = 0; a < k; a++) {
                for (int b = 0; b < n; b++) {
                    if (first < 0) {
                        break;
                    }
                    if (vals[a][b] == i || vals[a][b] == j) {
                        if (first == 0)
                            first = vals[a][b];
                        else if (first > 0 && vals[a][b] != first) {
                            first = -1;
                        }
                        break;
                    }
                }
            }
            if (first > 0) {
                count++;
            }
            first = 0;
        }
    }
    cout << count;
}