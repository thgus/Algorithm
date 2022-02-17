/*
1016번: 제곱 ㄴㄴ 수
https://www.acmicpc.net/problem/1016
*/

#include <iostream>
#include <vector>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

long long minNum, maxNum;

void initialize()
{
    cin>>minNum>>maxNum;
}

void solve()
{
    long long vecSize=maxNum-minNum+1;
    vector<bool> check(vecSize,false);
    
    long long maxSqrNum=sqrt(maxNum);
    for(long long i=2;i<=maxSqrNum;i++){
        long long curSqr=i*i;
        //cout<<curSqr<<"\n";

        long long curNum=(minNum/curSqr)*curSqr;
        if(curNum==minNum){
            check[0]=true;
        }

        curNum+=curSqr;
        while(curNum<=maxNum){
            check[curNum-minNum]=true;
            curNum+=curSqr;
        }
    }

    long long result=0;
    for(long long i=0;i<vecSize;i++){
        if(!check[i]){
            result++;
        }
    }
    cout<<result;
}

int main()
{
    initialize();
    solve();

    return 0;
}