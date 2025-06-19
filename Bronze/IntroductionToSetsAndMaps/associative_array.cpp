// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
	int q; cin >> q;
    long long first = 0, a, b;
    map<long long, long long> m;
	for (int i = 0; i < q; i++) {
        cin >> first;
        if (first == 0) {
            cin >> a >> b;
            m[a] = b;
        } else {
            cin >> a;
            cout << m[a] << endl;
        }
    }
}
