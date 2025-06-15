// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    // two cows cross whenever the pos of entry and exit follow same relative ordering
    // and one of the pos has to be between two of the other
    // a1 < b1 < a2 < b2 or b1 < a1 < b2 < a2

	char a;
    string b;
    cin >> b;
    vector<vector<int>> pos(26, vector<int>(2, -1));
    int cross = 0;
    int loc = 0;
    int j = 0;

    // need to build the position table too
    for (int i = 0; i < 52; i++) {
        a = b[i];
        loc = a - 'A';
        while (pos[loc][j] != -1) {
            j++;
        }
        pos[loc][j] = i;
        j = 0;
    }

    // now need to find the number of positions that have crossing
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (pos[i][0] < pos[j][0]) {
                if (pos[j][0] < pos[i][1] && pos[i][1] < pos[j][1])
                    cross++;
            } else {
                if (pos[i][0] < pos[j][1] && pos[j][1] < pos[i][1])
                    cross++;
            }
        }
    }
	cout << cross << endl;
}
