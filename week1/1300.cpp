// K번째 수

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std; 

// 수의 크기가 크므로 int 오류날 수 있음 => 전체 다 long long
long long n; long long k;

// mid값보다 같거나 작은 값의 개수를 측정
long long countUnderMid(long long mid){
    long long cnt = 0;
    for(int i=1; i<=n; i++){
        // 행별로 탐색
        // 전체 길이이거나, mid / i이거나.
        // mid / i는 행별로 i의 배수라는 규칙성을 이용한 것
        cnt += min(n, (long long)mid / i);
        if(i > mid){ // 더 이상 원하는 범위의 수를 찾을 수 없을 때
            break;
        }
    }

    return cnt;

}

int main(){
    cin>>n>>k;

    long long low = 1;
    long long high = n*n; // 저장된 수는 인덱스 k보다 무조건 작을 수밖에 => n*n 대신 k 써도 됨

    int ans = 0;

    while(low <= high){
        long long mid = (low + high) / 2; // mid 설정
        if(countUnderMid(mid) < k){
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid - 1;
        }

        // 같은 값이 여러 번 중복되는 문제
        // 아래와 같은 경우를 따로 분리하면 답을 구할 수 없음

        // else{
        //     ans = mid;
        // }
        
    }
    cout << ans;

    return 0;
}