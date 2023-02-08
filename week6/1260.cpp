// DFS와 BFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>>abj(100000); // 간선
vector<bool> visit(1001, false);

void DFS(int current){
    visit[current]=true;
    cout<<current<<' ';
    for(int i=0; i<int(abj[current].size()); i++){
        int next = abj[current][i];
        if(visit[next]) continue;
        DFS(next);
    }
}

void BFS(int start){
    queue<int> q;

    visit[start] = true;
    q.push(start);

    while(!q.empty()){ // q가 비어있지 않으면
        int current = q.front();
        cout << current << ' ';
        q.pop();
        
        for(int i=0; i<int(abj[current].size()); i++){
            int next=abj[current][i];
            if(visit[next]) continue;
            visit[next]=true;
            q.push(next);
        }
    }
}


int main(){
    int n, m, v;
    cin>>n>>m>>v;

    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        abj[a].push_back(b);
        abj[b].push_back(a);
    }

    for(int i=1; i<= 1000; i++){ // 0번 노드는 없으니 1번부터 실행. 
        sort(abj[i].begin(), abj[i].end());
    }

    DFS(v);

    for(int i=0; i<visit.size(); i++){
        visit[i]=false;
    }

    cout<<"\n";

    BFS(v);

    return 0;
}