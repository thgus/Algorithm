#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

struct Node
{
    int time;
    int num;
    int traps_bit;
    bool operator<(const Node n) const
    {
        return time>n.time;
    }
};

pair<bool,bool> check_bit(vector<int> &traps, int bit, int cnum, int nnum)
{
    bool first=false;
    bool second=false;
    
    if(traps[cnum]>=0)
    {
        if(bit&(1<<traps[cnum]))  first=true;
    }
    if(traps[nnum]>=0)
    {
        if(bit&(1<<traps[nnum]))  second=true;
    }

    return {first,second};
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    vector<vector<pair<int,int>>> c_road(n+1);
    vector<vector<pair<int,int>>> b_road(n+1);
    
    for(int i=0;i<roads.size();i++)
    {
        int p=roads[i][0],q=roads[i][1],s=roads[i][2];
        c_road[p].push_back({q,s});
        b_road[q].push_back({p,s});
    }
    
    // trap으로 인해서 방향이 바뀌었을 경우를 생각을 못했다;
    // vector<int> visited(n+1,INT_MAX);
    vector<vector<int>> visited(1<<traps.size(),vector<int>(n+1,INT_MAX));
    
    // 앟 이거 처리를 안해줬다. 
    // 한번 activate되면 이후 상관없는 case에서도 이럴거아냐;;
    // bit로 변경
    vector<bool> activate(n+1,false);
    priority_queue<Node> pq;
    pq.push({0,start,0});
    
    visited[0][start]=0;
    
    vector<int> trap_index(n+1,-1);
    for(int i=0;i<traps.size();i++)
    {
        trap_index[traps[i]]=i;
    }
    
    while(!pq.empty())
    {
        int ctime=pq.top().time;
        int cnum=pq.top().num;
        int bit=pq.top().traps_bit;
        pq.pop();
        
        if(visited[bit][cnum]>ctime)    continue;
                                
        if(cnum==end)
        {
            answer=ctime;
            break;
        }
                
        if(trap_index[cnum]>=0){
            int i=trap_index[cnum];
            
            if(bit&(1<<i))
            {
                bit&=~(1<<i);
            }
            else
            {
                bit|=(1<<i);
            }
        }
                
        for(pair<int,int> next:c_road[cnum])
        {
            int nnum=next.first;
            int ntime=ctime+next.second;
            
            pair<bool,bool> isReverse=check_bit(trap_index,bit, cnum, nnum);
            if(isReverse.first&&!isReverse.second)  continue;
            if(!isReverse.first&&isReverse.second)  continue;
            
            if(visited[bit][nnum]<=ntime)   continue;
            visited[bit][nnum]=ntime;
            pq.push({ntime,nnum,bit});
        }
        for(pair<int,int> next:b_road[cnum])
        {
            int nnum=next.first;
            int ntime=ctime+next.second;
            
            pair<bool,bool> isReverse=check_bit(trap_index,bit, cnum, nnum);
            if(!isReverse.first&&!isReverse.second)  continue;
            if(isReverse.first&&isReverse.second)  continue;
            
            if(visited[bit][nnum]<=ntime)   continue;
            visited[bit][nnum]=ntime;
            pq.push({ntime,nnum,bit});
        }
    }
    
    return answer;
}