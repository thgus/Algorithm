/*
19543번: 던전 지도
https://www.acmicpc.net/problem/19543

https://ip99202.github.io/posts/%EB%B0%B1%EC%A4%80-19543-%EB%8D%98%EC%A0%84-%EC%A7%80%EB%8F%84/
왜 계속 시간초과나지 싶었는데 2만짜리 string을 계속 변수로 할당해줘서 그런거였다.
변수 할당도 시간 생각하면서 해야해;;
*/

#include <iostream>
#include <vector>
#include <stack>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    sync_off;
    
    int n,m,k;
    cin>>n>>m>>k;

    vector<string> temp(k);
    for(int i=0;i<k;i++){
        cin>>temp[i];
    }

    char c;
    stack<int> s;
    for(int i=0;i<n;i++){
        cin>>c;
        s.push(c-'A');
    }

    int index=s.top();
    s.pop();

    int left,right;
    left=right=m-1;
    left--;
    while(1){
        if(left==-1)    break;
        if(temp[index][left]=='U')  break;
        left--;
    }
    long long num=right-left;

    while(!s.empty()){
        index=s.top();
        s.pop();

        while(1){
            if(right==-1)    break;
            if(right==left)    break;
            if(temp[index][right]=='U')    break;
            right--;
        }
        if(right==left)    break;
        if(right==-1)   break;

        while(1){
            if(left==-1)   break;
            if(temp[index][left]=='U') break;
            left--;
        }
        num+=right-left;
    }

    cout<<num;

    return 0;
}