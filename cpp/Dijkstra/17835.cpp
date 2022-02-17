/*
17835번: 면접보는 승범이네
https://www.acmicpc.net/problem/17835
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,k;
vector<vector<pair<int,int>>> route;
vector<long long> len;
vector<int> interview_city;

void initialize()
{
    cin>>n>>m>>k;
    route.resize(n+1);
    len.resize(n+1,LLONG_MAX);

    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        route[b].push_back({a,c});
    }

    for(int i=0;i<k;i++){
        cin>>a;
        interview_city.push_back(a);
        len[a]=0;
    }
}

void solve()
{
    queue<pair<long long,int>> que;
    for(int i=0;i<interview_city.size();i++){
        int start=interview_city[i];
        que.push({0,start});

        while(!que.empty()){
            long long clen=que.front().first;
            int cnum=que.front().second;
            que.pop();

            if(len[cnum]<clen)  continue;

            for(pair<int,int> next:route[cnum]){
                int nnum=next.first;
                long long ncost=clen;
                ncost+=(long long)next.second;
                
                if(len[nnum]>ncost){
                    len[nnum]=ncost;
                    que.push({ncost,nnum});
                }
            }
        }
    }

    long long max_len=0;
    int max_index;

    for(int i=1;i<=n;i++){
        if(len[i]!=LLONG_MAX && max_len<len[i]){
            max_len=len[i];
            max_index=i;
        }
    }

    cout<<max_index<<"\n"<<max_len;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}