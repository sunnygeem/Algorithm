// 가장 긴 증가하는 부분 수열 5

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> v;

int findIdx(vector<int> vec, int val){
    for(int i = 0; i<vec.size(); i++){
        if(vec[i] >= val){
            return i;
        }
    }
}

int main(){
    int n; cin>>n;

    int k; int tmp[100000];
    for(int i=0; i<n; i++){
        cin>>k;
        tmp[i] = k;
    }

    v.push_back(tmp[0]);
    for(int i=1; i<n; i++){
        int size = v.size();
        if(v[size - 1] < tmp[i]){
            v.push_back(tmp[i]);
        }
        else{ // v[size - 1] > tmp[i]
            int idx = findIdx(v, tmp[i]);
            v[idx] = tmp[i];
        }
    }

    cout << n - v.size() << "\n";
    
    return 0;
}