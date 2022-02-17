/*
11577번: Condition of deep sleep
https://www.acmicpc.net/problem/11577
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,k;
vector<bool> bulb;

void initialize()
{
    cin>>n>>k;
    bulb.resize(n);

    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        bulb[i]=(temp==0)?false:true;
    }
}

void solve()
{   
    int count=0;
    queue<int> que;

    for(int i=0;i<=n-k;i++){
        if(que.size()%2==1){
            bulb[i]=bulb[i]^1;
        }
        
        if(bulb[i]){
            count++;
            bulb[i]=false;
            que.push(i+k-1);
        }

        if(!que.empty()&&que.front()==i){
            que.pop();
        }
    }
    
    for(int i=n-k+1;i<n;i++){
        if(que.size()%2==1){
            bulb[i]=bulb[i]^1;
        }
        if(bulb[i]){
            cout<<"Insomnia";
            return;
        }

        if(!que.empty()&&que.front()==i){
            que.pop();
        }
    }
    cout<<count;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}