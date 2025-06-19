// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int count = 1;
    int prev = arr[0];
    for (int i = 1; i < n; i++) {
        // cout << arr[i] << endl;
        if (arr[i] != prev) {
            count++;
        }
        prev = arr[i];
    }
    cout << count << endl;
}
