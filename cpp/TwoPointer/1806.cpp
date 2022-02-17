/*
1806번: 부분합
https://www.acmicpc.net/problem/1806

left right 둘 다 0에서 시작해서 
값이 s보다 작으면 right를 한칸 앞으로 (값 증가)
값이 s보다 크면 left를 한칸 앞으로 (값 감소) 하는 식으로 해서
가장 작은 길이를 찾는거구나!

진짜 혼자서는 생각하기 넘 어려울거같아
두 포인터로 분류되어 있어서 생각해낸거지
어렵다... 더 공부해야해ㅜㅠ

*/

#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 1000000001;
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main(){
    sync_off;
    vector<int> vec;
    int n,s;
    cin>>n>>s;

    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }

    int left=0;
    int right=0;

    int minLen=MAX;
    int sum=vec[left];

    bool isChange=false;
    while(left<=right && right<n ){
        if(sum>=s){
            if(minLen>(right-left)){
                isChange=true;
                minLen=right-left;
            }
            sum-=vec[left];
            left++;  
        }else{
            right++;
            sum+=vec[right];
        }     
    }

    //이거 왜 안되지??
    //if(minLen==MAX){
    if(!isChange){
        cout<<"0";
    }
    else{
        cout<<minLen+1;
    }

    return 0;
}