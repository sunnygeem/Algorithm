// 링크와 스타트

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int s[20][20];
int v[20] = {0, }; //팀에 배정되면 그 값이 1로 바뀜
int ans = 1e9;

int calS(){
    int a=0, b=0;
    //a는 0팀, b는 1팀

    //i번 사람과 j번 사람이 같은 팀에 속했을 때, 능력치를 더함
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(v[i] == 0 && v[j] == 0){
                a += s[i][j] + s[j][i];
            }
            else if(v[i] == 1 && v[j] == 1){
                b += s[i][j] + s[j][i];
            }
        }
    }

    return abs(a-b);
}

int dfs(int cnt){
    if(cnt == n){ //탈출 조건: 모두 한 팀에 배정된 경우
        return ans;
    }

    v[cnt] = 1;
    dfs(cnt+1);
    v[cnt] = 0;
    dfs(cnt+1);
    
    ans = min(ans, calS());
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>s[i][j];
        }
    }

    cout << dfs(0) << "\n";

    return 0;
}