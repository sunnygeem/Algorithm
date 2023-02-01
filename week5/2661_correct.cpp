// 좋은 수열

#include <iostream>
#include <string>

using namespace std;

int n;
int stop = 0;

int check(string str){ // 좋은 수열인지
    int s = str.length();
    int end = s -1;
    string s1, s2;
    for(int i=1; i<=s/2; i++){
        s1 = str.substr(end-i, i);
        s2 = str.substr(end, i);
        if(!s1.compare(s2)){
            return false;
        }
        end--;
    }

    return true;
}

void dfs(string str, int num){
    if(stop == 1){
        return;
    }

    if(!check(str)){
        return;
    }

    if(num == n){
        cout << str << "\n";
        stop = 1;
        return;
    }

    dfs(str+'1', num+1);
    dfs(str+'2', num+1);
    dfs(str+'3', num+1);

}

int main(){
    cin>>n;
    
    string s;
    dfs(s, 0);

    return 0;
}