/*
2568번: 전깃줄 -2 
https://www.acmicpc.net/problem/2568
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define ELECTMAX 100000
#define NMAX 500000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<pair<int,int>> electricCord;
vector<bool> need(NMAX+1,true);

void initialize()
{
    cin>>n;
    int a,b;

    electricCord.push_back({0,0});
    for(int i=0;i<n;i++){
        cin>>a>>b;
        need[a]=false;
        electricCord.push_back({a,b});
    }
}

void solve()
{
    vector<int> route(ELECTMAX+1);
    sort(electricCord.begin(),electricCord.end());    
    
    vector<int> seq;
    vector<int> saveIndex;
    route[0]=route[1]=-1;
    seq.push_back(electricCord[1].second);
    saveIndex.push_back(1);

    int lastIndex=1;

    for(int i=2;i<=n;i++){
        int a=electricCord[i].first;
        int b=electricCord[i].second;

        if(b>seq.back()){
            seq.push_back(b);
            route[i]=saveIndex.back();
            saveIndex.push_back(i);
            lastIndex=i;
        }
        else{
            int index=lower_bound(seq.begin(),seq.end(),b)-seq.begin();
            seq[index]=b;
            saveIndex[index]=i;

            if(index!=0){
                route[i]=saveIndex[index-1];
            }
            else{
                route[i]=-1;
            }
        }
    }

    while(route[lastIndex]!=-1){
        int cur=electricCord[lastIndex].first;
        need[cur]=true;
        lastIndex=route[lastIndex];
    }
    int cur=electricCord[lastIndex].first;
    need[cur]=true;

    cout<<n-seq.size()<<"\n";
    for(int i=1;i<=NMAX;i++){
        if(!need[i]){
            cout<<i<<"\n";
        }
    }

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}