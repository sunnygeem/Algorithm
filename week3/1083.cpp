// 소트

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        int val; cin>>val;
        v.push_back(val);
    }

    cin>>s;
    for(int i = 0; i < n - 1; i++){
        int max = v[i];
        int max_idx = i;

        if(max < v[max_idx + 1]){
            max = v[max_idx + 1];
            max_idx += 1;

            swap(v[max_idx], v[max_idx - 1]);
            --s;
        }

        

        if(s == 0){
            break;
        }

    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";


    return 0;
}