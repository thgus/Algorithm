/*
9205번: 맥주 마시면서 걸어가기
https://www.acmicpc.net/problem/9205
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    sync_off;
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> location;

        int x,y;
        for(int i=0;i<n+2;i++){
            cin>>x>>y;
            location.push_back({x,y});
        }

        //vector<vector<double>> route(n+2,vector<double>(n+2));
        vector<vector<int>> route(n+2,vector<int>(n+2));
        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++){
                //double len=sqrt(pow(location[i].first-location[j].first,2)+pow(location[i].second-location[j].second,2));
                //두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이 이다.
                int len=abs(location[i].first-location[j].first)+abs(location[i].second-location[j].second);
                route[i][j]=route[j][i]=len;
            }
        }

        bool isHappy=false;
        vector<bool> visited(n+2,false);
        queue<int> que;
        que.push(0);
        visited[0]=true;
        while(!que.empty()){
            int cur=que.front();
            que.pop();

            if(cur==n+1){
                isHappy=true;
                break;
            }

            for(int next=0;next<n+2;next++){
                if(cur==next)   continue;
                if(route[cur][next]>50*20)  continue;
                if(visited[next])   continue;
                visited[next]=true;
                que.push(next);
            }
        }

        if(isHappy){
            cout<<"happy\n";
        }
        else{
            cout<<"sad\n";
        }
    }

    return 0;
}