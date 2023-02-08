// 아기 상어

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

int abj[20][20]; // 간선
bool visit[20][20]; 

int n;

int dx[] = {0,0,-1,1}; // 상하좌우
int dy[] = {-1,1,0,0};
int cx, cy; // 물고기를 먹었을 때 상어의 위치

int t=0, cnt=0; // 총 시간, 먹은 물고기 수
int s = 2; // 상어의 크기

bool call = false; // 먹을 물고기가 없어서 엄마 상어를 불러야 하는 경우 true
bool eat = false;

using namespace std;

void BFS(int a, int b, int s){ // 위치, 크기가 parameter
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(a, b), 0));
    visit[b][a] = true;

    int ot; // 한 마리 먹는 데까지 걸린 시간
    while(!q.empty()){
        // 위치 설정
        int tx = ;
        int ty = ;
    }
}

int main(){
    
    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>abj[i][j];

            if(abj[i][j] == 9){
                cx = j;
                cy = i;
                abj[i][j] = 0;
            }
        }
    }

    while(call == false){
        memset(visit, false, 20*sizeof(bool));

        BFS(cx, cy, s);
        
        if(eat == true){
            eat = false;
            cnt++;
            abj[cy][cx] = 0; // 먹은 물고기 정보 초기화

            if(cnt == s){ // 조건: 자신과 크기가 같은 물고기를 먹으면 크기 증가
                s++;
                cnt = 0;
            }
        }
        else{
            call = true;
        }
    }

    cout<<t<<"\n";
    
    return 0;

}