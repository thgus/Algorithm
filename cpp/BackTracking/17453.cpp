/*
17453번: 두 개의 문
https://www.acmicpc.net/problem/17453

진짜 비트연산 대어렵다. 정리하기도 힘들어
*/

#include <iostream>
#include <vector>
#include <bitset>

#define NMAX 101
//#define NMAX 3
#define MNAX 20
#define POWMAX 1048577
//#define POWMAX 5
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
bitset<NMAX> start=0;
vector<bitset<NMAX>> gate;

void initialize()
{
    cin>>n>>m;

    char c;
    for(int i=n-1;i>=0;i--){
        cin>>c;
        if(c=='1'){
            start.set(i,true);
        }
        else{
            start.set(i,false);
        }
    }

    for(int i=0;i<m;i++){
        bitset<NMAX> temp;
        for (int i = n - 1; i >= 0; i--){
            cin >> c;
            if (c == '1'){
                temp.set(i,true);
            }
            else{
                temp.set(i,false);
            }
        }
        gate.push_back(temp);
    }

}

vector<vector<int>> result(2*NMAX+1);
//2^20+1
vector<bool> isVisited(POWMAX,false);

void dfs(bitset<NMAX> cur, int depth, int pressBtn){
    if(isVisited[pressBtn]||depth>m){
        return;
    }
    isVisited[pressBtn]=true;
    
    int index=0;
    for(int i=0;i<n;i++){
        (cur.test(i)==1)?index++:index--;
    } 
    if(result[n+index].size()==0){
         for(int i=0;i<m;i++){
             if(pressBtn&(1<<i)){
                 result[n+index].push_back(i+1);
             }
         }
    }

    for(int i=0;i<m;i++){
        int nextPressBtn=pressBtn|(1<<i);
        dfs(cur^gate[i],depth+1,nextPressBtn);
    }

}

void solve()
{
    dfs(start, 0, 0);

    int index=0;
    for(int i=0;i<n;i++){
        if(start.test(i)==1){
            index++;
        }
        else{
           index--;
        }
    }

    for(int i=0;i<2*n+1;i++){
        if(i==(n+index)){
            cout<<"0\n";
            continue;
        }

        if(result[i].size()==0){
            cout<<"-1\n";
        }
        else{
            cout<<result[i].size()<<" ";
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
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