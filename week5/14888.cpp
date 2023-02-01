// 연산자 끼워넣기

#include <iostream>

using namespace std;

int n;
int arr[11];
int op[4];
int minVal = 1000000000;
int maxVal = -1000000000;

void dfs(int res, int cnt){
    if(cnt == n){ //종료조건
        if(res > maxVal){
            maxVal = res;
        }

        if(res < minVal){ //else if 사용 X
            minVal = res;
        }

        return;
    }

    for(int i=0; i<4; i++){
        if(op[i] > 0){
            op[i] -= 1;

            if(i == 0){ //+
                dfs(res + arr[cnt], cnt+1);
                // 처음 cnt 인자를 0으로 주고, arr[cnt+1]로 연산하게 되면 나중에 overbound
            }
            else if(i == 1){ //-
                dfs(res - arr[cnt], cnt+1);
            }
            else if(i == 2){ //*
                dfs(res * arr[cnt], cnt+1);
            }
            else{ ///
                dfs(res / arr[cnt], cnt+1);
            }

            op[i] += 1; //다음 depth에서의 사용을 위해 다시 +
        }

    }

    return;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<4; i++){
        cin>>op[i];
    }

    dfs(arr[0], 1);

    cout << maxVal << "\n" << minVal << "\n";

    return 0;
}