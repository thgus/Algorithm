/*
10844번: 쉬운 계단 수
https://www.acmicpc.net/problem/10844
*/

#include<iostream>
#include<vector>

#define MAX 100
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<vector<long long>> vec(MAX+1,vector<long long>(10,0));

void initialize(){
    cin>>n;
}

void solve(){
    for(int i=1;i<10;i++){
        vec[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            if(j==0){
                vec[i][j]+=vec[i-1][j+1];
            }
            else if(j==9){
                vec[i][j]+=vec[i-1][j-1];
            }
            else{
                vec[i][j]+=vec[i-1][j+1];
                vec[i][j]+=vec[i-1][j-1];
            }
            vec[i][j]=vec[i][j]%1000000000;
        }
    }

    long long sum=0;
    for(int i=0;i<10;i++){
        sum=(sum+vec[n][i])%1000000000;
    }
    cout<<sum;
}

int main(){
    sync_off;
    initialize();
    solve();
    
    return 0;
}