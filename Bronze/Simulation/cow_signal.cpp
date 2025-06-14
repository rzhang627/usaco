// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
	int m, n, k; cin >> m >> n >> k;

    // we want to read the next M lines, each with a length N string
    for (int i = 0; i < m; i++) {
        vector<char> str;
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            str.push_back(c);
        }
        // after building the string, we want to print k lines each character k times
        for (int j = 0; j < k; j++) {
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < k; q++)
                    cout << str[p];
            }
            cout << endl;
        }
    }
}
