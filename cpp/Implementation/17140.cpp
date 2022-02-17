/*
17140번: 이차원 배열과 연산
https://www.acmicpc.net/problem/17140
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define MAX 100
#define ARR_MAX 105
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r,c,k;
int arr[ARR_MAX][ARR_MAX];

int r_len,c_len;

void initialize()
{
    r_len=c_len=3;

    cin>>r>>c>>k;
    r--,c--;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
}

void print_arr()
{
    cout<<"\n";
    for(int i=0;i<r_len;i++)
    {
        for(int j=0;j<c_len;j++)
        {
            cout<<arr[i][j]<<" "; 
        }
        cout<<"\n";
    }
}

struct Node
{
    int first,second;

    bool operator<(const Node n)const{
        if(first==n.first)
        {
            return second<n.second;
        }
        return first<n.first;
    }
};

void sort_r()
{
    int nc_len=-1; 
    int temp[ARR_MAX];
   
    for(int i=0;i<r_len;i++){
        memset(temp,0,sizeof(int)*ARR_MAX);
        for(int j=0;j<c_len;j++)
        {
            int cur=arr[i][j];
            if(cur==0)  continue;
            temp[cur-1]++;
        }

        vector<Node> vec;
        for(int j=0;j<MAX;j++)
        {
            if(temp[j]==0)   continue;
            vec.push_back({temp[j],j+1});
        }
        sort(vec.begin(),vec.end());
    
        int j;
        memset(arr[i],0,sizeof(int)*ARR_MAX);
        for(j=0;j<vec.size()&&j<MAX/2;j++)
        {
            arr[i][j*2]=vec[j].second;
            arr[i][j*2+1]=vec[j].first;
        }

        nc_len=max(nc_len,(j*2));
    }

    for(int i=r_len;i<ARR_MAX;i++)
    {
        memset(arr[i],0,sizeof(int)*ARR_MAX);
    }

    c_len=nc_len;
    //print_arr();
}

void sort_c()
{ 
    int nr_len=-1; 
    int temp[ARR_MAX];
   
    for(int i=0;i<c_len;i++){
        memset(temp,0,sizeof(int)*ARR_MAX);
        for(int j=0;j<r_len;j++)
        {
            int cur=arr[j][i];
            if(cur==0)  continue;
            temp[cur-1]++;
        }

        vector<Node> vec;
        for(int j=0;j<MAX;j++)
        {
            if(temp[j]==0)   continue;
            vec.push_back({temp[j],j+1});
        }
        sort(vec.begin(),vec.end());
    
        int j;
        for(int j=0;j<ARR_MAX;j++)  arr[j][i]=0;
        for(j=0;j<vec.size()&&j<MAX/2;j++)
        {
            arr[j*2][i]=vec[j].second;
            arr[j*2+1][i]=vec[j].first;
        }

        nr_len=max(nr_len,(j*2));
    }

    for(int i=c_len;i<ARR_MAX;i++)
    {
        for(int j=0;j<ARR_MAX;j++)  arr[j][i]=0;
    }

    r_len=nr_len;
    //print_arr();
}

void solve()
{
    int time=0;
    while(arr[r][c]!=k)
    {
        if(time>MAX){
            time=-1;
            break;
        }    
        time++;

        if(r_len>=c_len)        sort_r();
        else if(r_len<c_len)    sort_c();                
    }

    cout<<time;
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}