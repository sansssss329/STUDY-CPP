// https://www.luogu.com.cn/problem/P2327 扫雷
#include<iostream>
using namespace std;
const int N = 1e4 + 10;

int a[N], b[N];

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n + 1; i++) cin >> b[i];
    int sum = 0;
    while(a[1] < 2){
        bool flag = 1;
        for(int i = 2; i <= n; i++){
            a[i] = b[i - 1] - a[i - 1] - a[i - 2];
            if(a[i] < 0 || a[i] > 1 || a[n + 1] != 0) {
                flag = 0;
                break;
            }
        }
        if(flag) sum++;
        a[1]++;
    }
    cout << sum << endl;
    return 0;
}