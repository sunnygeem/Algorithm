// LCS2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char x[1001]={0, };
char y[1001]={0, };
int m, n;
vector<char> v;
int length = 0;

int len[1001][1001];
int dir[1001][1001];

void sol(){
    for(int i=0; i<=m; i++){
        len[i][0] = 0;
    }
    for(int j=0; j<=n; j++){
        len[0][j] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i] == y[j]){ // 문자가 같을 때
                len[i][j] = len[i-1][j-1] + 1;
                dir[i][j] = 0;
            }
            else if(len[i-1][j] >= len[i][j-1]){ // 위의 값 채택
                len[i][j] = len[i-1][j];
                dir[i][j] = 1;
            }
            else{ // 왼쪽 값 채택
                len[i][j] = len[i][j-1];
                dir[i][j] = 2;
            }
        }
    }
}

void print(int d[1001][1001], char x2[1001], int i, int j){
    if(i == 0 || j == 0){
        return;
    }

    if(d[i][j] == 0){
        print(d, x2, i-1, j-1);
        v.push_back(x2[i]);
        length++;
    }
    else if(d[i][j] == 1){
        print(d, x2, i-1, j);
    }
    else{
        print(d, x2, i, j-1);
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;
    m = a.length();
    for(int i=1; i<=m; i++){
        x[i] = a[i-1];
    }
    n = b.length();
    for(int i=1; i<=n; i++){
        y[i] = b[i-1];
    }

    sol();

    print(dir, x, m, n);
    cout<<length<<"\n";
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
    cout<<"\n";

    return 0;
}