// 마인크래프트

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, b;
int g[500][500];
int minTime;
int minHeight, maxHeight;
int stdHeight, ansHeight;

int main(){
    cin>>n>>m>>b;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
        }
    }

    minHeight = g[0][0];
    maxHeight = g[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] > maxHeight){
                maxHeight = g[i][j];
            }
            else if(g[i][j] < minHeight){
                minHeight = g[i][j];
            }
        }
    }

    int cnt = 0;

    for(int i=minHeight; i<=maxHeight; i++){
        stdHeight = i;
        int add = 0; int remove = 0;
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                
                int subHeight = g[j][k] - i;
                if(subHeight > 0){
                    remove += subHeight;
                }
                else if(subHeight < 0){
                    add += abs(subHeight);
                }
            }
        }

        // 제거하는 것은 인벤토리와 상관 X
        // 추가하는 것은 인벤토리의 사정을 고려해야 함
        if(b + remove >= add){
            int time = (remove*2) + add;

            if(cnt == 0){
                minTime = time;
            }

            if(minTime > time){
                minTime = time;
                ansHeight = stdHeight;
            }
        }

        cnt++;
    }

    cout << minTime << " " << ansHeight << "\n";

    return 0;
}