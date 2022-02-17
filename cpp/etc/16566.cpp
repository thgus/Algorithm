/*
16566번: 카드 게임
https://www.acmicpc.net/problem/16566
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 4000000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,k;
vector<int> card;
vector<int> mcard;

void initialize()
{
    cin>>n>>m>>k;
    int temp;
    for(int i=0;i<m;i++){
        cin>>temp;
        card.push_back(temp);
    }
}

vector<int> parent(MAX+1);
int findParent(int i){
    if(parent[i]==i){
        return i;
    }
    else{
        return parent[i]=findParent(parent[i]);
    }
}

void makeUnion(int a, int b){
    int ap=findParent(a);
    int bp=findParent(b);
    parent[bp]=ap;
}

void solve()
{
    sort(card.begin(),card.end());

    for(int i=0;i<=m;i++){
        parent[i]=i;
    }

    int cur;
    int startindex;
    for(int i=0;i<k;i++){
        cin>>cur;

        int curindex=upper_bound(card.begin(),card.end(),cur)-card.begin()+1;
        while(findParent(curindex)!=curindex || curindex==startindex){
            curindex++;
        }

        if(i==0){
            startindex=curindex;
        }
        else{
            makeUnion(startindex,curindex);
        }

        cout<<card[curindex]<<"\n";
    }

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}