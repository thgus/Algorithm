/*
2848번: 알고스팟어
https://www.acmicpc.net/problem/2848
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<string> vec;
vector<int> alphabet(26,0);

void initialize()
{
    cin>>n;
    vec.resize(n);

    for(int i=0;i<n;i++){
        cin>>vec[i];

        for(int j=0;j<vec[i].size();j++){
            alphabet[vec[i][j]-'a']=1;
        }
    }
}

void solve()
{
    //vector<vector<int>> route(26);
    vector<vector<bool>> route(26,vector<bool>(26,false));
    vector<int> waiting(26,0);

    for(int i=0;i<n-1;i++){
        string str1=vec[i];
        string str2=vec[i+1];

        int index=0;
        while(str1[index]==str2[index]){
            index++;
        }
        int c1=str1[index]-'a';
        int c2=str2[index]-'a';

        route[c1][c2]=true;
        waiting[c2]++;
    }    

    queue<int> que;
    for(int i=0;i<26;i++){
        if(alphabet[i]==1 && waiting[i]==0){
            alphabet[i]==2;
            que.push(i);
        }
    }

    vector<char> result;
    while(!que.empty()){
        int cur=que.front();
        que.pop();

        if(!que.empty()){
            cout<<"?";
            return;
        }
        alphabet[cur]=2;
        result.push_back(cur+'a');

        for(int next=0;next<26;next++){
            if(!route[cur][next])   continue;

            waiting[next]--;
            if(waiting[next]==0){
                que.push({next});
            }
        }
    }

    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}