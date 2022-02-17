/*
10800번: 컬러볼
https://www.acmicpc.net/problem/10800
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;

vector<pair<int,int>> vec;
vector<vector<int>> colorVec(MAX+1);

int lowerBound(vector<pair<int,int>> &p, int key){
    int start=0;
    int end=p.size()-1;

    while(end-start>0){
        int mid=(start+end)/2;
        if(p[mid].first<key){
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return end+1;
}

int lowerBound(vector<int> &p, int key){
    int start=0;
    int end=p.size()-1;

    while(end-start>0){
        int mid=(start+end)/2;
        if(p[mid]<key){
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return end+1;
}

void initialize()
{
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec.push_back({b,a});
        colorVec[a].push_back(b);
    }
}

void solve()
{
    vector<vector<int>> sum(MAX+1);
    vector<int> totalSum;

    vector<vector<int>> colorVecTemp=colorVec;
    vector<pair<int,int>> temp=vec;
    
    for(int i=1;i<=n;i++){
        sort(colorVecTemp[i].begin(),colorVecTemp[i].end());
    }
    sort(temp.begin(),temp.end());

    for(int i=0;i<n;i++){
        int curWeight=temp[i].first;
        int curColor=temp[i].second;

        int preWeight=0;
        if(!totalSum.empty()){
            preWeight=totalSum[totalSum.size()-1];
        }
        totalSum.push_back(preWeight+curWeight);

        preWeight=0;
        if(!sum[curColor].empty()){
            preWeight=sum[curColor][sum[curColor].size()-1];
        }
        sum[curColor].push_back(preWeight+curWeight);
    }

    for(int i=0;i<n;i++){
        int curWeight=vec[i].first;
        int curColor=vec[i].second;

        int index=lowerBound(temp,curWeight)-1;
        int colorIndex=lowerBound(colorVecTemp[curColor],curWeight)-1;

        cout<<totalSum[index]-sum[curColor][colorIndex]<<"\n";
    }

}


int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}