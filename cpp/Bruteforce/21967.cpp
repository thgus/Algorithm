/*
21967번: 세워라 반석 위에 
https://www.acmicpc.net/problem/21967
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec;

void initialize()
{
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}

void solve()
{
    int max_len=0;
    for(int start=1;start<=8;start++){
        int end=start+2;

        int cur_len=0;
        for(int i=0;i<n;i++){
            if(vec[i]>=start&&vec[i]<=end){
                cur_len++;
                max_len=max(max_len,cur_len);
            }
            else{
                cur_len=0;
            }
        }
    }

    cout<<max_len;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}