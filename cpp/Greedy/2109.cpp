/*
2109번: 순회강연
https://www.acmicpc.net/problem/2109
*/

#include <iostream>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node{
    int p,d;
    bool operator<(const Node node) const {
        if(node.p==p){
            return d<node.d;
        }
        return node.p<p;
    }
};

int n;
vector<Node> vec;
void initialize()
{
    cin>>n;
    int p,d;
    for(int i=0;i<n;i++){
        cin>>p>>d;
        vec.push_back({p,d});
    }
}

void solve()
{
    sort(vec.begin(),vec.end());

    int max_day=10000;
    vector<bool> day_cost(max_day+1,false); 
    
    long long sum=0;
    for(int i=0;i<n;i++){
        int index=vec[i].d;
        while(index!=0&&day_cost[index]){
            index--;
        }
        if(index==0)   continue;
        day_cost[index]=true;
        sum+=vec[i].p;
    }
 
    cout<<sum;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}