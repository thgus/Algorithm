/*
2565번: 전깃줄
https://www.acmicpc.net/problem/2565

이거 백트래킹으로는 못푸나...?
위치가 500까지라 백트래킹하면 시간 엄청 오래걸릴거 같긴 하다
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 100
#define NUMMAX 500
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<pair<int,int>> vec;

void initialize(){
    cin>>n;

    int a,b;
    vec.push_back({0,0});
    for(int i=1;i<=n;i++){
        //cin>>vec[i].first>>vec[i].second;
        cin>>a>>b;
        vec.push_back({a,b});
    }
}

vector<int> pole(NUMMAX+1,0);

void solve(){
    sort(vec.begin(),vec.end());

    int to;
    for(int i=1;i<=n;i++){
        to=vec[i].second;

        pole[to]++;
        for(int j=to+1;j<=NUMMAX;j++){
            if(pole[j]<pole[to]){
                pole[j]=pole[to];
            }
            else{
                break;
            }
        }
        //cout<<vec[i].first<<" "<<vec[i].second<<" "<<pole[NUMMAX]<<"\n";
    }

    cout<<n-pole[NUMMAX];
}

int main(){
    sync_off;
    initialize();
    solve();
    
    return 0;
}