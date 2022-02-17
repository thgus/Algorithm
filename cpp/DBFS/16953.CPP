/*
16953번: A → B
https://www.acmicpc.net/problem/16953
*/

#include<iostream>
#include<vector>
#include<queue>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int a,b;

void initialize(){
    cin>>a>>b;
}

int solve(){  
    queue<pair<long long,int>> que;
    que.push({(long long)a,1});

    long long n;
    while(!que.empty()){
        n=que.front().first;
        if(n==b){
            return que.front().second;
        }
        
        if(n*10+1<=1000000000){
            que.push({n*10+1,que.front().second+1});
        }
        
        if(n*2<=1000000000){
            que.push({n*2,que.front().second+1});
        }

        que.pop();
    }

    return -1;
}

int main(){
    sync_off;
    initialize();
    cout<<solve();
    
    return 0;
}