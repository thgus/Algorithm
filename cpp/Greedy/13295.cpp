/*
13295번: Nine Packs
https://www.acmicpc.net/problem/13295
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

int h,b;

vector<int> hotdog;
vector<int> bun;
//vector<int> hotdog(MAX+1,0);
//vector<int> bun(MAX+1,0);
int hotdogNum=0;

void initialize()
{
    cin>>h;
    int temp;
    for(int i=0;i<h;i++){
        cin>>temp;
        hotdog.push_back(temp);
        //hotdog[temp]++;
        hotdogNum+=temp;
    }
    cin>>b;
    for(int i=0;i<b;i++){
        cin>>temp;
        bun.push_back(temp);
        //bun[temp]++;
    }
}

void solve()
{
    vector<int> dp(MAX+1,0);
    for(int cur=0;cur<b;cur++){
        int curBun=bun[cur];
        for(int i=hotdogNum;i>0;i--){
            if(i<curBun){
                break;
            }
            dp[i]=max(dp[i],dp[i-curBun]+1);
        }
        for(int i=0;i<=hotdogNum;i++){
            cout<<dp[i]<<" ";
        }
        cout<<"\n";
    }

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}
