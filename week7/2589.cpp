// 보물섬

#include <iostream>
#include <queue>

using namespace std;

int w, h;
char arr[51][51]; // 주어지는 지도
bool visit[51][51]; // 방문처리
int path[51][51]; // 경로(시작점부터 해당 노드까지의 길이)

int dy[] = {-1,1,0,0}; // 상하좌우
int dx[] = {0,0,-1,1};

queue<pair<int, int>> q;

int res = 0; // 최장경로

int BFS(int x, int y){ // 최장경로 return
    // parameter로 받은 x, y에 대한 경로 처리
    visit[y][x] = true;
    q.push(make_pair(x, y));

    // 경로 및 최장경로 탐색
    while(q.empty() != true){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // queue의 원소 하나를 선택하여 상하좌우 이동
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || ny >= h || nx >= w){ // 탐색 불가능한 경우
                continue;
            }
            if(arr[ny][nx] == 'L' && !visit[ny][nx]){ // 방문기록이 없고 육지인 경우 => 방문 가능
                visit[ny][nx] = true;
                path[ny][nx] = path[y][x] + 1;
                q.push(make_pair(nx, ny));

                if(res < path[ny][nx]){
                    res = path[ny][nx];
                }
            }
        }
    }

    return res;
}

void init(){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            visit[i][j] = false;
            path[i][j] = 0;
        }
    }

    res = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>h>>w;
    for(int i = 0; i< h; i++){
        for(int j = 0; j < w; j++){
            cin>>arr[i][j];
        }
    }

    int ans = 0;
    init();
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(arr[i][j] == 'L'){
                int val = BFS(j, i);
                if(val > ans){
                    ans = val;
                }
            }

            //초기화
            init();
        }
    }

    cout << ans << "\n";


    return 0;
}