/*
1759번: 암호 만들기
https://www.acmicpc.net/problem/1759
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int l,c;
vector<char> vec;

void initialize()
{
    cin>>l>>c;
    vec.resize(c);
    for(int i=0;i<c;i++){
        cin>>vec[i];
    }
}

int check(vector<char> &result){
    int a,b;
    a=b=0;
    for(char ch:result){
         if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
             a++;
         }
         else{
             b++;
         }
    }

    if(a>=1&&b>=2){
        return true;
    }
    else{
        return false;
    }
}

void dfs(vector<bool> &visited, vector<char> &result,int len, int last_index){
    if(len==l){
        if(check(result)){
            for(char ch:result) cout<<ch;
            cout<<"\n";
        }
        return;
    }

    for(int i=last_index;i<c;i++){
        if(visited[i])  continue;

        visited[i]=true;
        result[len]=vec[i];
        dfs(visited,result,len+1,i+1);
        visited[i]=false;
    }
}

void solve()
{
    vector<bool> visited(c,false);
    vector<char> result(l);

    sort(vec.begin(),vec.end());
    dfs(visited,result,0,0);
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}