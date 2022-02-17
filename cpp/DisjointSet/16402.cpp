/*
16402번: 제국
https://www.acmicpc.net/problem/16402
*/

#include <iostream>
#include <vector>
#include <map>
#include <cstring>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;

int findParent(vector<int> &parent, int i){
    if(parent[i]==i){
        return i;
    }
    else{
        return parent[i]=findParent(parent,parent[i]);
    }
}

void solve()
{
    scanf("%d%d",&n,&m);
    getchar();

    char str[21];
    map<string,int> strtint;
    for(int i=0;i<n;i++){
        scanf("%[^\n]",str);
        getchar();
        strtint.insert({str,i});
    }

    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    char wstr[60];
    for(int i=0;i<m;i++){
        scanf("%[^\n]",wstr);
        char *temp=strtok(wstr,",");
        
        char w[2][21];  int win;
        strcpy(w[0],temp);  temp=strtok(NULL,",");
        strcpy(w[1],temp);  temp=strtok(NULL,",");
        win=atoi(temp);

        int aindex=strtint.find(w[0])->second;
        int bindex=strtint.find(w[1])->second;

        int aParent=findParent(parent,aindex);
        int bParent=findParent(parent,bindex);

        if(aParent==bParent){
            (win==1)?parent[bindex]=parent[aindex]=aindex:parent[aindex]=parent[bindex]=bindex;
        }
        else{
            (win==1)?parent[bParent]=aParent:parent[aParent]=bParent;
        }

        getchar();
    }

    vector<string> vec;
    for(auto it=strtint.begin();it!=strtint.end();it++){
        int curindex=it->second;
        if(findParent(parent,curindex)==curindex){
            vec.push_back(it->first);
        }
    }

    cout<<vec.size()<<"\n";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"\n";
    }
    
}

int main()
{
    //sync_off;
    solve();

    return 0;
}