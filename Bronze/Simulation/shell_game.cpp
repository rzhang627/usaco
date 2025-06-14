// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define max(a,b) (a > b ? a : b)

int main() {
    // simulate the process for different base positions of the shell
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int iters;
    cin >> iters;

    int shells1[3] = {1, 0, 0};
    int shells2[3] = {0, 1, 0};
    int shells3[3] = {0, 0, 1};
    int j = 0, correct1 = 0, correct2=0, correct3=0;
    int first, second, third;
    while (j < iters) {
        cin >> first >> second >> third;
        // cout << shells1[0] << shells1[1] << shells1[2] << endl;
        // cout << first << second << third << endl;
        first--; second--; third--;
        // swap the positions of first and second
        int temp = shells1[first];
        shells1[first] = shells1[second];
        shells1[second] = temp;
        if (shells1[third] == 1)
            correct1++;

        temp = shells2[first];
        shells2[first] = shells2[second];
        shells2[second] = temp;
        if (shells2[third] == 1)
            correct2++;

        temp = shells3[first];
        shells3[first] = shells3[second];
        shells3[second] = temp;
        if (shells3[third] == 1)
            correct3++;
        j++;
    }
    cout << max(max(correct1,correct2),correct3) << endl;
	// int a, b, c; cin >> a >> b >> c;
	// cout << "The sum of these three numbers is " << a + b + c << "\n";
}
