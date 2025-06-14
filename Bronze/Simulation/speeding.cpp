// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
	int n, m; cin >> n >> m;
    int over = 0;
    // track the cumulative?? miles at each point and add determine if they are faster than 
    vector<int> distances;
    vector<int> limits;
    int d, l;
	for (int i = 0; i < n; i++) {
        cin >> d >> l;
        distances.push_back(d);
        limits.push_back(l);
    }
    // move through the segments Bessie travels
    int left = distances[0];
    unsigned long idx = 0;
    // cout << limits[0] << endl;
    for (int i = 0; i < m; i++) {
        cin >> d >> l;
        // cout << "d: " << d << endl;
        // now we move through the distances array and compare speed limits, tracking how much is remaining
        // and making sure to reset the distance remaining once we finish using the available distance
        while (d > 0) {
            if (d <= left) {
                left -= d;
                // cout << "d: " << d << endl;
                // cout << left << endl;
                over = std::max(l - limits[idx], over);
                if (left == 0) {
                    idx++;
                    if (idx > n) {
                        break;
                    }
                    left = distances[idx];
                }
                break;
            } else {
                // need to check the max speeding again
                // then change distance remaining
                // update the value of your idx
                // 
                over = std::max(l - limits[idx], over);
                // cout << "over: " << over << endl;
                d -= left;
                idx++;
                if (idx > n) {
                    break;
                }
                // cout << "idx: " << idx << endl;
                left = distances[idx];
            }
        }
    }
    cout << over;
}

// what are all of the ways to choose the vowels