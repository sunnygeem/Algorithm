// 사다리

#include <iostream>
#include <cmath>

using namespace std;

double x, y, c, guess_c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>x>>y>>c;

    // k (원하는 값)를 이분탐색을 이용하여 예측 
    double l = 1;
    double r = min(x,y);
    double k, h1, h2;

    // k를 변경하며 c를 추측해보고, c와 일치하는지 확인
    while(r - l >= 0.001){
        k = (l+r) / 2.0;
        // c = h1*h2/(h1+h2)
        h1 = sqrt(x*x - k*k);
        h2 = sqrt(y*y - k*k);
        guess_c = (h1*h2) / (h1+h2);

        if(guess_c >= c){
            l = k;
        }
        else{
            r = k;
        }
    }

    cout << k << "\n";
    

    
    return 0;
}