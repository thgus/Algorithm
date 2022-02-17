/*
1029번: 그림 교환
https://www.acmicpc.net/problem/1029
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> m_key;

void initialize()
{
    cin>>n;
    string temp;
    m_key.resize(n);

    for(int i=0;i<n;i++){
        cin>>temp;

        int key=0;
        for(int i=0;i<temp.size();i++){
            int cur_c=temp[i]-'a';
            key|=(1<<cur_c);
        }
        m_key[i]=key;
    }
}

int result=0;
void dfs(int s, int key){
    if(key==(1<<26)-1){
        result++;
    }

    for(int i=s;i<n;i++){
        int next_key=key|(m_key[i]);
        dfs(i+1,next_key);
    }
}

void solve()
{
    dfs(0,0);
    cout<<result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}