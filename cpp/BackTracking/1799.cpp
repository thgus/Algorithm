/*
1799번: 비숍
https://www.acmicpc.net/problem/1799
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<pair<int,int>> bbishop;
vector<pair<int,int>> wbishop;

void initialize()
{
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            if(temp==1){
                if((i+j)%2==0){
                    bbishop.push_back({j,i});
                }
                else{
                    wbishop.push_back({j,i});
                }
            }
        }
    }
}

int sum;
void bt(vector<pair<int,int>> bishop, vector<bool> &ld, vector<bool> &rd, int index, int cnt){
    if(sum<cnt){
        sum=cnt;
    }
    if(index==bishop.size()){
        return;
    }

    for(int cur=index;cur<bishop.size();cur++){
        if(sum>(cnt+(bishop.size()-cur))){
            break;
        }

        int y=bishop[cur].first;
        int x=bishop[cur].second;

        if(!ld[y+x]&&!rd[n-1-x+y]){
            ld[y+x]=true;
            rd[n-1-x+y]=true;
            bt(bishop,ld,rd,cur+1,cnt+1);
            ld[y+x]=false;
            rd[n-1-x+y]=false;
        }        
    }
}

void solve(){    
    vector<bool> ld(2*n-1,false);
    vector<bool> rd(2*n-1,false);

    int result=0;
    sum=0;
    bt(bbishop,ld,rd,0,0);
    result+=sum;

    sum=0;
    bt(wbishop,ld,rd,0,0);
    result+=sum;

    cout<<result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}