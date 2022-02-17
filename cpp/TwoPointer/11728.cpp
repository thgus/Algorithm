/*
11728번: 배열 합치기
https://www.acmicpc.net/problem/11728
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    sync_off;
    vector<int> vec;
    int temp;
    
    int n,m;
    cin>>n>>m;
    while(n--){
        cin>>temp;
        vec.push_back(temp);
    }
    while(m--){
        cin>>temp;
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());

    for(int cur:vec){
        cout<<cur<<" ";
    }
    return 0;
}