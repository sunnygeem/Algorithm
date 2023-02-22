#include <iostream>
#include <algorithm>

using namespace std;

int n, k, w, v;
int dp[100001]; // dp[무게 한계치]
int weight[101]; // 무게
int val[101]; // 가치

void cal(){
    for(int i=1; i<=n; i++){
        for(int j=k; j>=1; j--){
            if(weight[i] <= j){ // i번째 물품을 넣을 수 있는 경우
                dp[j] = max(dp[j], dp[j-weight[i]] + val[i]);
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

    cout << dp[k] << "\n";

    return 0;
}