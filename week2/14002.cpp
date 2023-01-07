// 가장 긴 증가하는 부분수열 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int v[1001]; // 수열 A
int idx[1001]; // LIS의 index 저장. idx[a] = b : A의 a번째 값은 LIS에서 b번째에 위치함.
vector<int> lis; // LIS
vector<int> ans;

void makeLIS(int arr[1001]){
    
    for(int i=1; i<=n; i++){
        if(lis.size() == 0 || lis[lis.size() - 1] < v[i]){
            lis.push_back(v[i]);
            idx[i] = lis.size() - 1;
        }
        else{ // lis[lis.size() - 1] >= v[i]
            int left = 0; int right = lis.size() - 1;
            while(left < right){
                int mid = (left + right) / 2;
                if(lis[mid] >= v[i]){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }

            lis[left] = v[i];
            idx[i] = left;


        }
    }
}

int main(){
    ios::sync_with_stdio(0); // 스트림 간 동기화를 해제해주어 빠른 입출력을 가능하게함
    cin.tie(NULL); // flush (buffer에 쌓인 데이터를 모두 내보내는 것)의 빈도를 줄여 입출력 속도를 향상시킴
    cout.tie(NULL);

    cin>>n;
    int val;
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    makeLIS(v);
    cout << lis.size() << "\n";

    int lis_size = lis.size() - 1;
    for(int i = n; i > 0; i--){
        if(idx[i] == lis_size){
            lis_size--;
            ans.push_back(v[i]);
        }
    }

    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }

    cout << "\n";





    return 0;
}