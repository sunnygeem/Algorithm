// 트리의 부모 찾기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>>abj(1000001); // 간선
vector<bool> visit(1000001, false);
int res[1000001];

void DFS(int current){
    // if(val == current){
    //     res = past;
    //     return;
    // }
    // visit[current]=true;
    
    // for(int i=0; i<int(abj[current].size()); i++){
    //     int next = abj[current][i];
    //     if(visit[next]) continue;
    //     DFS(next, current, val);
    // }

    visit[current] = true;
    for(int i=0; i<int(abj[current].size()); i++){
        int next = abj[current][i];
        if(visit[next]) continue;
        res[next] = current;
        DFS(next);
    }

}

int main(){
    int n; cin>>n;
    for(int i=1; i<n; i++){
        int a,b; cin>>a>>b;
        abj[a].push_back(b);
        abj[b].push_back(a);
    }

    DFS(1);

    for(int i=2; i<=n; i++){
        // for(int i=0; i<visit.size(); i++){
        //     visit[i]=false;
        // }

        cout<<res[i]<<"\n";
    }

    return 0;
}