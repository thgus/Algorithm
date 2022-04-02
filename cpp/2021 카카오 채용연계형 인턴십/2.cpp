#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int dy[4]={-1,1,0,0};
    int dx[4]={0,0,-1,1};
    
    for(int i=0;i<5;i++)
    {
        bool isSafe=true;
        for(int y=0;y<5;y++){
            for(int x=0;x<5;x++){
                if(places[i][y][x]!='P')    continue;
                vector<vector<bool>> visited(5,vector<bool>(5,false));   
                
                queue<pair<int,pair<int,int>>> que;
                que.push({0,{y,x}});
                visited[y][x]=true;
            
                while(!que.empty())
                {
                    int len=que.front().first;
                    int cy=que.front().second.first;
                    int cx=que.front().second.second;
                    que.pop();
                    
                    if(i==1)
                    {
                        cout<<cy<<" "<<cx<<" "<<places[1][cy][cx]<<"\n";
                    }
                    
                    if(len!=0 && places[i][cy][cx]=='P')
                    {
                        isSafe=false;
                        break;
                    }
                    
                    if(len==2)  continue;
                    
                    for(int k=0;k<4;k++)
                    {
                        int ny=cy+dy[k];
                        int nx=cx+dx[k];
                        
                        if(ny<0||ny>=5||nx<0||nx>=5)    continue;
                        if(places[i][ny][nx]=='X')  continue;
                        if(visited[ny][nx]) continue;
                        
                        visited[ny][nx]=true;
                        que.push({len+1,{ny,nx}});
                    }
                }
            }
            if(!isSafe) break;
        }
        if(isSafe)
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    return answer;
}