// 바이러스

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>>abj(100000);
vector<bool> visit(1001, false);

int cnt = -1;
// -1부터 시작하는 이유: DFS 함수 내에서 1도 cnt에 포함되기 때문

void DFS(int current){
    visit[current]=true;
    cnt++;
    for(int i=0; i<int(abj[current].size()); i++){
        int next = abj[current][i];
        if(visit[next]) continue;
        DFS(next);
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        abj[a].push_back(b);
        abj[b].push_back(a);
    }

    for(int i=1; i<= 1000; i++){ // 0번 노드는 없으니 1번부터 실행. 
        sort(abj[i].begin(), abj[i].end());
    }

    DFS(1);

    cout<<cnt<<"\n";

    return 0;
}