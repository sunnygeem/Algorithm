// 평범한 배낭

#include <iostream>
#include <algorithm>

using namespace std;

int n, k, w, v;
int dp[101][100001]; // dp[1~n번째 물품까지][제한 무게 k]
int weight[101]; // 무게
int val[101]; // 가치

void cal(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j - weight[i] >= 0){ // i번째 물품을 넣을 수 있는 경우
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + val[i]);
            }
            else{ // i번째 물품을 넣기에 용량이 부족한 경우 => i-1번째 값으로 설정
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin >> weight[i] >> val[i];
    }

    cal();

    cout << dp[n][k] << "\n";

    return 0;
}