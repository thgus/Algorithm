/*
17394번: 핑거 스냅
https://www.acmicpc.net/problem/17394
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>

#define MIN 2
#define MAX 1000000
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<bool> isPrime(MAX+1,true);

void setPrimeNum(){
    isPrime[1]=false;
    for(int i=2;i<sqrt(MAX+1);i++){
        for(int j=i*i;j<=MAX;j+=i){
            isPrime[j]=false;
        }
    }
}

int bfs(int n, int a, int b){
    queue<pair<int,int>> que;
    que.push({n,0});

    int people;
    int snap;

    vector<bool> visited(MAX+100);
    visited[n]=true;

    while(!que.empty()){
        people=que.front().first;
        snap=que.front().second;
        que.pop();
        
        if(people>=a&&people<=b&&isPrime[people]){
            return snap;
        }

        if((people/2)>=MIN && !visited[people/2]){
            que.push({people/2,snap+1});
            visited[people/2]=true;
        } 
        if((people/3)>=MIN && !visited[people/3]){
            que.push({people/3,snap+1});
            visited[people/3]=true;
        }
        if(!visited[people+1]){
            que.push({people+1,snap+1});
            visited[people+1]=true;
        }
        if(people-1>=MIN && !visited[people-1]){
            que.push({people-1,snap+1});
            visited[people-1]=true;
        }
    }

    return -1;
}

int solv(int n, int a, int b){
    bool existPrime=false;
    for(int i=a;i<=b;i++){
        if(isPrime[i]){
            existPrime=true;
        }
    }
    if(!existPrime){
        return -1;
    }else{
        return bfs(n,a,b);
    }
}

int main(){
    sync_off;
    setPrimeNum();

    int t;
    cin>>t;
    int n,a,b;

    while(t-->0){
        cin>>n>>a>>b;
        cout<<solv(n,a,b)<<"\n";
    }

    return 0;
}