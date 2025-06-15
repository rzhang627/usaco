// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

	int n, m; cin >> n >> m;
    // a position could explain spottiness if and only if none of the plain cows have the char in spotty cows
    // if it does, you can move to the next position immediately
    // iterate through the chars at any position in genome and check if any are found in the plain cows
    // O(M * N^2)
    vector<vector<char>> spotty(m, vector<char>(n));
    vector<vector<char>> plain(m, vector<char>(n));
    char a;
    string b;

    for (int i = 0; i < n; i++) {
        cin >> b;
        for (int j = 0; j < m; j++) {
            a = b[j];
            spotty[j][i] = a;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> b;
        for (int j = 0; j < m; j++) {
            a = b[j];
            plain[j][i] = a;
        }
    }

    // mistake was using j to index instead of k
    bool contained = false;
    int loc = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a = spotty[i][j];
            // if (i == 7)
            //     cout << a << endl;
            for (int k = 0; k < n; k++) {
                // cout << plain[i][k];
                if (plain[i][k] == a) {
                    contained = true;
                    // cout << plain[i][j] << endl;
                    break;
                }
            }
            if (contained) {
                break;
            }
        }
        // cout << !contained << endl;
        loc += !contained;
        contained = false;
    }
    cout << loc << endl;
}
