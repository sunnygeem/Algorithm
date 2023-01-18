// 파일 합치기 3

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long t, k, ans;

long long cost(vector<int> vec){
    long long cost = 0;

    while(vec.size() != 1){
        sort(vec.begin(), vec.end());
        long long val1 = vec.front();
        vec.erase(vec.begin());
        long long val2 = vec.front();
        vec.erase(vec.begin());

        long long midCal = val1 + val2;
        cost += midCal;

        vec.push_back(midCal);
    }

    return cost;
}

int main(){
    cin>>t;
    while(t--){
        cin>>k;
        vector<int> v; long long val;
        for(long long i=0; i<k; i++){
            cin>>val;
            v.push_back(val);
        }

        ans = cost(v);
        cout << ans << "\n";

    }

    return 0;
}