// A->B

#include <iostream>

using namespace std;

long long a,b;
int cnt, ans;

int findCnt(){

    while(1){   
        if(a > b){
            return -1;
        }

        if(a == b){
            return cnt;
        }

        if(b % 2 == 0){
            b /= 2;
        }
        else if(b % 10 == 1){
            --b;
            b /= 10;
        }
        else{
            return -1;
        }

        cnt ++;
    }

    return cnt;
}

int main(){
    cin>>a>>b;

    ans = findCnt();
    if(ans == -1){
        cout << ans << "\n";
    }
    else{
        ans += 1;
        cout << ans << "\n";
    }


}