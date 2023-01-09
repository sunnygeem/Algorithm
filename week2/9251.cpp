// LCS

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a, b;
int ans[1001][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    // 문자가 같을 때는, +1은 대각선으로부터
    // 문자가 다를 경우에는, 왼쪽이나 위의 값 중 큰 것 선택
    for(int i=0; i < a.length(); i++){
        for(int j=0; j<b.length(); j++){
            if(a[i] == b[j]){
                ans[i+1][j+1] = ans[i][j] + 1;
            }
            else{
                ans[i+1][j+1] = max(ans[i][j+1], ans[i+1][j]);
            }
        }
    }

    cout << ans[a.length()][b.length()] << "\n";

    return 0;
}