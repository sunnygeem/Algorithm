// 꼬인 전깃줄

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
int arr[1000010];
int index[1000010];
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    // 이처럼 푸는 방법은 O(N^2). 문제에서 원하는 방법은 O(NlogN)
    // => 데이터가 들어가는 index 위치를 저장
    // (index[a] = b : 원본 데이터에서 a번째에 있는 숫자는, LIS 배열에서 b번째에 위치)

    // vector<int> ans;
    // ans.push_back(v[0]);
    // for(int i=1; i<v.size(); i++){
    //     int ans_size = ans.size();
    //     if(ans[ans_size - 1] < v[i]){
    //         ans.push_back(v[i]);
    //     }
    //     else{ // ans[ans_size - 1] > v[i]
    //         int idx = findIdx(ans, v[i]);
    //         ans[idx] = v[i];
    //     }
    // }

    for(int i=1; i<=n; i++){
        if(v.size() == 0 || v[v.size() - 1] < arr[i]){
            v.push_back(arr[i]);
            index[i] = v.size() - 1;
        }
        else{
            int left = 0; int right = v.size() - 1;
            while(left < right){ // 이전 for 문 : O(N), 현재 while문 : O(logN)
                int mid = (left + right) / 2;

                if(v[mid] >= arr[i]){
                    right = mid;
                }
                else{
                    left = mid+1;
                }
            }
            
            v[left] = arr[i];
            index[i] = left;
        }
    }

    cout<<v.size()<<"\n";

    // 아래 방법으로 출력하는 것은 오답
    // v는 각 원소의 basic 배열에서의 index 순서를 고려하지 않은, 순수 값의 크기 비교만 실행한 벡터이기 때문

    // cout<<v.size()<<"\n";

    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<"\n";

    vector<int> ans;
    int idx = v.size() - 1;
    for(int i=n; i>0; i--){ // 값이 같아도 나중에 집어넣은 것이 답이 되므로 거꾸로 push_back
        if(index[i] == idx){
            idx--;
            ans.push_back(arr[i]);
        }
    }
    for(int i = ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";



    return 0;
}