#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int a[N] , b[N], c[N];
int  la, lb, lc;

int main() {
    string x, y;
    cin >> x >> y;
    la = x.size(); lb = y.size(); lc = max(la, lb);
	for (int i = la - 1; i >= 0; i--) a[la - 1 - i] = x[i] - '0';
	for (int i = lb - 1; i >= 0; i--) b[lb - 1 - i] = y[i] - '0';
    for(int i = 0; i < lc; i++) {
        c[i] += a[i] + b [i];
        c[i + 1] = c[i] / 10;
        c[i] %= 10;
    }
    if(c[lc]) lc++;
    for(int i = lc - 1; i >= 0; i--) cout << c[i];
    return 0;
}