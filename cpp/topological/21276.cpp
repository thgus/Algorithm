/*
21276번: 계보 복원가 호석
https://www.acmicpc.net/problem/21276
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<int>> child;
vector<string> name;
vector<int> topology;
map<string,int> string_index;

void initialize()
{
    cin>>n;
    name.resize(n);

    for(int i=0;i<n;i++){
        cin>>name[i];
    }

    sort(name.begin(),name.end());

    for(int i=0;i<n;i++){
        string_index.insert({name[i],i});
    }

    topology.resize(n);
    child.resize(n);

    cin>>m;

    string temp1,temp2;
    for(int i=0;i<m;i++){
        cin>>temp1>>temp2;
        auto it1=string_index.find(temp1);
        auto it2=string_index.find(temp2);

        topology[it1->second]++;
        child[it2->second].push_back(it1->second);
    }
}

void solve()
{
    int start_sum=0;
    vector<string> start_str;
    queue<int> que;

    for(int i=0;i<n;i++){
        if(topology[i]==0){
            start_sum++;
            start_str.push_back(name[i]);
            que.push(i);

            topology[i]=-1;
        }   
    }

    vector<vector<int>> result(n);

    while(!que.empty()){
        int cur=que.front();
        que.pop();

        for(int i=0;i<child[cur].size();i++){
            int next=child[cur][i];
            if(--topology[next]==0){
                que.push(next);
                result[cur].push_back(next);
            }
        }
    }

    cout<<start_sum<<"\n";
    for(int i=0;i<start_str.size();i++){
        cout<<start_str[i]<<" ";
    }
    cout<<"\n";
    for(auto it=string_index.begin();it!=string_index.end();it++){
        string cur_string=it->first;
        int cur_index=it->second;

        cout<<cur_string<<" "<<result[cur_index].size()<<" ";
        sort(result[cur_index].begin(),result[cur_index].end());
        for(int i=0;i<result[cur_index].size();i++){
            cout<<name[result[cur_index][i]]<<" ";
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