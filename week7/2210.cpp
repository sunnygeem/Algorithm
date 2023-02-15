#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set> // set은 중복을 허용하지 않음 => 만들 수 있는 수. 자동정렬.

using namespace std;

int arr[5][5];

int dy[] = {1,-1,0,0}; // 상하좌우
int dx[] = {0,0,-1,1};

set<int> ans;

void BFS(int x, int y){
    queue<pair<string, pair<int, int>>> q;
    int cur = arr[y][x];
    string str = ""; // 만들 수 있는 수
    str += ('0' + cur);
    q.push({str, {x, y}});

    while(q.empty() != true){
        string s = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(s.size() == 6){
            ans.insert(stoi(s));
            continue;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5){
                continue;
            }

            string tmp = s;
            tmp += (arr[ny][nx] + '0');
            q.push({tmp, {nx, ny}});
        }
    }

}

int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            BFS(j, i);
        }
    }

// for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
// 	cout << *it << "\n";
// }
    cout << ans.size() << "\n";

    return 0;
}