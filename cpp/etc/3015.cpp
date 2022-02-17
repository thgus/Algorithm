/*
3015번: 오아시스 재결합
https://www.acmicpc.net/problem/3015
*/

#include <iostream>
#include <vector>
#include <stack>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

long long n;

struct Node{
    long long num, same;
};

void solve()
{
    cin>>n;

    long long sum=0;
    stack<Node> s;

    while(n--){
        long long cur;
        cin>>cur;

        while(!s.empty()&&s.top().num<cur){
            sum++;
            s.pop();
        }

        if(s.empty()){
            s.push({cur,1});
        }
        else if(s.top().num>cur){
            sum++;
            s.push({cur,1});
        }
        else if(s.top().num==cur){
            if(s.size()==s.top().same){
                sum+=s.top().same;
            }
            else{
                sum+=s.top().same+1;
            }
            s.push({cur,s.top().same+1});
        }
    }    

    cout<<sum;
}


int main()
{
    sync_off;
    solve();

    return 0;
}