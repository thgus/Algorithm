/*
14002번: 가장 긴 증가하는 부분 수열 4
https://www.acmicpc.net/problem/14002

LIS 알고리즘

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> a(MAX);

void initialize()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

void printArr(vector<pair<int,int>> &vec, int size){
    for(int i=0;i<size;i++){
        cout<<vec[i].first<<" ";
    }
    cout<<"\n";
    for(int i=0;i<size;i++){
        cout<<vec[i].second<<" ";
    }
    cout<<"\n";
}

void printArr(vector<int> &vec, int size){
    for(int i=0;i<size;i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

int _lower_bound(vector<pair<int,int>> &vec, int x){
    int left=0;
    int right=vec.size()-1;
    
    int mid;
    while(left<right){
        mid=(left+right)/2;

        if(vec[mid].first<x){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return right;
}

void solve()
{
    vector<pair<int,int>> lis;
    vector<int> route(MAX);

    //first:value, second: a index
    lis.push_back({a[0],0});
    route[0]=-1;

    for(int i=1;i<n;i++){
        int x=a[i];
        if(lis[lis.size()-1].first<x){
            route[i]=lis[lis.size()-1].second;
            lis.push_back({x,i});
        }
        else{
            int index=_lower_bound(lis,x);
            lis[index].first=x;
            lis[index].second=i;
 
            if(index==0){
                route[i]=-1;
            }
            else{
                route[i]=lis[index-1].second;
            }

        }

        //printArr(lis,lis.size());
    }

    vector<int> result;
    int index=lis[lis.size()-1].second;
    while(route[index]!=-1){
        result.push_back(a[index]);
        index=route[index];
    }
    result.push_back({a[index]});

    reverse(result.begin(),result.end());

    cout<<result.size()<<"\n";
    printArr(result,result.size());

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}