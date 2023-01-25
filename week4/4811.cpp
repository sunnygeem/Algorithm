// 알약

#include <iostream>

using namespace std;

int n;
long long dp[31][31] = {0, };

long long sol(int w, int h){
    if(w == 0){
        return 1;
    }

    // 값이 이미 구해진 경우
    // 이 조건문을 먼저 실행하지 않으면, 아래 두 과정이 여러 번 반복되는 경우 발생
    if(dp[w][h] > 0){
        return dp[w][h];
    }

    if(w > 0){
        dp[w][h] += sol(w-1, h+1);
    }

    if(h > 0){
        dp[w][h] += sol(w, h-1);
    }

    return dp[w][h];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);



    while(1){
        cin >> n;
        if(n == 0){
            return 0;
        }

        cout << sol(n, 0) << "\n";
    }

    return 0;
}