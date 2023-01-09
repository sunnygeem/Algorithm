// 동전1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int ans[10001]; // ans[k] = k원 만들 수 있는 경우의 수

int main(){
    cin >> n >> k;

    
    vector<int> coin(n);
    vector<int> ans(k+1); // 0 ~ k까지 => k+1
    
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    // *** 아무 동전도 선택하지 않는 경우도 하나의 경우의 수 ***
    ans[0] = 1;
    for(int i=0; i<n; i++){
        // 각 동전에 대해 그것을 제외하면 k를 만들 수 있는 경우의 수의 형태는 -coin[i]와 동일
        for(int j=coin[i]; j<=k; j++){
            ans[j] += ans[j - coin[i]];
        }

    }

    cout << ans[k]<< "\n";
    

    return 0;
}