/*
2825번: 수업시간에 교수님 몰래 교실을 나간 상근이
https://www.acmicpc.net/problem/2825
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<string> vec;

void initialize()
{
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}

long long cal_combination(int num){
    long long result=num;
    result=(result*(result-1))/2;
    return result;
}

void solve()
{
    string cur;
    vector<long long> sum(1<<10,0);
    for(int i=0;i<n;i++){
        vector<bool> visited(10,false);
        cur=vec[i];
        for(int i=0;i<cur.size();i++){
            char c=cur[i];
            visited[c-'0']=true;
        }

        int num=0;
        for(int i=0;i<10;i++){
            if(visited[i]){
                num|=(1<<i);
            }
        }
        sum[num]++;
    }
    
    long long result=0;
    for(int i=0;i<(1<<10);i++){
        result+=(sum[i]*(sum[i]-1))/2;
        for(int j=i+1;j<(1<<10);j++){
            if(i&j){
                result+=sum[i]*sum[j];
            }
        }
    }
    cout<<result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}