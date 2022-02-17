/*
15686번: 치킨 배달
https://www.acmicpc.net/problem/15686
*/

#include <iostream>
#include <vector>
#include<cmath>

#define MAX 50
#define STOREMAX 13

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;

void initialize()
{
    cin>>n>>m;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            if(temp==2){
                chicken.push_back({i,j});
            }
            else if(temp==1){
                house.push_back({i,j});
            }
        }
    }
}

int minLen=13*50*2*50+1;

void selectStore(int k, int s, vector<int> &storeNum){
    if(k==m){
        int len=0;
        
        for(int i=0;i<house.size();i++){
            int distance=101;
            for(int j=0;j<storeNum.size();j++){
                int ylen=abs(chicken[storeNum[j]].first-house[i].first);
                int xlen=abs(chicken[storeNum[j]].second-house[i].second);
                
                if(distance>ylen+xlen){
                    distance=ylen+xlen;
                }
            }
            len+=distance;
        }

        if(minLen>len){
            minLen=len;
        }
        return;
    }
    for(int i=s+1;i<chicken.size();i++){
        storeNum.push_back(i);
        selectStore(k+1, i, storeNum);
        storeNum.pop_back();
    }
}

void solve()
{
    vector<int> storeNum;
    selectStore(0, -1, storeNum);
    cout<<minLen;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}