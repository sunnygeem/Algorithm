// 양팔저울

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int penNum, marNum;
int pen[31]; int mar[8];


int findPenIdx(int dif, int arr[31], int idx, vector<int> use){
    if(dif < 0){
        dif = abs(dif);
    }
    // dif = 차, arr = 추 배열, idx = 사용가능한 가장 큰 추의 idx
    for(int i=0; i<=idx; i++){
        if(arr[i] == dif && use[i] == 1){
            return i;
        }
    }

    return -1;

}

int findLargestIdx(vector<int> use){
    for(int i=use.size(); i>0; i--){
        if(use[i] == 1){
            return i;
        }
    }
    
    return -1;
}

int penUsePos(vector<int> use){ // 사용가능한 추가 남았는지 여부 확인
    int size = use.size();
    for(int i = 0; i < use.size(); i++){
        if(use[i] == 1){
            return 1;
        }
    }

    return 0;
}

int main(){
    cin>>penNum;
    for(int i= 0; i < penNum; i++){
        cin>>pen[i]; // 오름차순으로 주어짐
    }
    cin>>marNum;
    for(int i = 0; i< marNum; i++){
        cin>>mar[i];
    }

    
    for(int i = 0; i< marNum; i++){
        vector<int> penUse(penNum, 1); // 해당 index의 추를 사용할 수 있으면 1, 없으면 0    
        vector<int> left; vector<int> right;
        int penIdx = penNum - 1; // 한 번 사용하면 다시 사용할 수 없음
        int leftCnt = 0, rightCnt = 0;
        // 1. 제일 무거운 추를 우측에, 구슬을 좌측에
        left.push_back(mar[i]);
        leftCnt += mar[i];
        right.push_back(pen[penIdx]);
        rightCnt += pen[penIdx];
        penUse[penIdx] = 0;

        int dif; int ans_flag = 0;
        while(1){
        // 2. 둘의 차를 계산
        // => 차와 일치하는 추 존재하면 보충
        // => 그렇지 않으면, 값이 더 작은 쪽에 가장 큰 추를 보충한 후 다시 차를 계산
            dif = leftCnt - rightCnt; // 음수면 left에 보충, 양수면 right에 보충
            if(dif == 0){
                    ans_flag = 1;
                    break;
            }

            if(!penUsePos(penUse)){
                break;
            }

            int newIdx = findPenIdx(dif, pen, penIdx, penUse);
            if(newIdx != -1){ // 차와 일치하는 추 존재
                if(dif < 0){
                    left.push_back(pen[newIdx]);
                    leftCnt+=pen[newIdx];
                    penUse[newIdx] = 0;
                }
                else if(dif > 0){
                    right.push_back(pen[newIdx]);
                    rightCnt+=pen[newIdx];
                    penUse[newIdx] = 0;
                }
            }
            else{ // 차와 일치하는 추 존재 X

                int addIdx = findLargestIdx(penUse);
                if(addIdx == -1){
                    break;
                }
                
                if(dif > 0){
                    right.push_back(pen[addIdx]);
                    rightCnt+=pen[addIdx];
                    penUse[addIdx] = 0;
                }
                else if(dif < 0){
                    left.push_back(pen[addIdx]);
                    leftCnt+=pen[addIdx];
                    penUse[addIdx] = 0;
                }
            }



        }

        if(ans_flag == 1){
            cout << "Y" << " ";
        }
        else{
            cout << "N" << " ";
        }

        

    }

    cout << "\n";

    return 0;
}