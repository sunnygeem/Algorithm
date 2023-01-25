// 2xn 타일링

#include <iostream>

using namespace std;

int n;
int d[1001];

int dp(int *d, int n) {
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) d[i] = (d[i-1] + d[i-2]) % 10007;
    // https://www.acmicpc.net/board/view/20220 : 미리 나눈 값을 저장하는 이유

    return d[n];
}

int main() {

    cin>>n;

    cout << dp(d, n) << "\n";

    return 0;
}