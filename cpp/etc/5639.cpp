/*
5639번: 이진 검색 트리
https://www.acmicpc.net/problem/5639

입력받는거 엄청 신기하다
*/

#include<iostream>
#include<vector>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<int> vec;
void initialize(){
    int temp;
    while(cin>>temp){
        vec.push_back(temp);
    }
}

void findNode(int left, int right){
    int i;

    if(left==right){
        cout<<vec[left]<<"\n";
        return;
    }
    else if (left>right){
        return;
    }

    for(i=left+1; i<=right; i++){
        if(vec[left]<vec[i]){
            break;
        }
    }

    findNode(left+1,i-1);
    findNode(i,right);
    cout<<vec[left]<<"\n";
}

void solve(){
    findNode(0,vec.size()-1);
}

int main(){
    sync_off;
    initialize();
    solve();
    
    return 0;
}