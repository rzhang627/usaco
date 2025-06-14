// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
	int x, y; cin >> x >> y;
    int dist = 0, dir = 1, scale = 1, pos = x;
    // go in the correct direction till you need to turn, checking if you reach goal pos at any point
    // multiply direction by -1, change the scale
    // cout << pos;
    while (pos != y) {
        while (pos != x + scale * dir) {
            pos += dir;
            dist += 1;
            if (pos == y) {
                break;
            }
        }
        dir *= -1;
        scale *= 2;
    }
	cout << dist;
}
