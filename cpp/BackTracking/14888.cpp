/*
14888번: 연산자 끼워넣기
https://www.acmicpc.net/problem/14888
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<long long> a;
vector<char> op;

void initialize()
{
    cin>>n;
    int num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        a.push_back(num);
    }

    char arr[4]={'+','-','*','/'};
    for(int i=0;i<4;i++)
    {
        cin>>num;
        for(int j=0;j<num;j++)
        {
            op.push_back(arr[i]);
        }
    }
}

void backtracking(long long cal, vector<bool> &used, long long &min_cal, long long &max_cal ,int seq)
{
    if(seq==n-1)
    {
        min_cal=min(min_cal,cal);
        max_cal=max(max_cal,cal);
        return;
    }

    for(int i=0;i<n-1;i++)
    {
        if(used[i]) continue;

        used[i]=true;
        switch (op[i])
        {
        case '+':
            backtracking(cal+a[seq+1],used,min_cal,max_cal,seq+1);
            break;
        case '-':
            backtracking(cal-a[seq+1],used,min_cal,max_cal,seq+1);
            break;
        case '*':
            backtracking(cal*a[seq+1],used,min_cal,max_cal,seq+1);
            break;
        case '/':
            backtracking(cal/a[seq+1],used,min_cal,max_cal,seq+1);
            break;
        }
        used[i]=false;
    }
}

void solve()
{
    long long min_cal=LLONG_MAX;
    long long max_cal=LLONG_MIN;
    vector<bool> used(n-1,false);

    long long cal=a[0];
    backtracking(cal,used,min_cal,max_cal,0);

    cout<<max_cal<<"\n"<<min_cal;
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}