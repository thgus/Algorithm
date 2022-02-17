/*
21758번: 꿀 따기
https://www.acmicpc.net/problem/21758
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
vector<int> vec;

void initialize()
{
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}

void solve()
{
    vector<long long> sum1(n);
    vector<long long> sum2(n);

    sum1[0]=vec[0];
    sum2[n-1]=vec[n-1];
    for(int i=1;i<n;i++){
        sum1[i]=sum1[i-1]+(long long)vec[i];
        sum2[n-1-i]=sum2[n-i]+(long long)vec[n-1-i];
    }

    long long result=-1;
    for(int i=0;i<n;i++){
        result=max(result,sum1[i]+sum2[i]-vec[0]-vec[n-1]);
    }
    for(int i=1;i<n;i++){
        result=max(result,sum1[n-1]*2-sum1[i]-vec[i]-vec[0]);
    }
    for(int i=n-2;i>=0;i--){
        result=max(result,sum2[0]*2-sum2[i]-vec[i]-vec[n-1]);
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