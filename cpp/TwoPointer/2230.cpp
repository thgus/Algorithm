/*
2230번: 수 고르기
https://www.acmicpc.net/problem/2230
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100005
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    sync_off;
    
    int arr[MAX];
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    int left,right;
    left=right=0;

    int result=2000000001;
    while(right<n){
        int sub=arr[right]-arr[left];

        if(sub>=m){
            result=min(result,sub);
        }

        if(sub<=m){
            right++;
        }
        else{
            left++;
        }
    }
    cout<<result;

    return 0;
}