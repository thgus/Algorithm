/*
17406번: 배열 돌리기 4
https://www.acmicpc.net/problem/17406

벡터 떡칠해서 시간 오래걸린거 같은데 맞았으니 고칠지는 의문
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,k;
vector<vector<int>> arr;

struct Cal{
    int r,c,s;
};
vector<Cal> order;

void initialize()
{
    cin>>n>>m>>k;
    arr.resize(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    int r,c,s;
    while(k--)
    {
        cin>>r>>c>>s;
        order.push_back({r-1,c-1,s});
    }
}

void print_arr()
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void turn_arr(int sr, int sc, int er, int ec)
{   
    if(sr>=er||sc>=ec)
    {
        return;
    }
    
    turn_arr(sr+1,sc+1,er-1,ec-1);
    
    int len=er-sr;

    vector<int> choice(len);

    // 연산 할 때 마다 배열 전체를 복사하는건 좀 그런가..?
    vector<vector<int>> save=arr;  
    
    int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int start_location[4][2]={{sr,sc},{sr,ec},{er,ec},{er,sc}};

    for(int i=0;i<4;i++){
        int cy=start_location[i][0];
        int cx=start_location[i][1];

        for(int j=0;j<len;j++){
            choice[j]=arr[cy][cx];
            cy+=d[i][0], cx+=d[i][1];
        }   

        cy=start_location[i][0]+d[i][0];
        cx=start_location[i][1]+d[i][1];
        for(int j=0;j<len;j++){
            save[cy][cx]=choice[j];
            cy+=d[i][0], cx+=d[i][1];
        }
    }

    arr=save;
}

int bt(vector<int> &seq, vector<bool> &use)
{
    if(seq.size()==order.size())
    {   
        vector<vector<int>> save=arr;
        
        for(int i=0;i<seq.size();i++)
        {
            int r=order[seq[i]].r;
            int c=order[seq[i]].c;
            int s=order[seq[i]].s;

            turn_arr(r-s,c-s,r+s,c+s);
        }

        int min_sum=987654321;
        for(int i=0;i<n;i++)
        {
            int cur_sum=0;
            for(int j=0;j<m;j++)
            {
                cur_sum+=arr[i][j];
            }

            min_sum=min(min_sum,cur_sum);
        }

        arr=save;
        return min_sum;
    }

    int min_sum=987654321;
    for(int i=0;i<use.size();i++)
    {
        if(use[i])  continue;

        use[i]=true;
        seq.push_back(i);
        min_sum=min(min_sum,bt(seq,use));
        seq.pop_back();
        use[i]=false;
    }

    return min_sum;
}

void solve()
{
    vector<int> seq;
    vector<bool> use(order.size(),false);
    cout<<bt(seq,use);
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}