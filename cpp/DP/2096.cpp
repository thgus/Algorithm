/*
2096번: 내려가기
https://www.acmicpc.net/problem/2096
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000;
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void solve()
{
    int n;
    int maxArr[3]={0,0,0};
    int minArr[3]={0,0,0};

    cin>>n;
    //메모리 제한이 4MB이니 입력을 받으면서 dp에 저장
    int input[3];
    cin>>input[0]>>input[1]>>input[2];
    //maxArr[0]=max(input[0],input[1]); maxArr[1]=max(input[0],max(input[1],input[2])); maxArr[2]=max(input[1],input[2]);
    //minArr[0]=min(input[0],input[1]); minArr[1]=min(input[0],min(input[1],input[2])); minArr[2]=min(input[1],input[2]);
    maxArr[0]=minArr[0]=input[0];
    maxArr[1]=minArr[1]=input[1];
    maxArr[2]=minArr[2]=input[2];

    int temp[3];
    for(int i=1;i<n;i++){
        cin>>input[0]>>input[1]>>input[2];
        
        temp[0]=max(maxArr[0],maxArr[1]); temp[1]=max(maxArr[0],max(maxArr[1],maxArr[2])); temp[2]=max(maxArr[1],maxArr[2]);
        for(int i=0;i<3;i++) maxArr[i]=temp[i]+input[i];

        temp[0]=min(minArr[0],minArr[1]); temp[1]=min(minArr[0],min(minArr[1],minArr[2])); temp[2]=min(minArr[1],minArr[2]);
        for(int i=0;i<3;i++) minArr[i]=temp[i]+input[i];    
    }

    cout<<max(maxArr[0],max(maxArr[1],maxArr[2]))<<" "<<min(minArr[0],min(minArr[1],minArr[2]));
}

int main()
{
    sync_off;
    solve();

    return 0;
}