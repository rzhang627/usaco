// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
	int n; cin >> n;
    string a, b;
    int counts[26] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int charsA[26] = {0};
        int charsB[26] = {0};
        // cout << a << b << endl;
        for (int j = 0; j < a.length(); j++) {
            char c = a[j];
            // cout << c - 'a';
            charsA[c - 'a']++;
        }
        for (int j = 0; j < b.length(); j++) {
            char c = b[j];
            charsB[c - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            counts[j] += std::max(charsA[j], charsB[j]);
        }
    }
    for (int i = 0; i < 26; i++) {
	    cout << counts[i] << endl;
    }
}
