/*
11054번: 가장 긴 바이토닉 부분 수열
https://www.acmicpc.net/problem/11054

코드 더럽다 더러워
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> a;

void initialize()
{
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        a.push_back(temp);
    }
}

void printArr(vector<int> &result, int size){
    for(int i=0;i<size;i++){
        cout<<result[i]<<" ";
    }
    cout<<"\n";
}

int _lower_bound(vector<int> &vec, int x){
    int left=0;
    int right=vec.size()-1;
    
    int mid;
    while(left<right){
        mid=(left+right)/2;

        if(vec[mid]<x){
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
    //first:value, second: a index
    vector<int> lis1, lis2;
    lis1.push_back(a[0]);

    vector<int> result(MAX,0);
    vector<int> resultMax(MAX);


    for(int i=0;i<n;i++){  
        int x=a[i];
        
        if(lis1.empty()||lis1.back()<x){
            lis1.push_back(x);
        }
        else{
            int index=_lower_bound(lis1,x);
            lis1[index]=x;
        }

        result[i]+=lis1.size();
        resultMax[i]=lis1.back();

    }

    reverse(a.begin(),a.end());

    for(int i=0;i<n-1;i++){
        int x=a[i];

        if(lis2.empty()||lis2.back()<x){
            lis2.push_back(x);
        }
        else{
            int index=_lower_bound(lis2,x);
            lis2[index]=x;
        }

        (resultMax[n-2-i]==lis2.back())?result[n-2-i]+=lis2.size()-1:result[n-2-i]+=lis2.size();
    
    }

    int maxLen=0;
    for(int i=0;i<n;i++){
        if(maxLen<result[i]){
            maxLen=result[i];
        }
    }
    cout<<maxLen;
    
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}