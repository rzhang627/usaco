// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
	int c1, m1, c2, m2, c3, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    int min;
	for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            min = std::min(m1, c2 - m2);
            m1 -= min;
            m2 += min;
        } else if (i % 3 == 1) {
            min = std::min(m2, c3 - m3);
            m2 -= min;
            m3 += min;
        } else {
            min = std::min(m3, c1 - m1);
            m3 -= min;
            m1 += min;
        }   
    }
    cout << m1 << endl << m2 << endl << m3 << endl;
}
