// N과 M(3)

#include <iostream>

using namespace std;

int n, m;
int arr[8];
bool visit[8] = {false, };


void dfs(int len){

    if(len == m){

        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout<<"\n";

        return;
    }

    for(int i = 1; i<=n; i++){
        //if(visit[i] == false){
        //if문을 사용하게 되면 자기 자신은 포함할 수 없음
        visit[i] = true;
        arr[len] = i;
        dfs(len+1);
        visit[i] = false;
        //}
    }

}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>m;

    dfs(0);

    return 0;
}