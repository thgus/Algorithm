/*
9527번: 1의 개수 세기
https://www.acmicpc.net/problem/9527
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

#define BITMAX 55
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

long long a,b;

void initialize()
{
    cin>>a>>b;
}

long long calSum(long long s){
    //0부터 시작하므로 갯수 1 증가
    s++;

    long long sum=0;
    long long cycle=1;

    long long x=s;
    long long i=1;

    while(x){
        cycle*=2;

        long long share=(s/cycle);
        long long rest=s%cycle;

        sum+=share*i;
        long long restone=rest-(cycle/2);
        if(restone>0){
            sum+=restone;
        }

        x>>=1;
        i<<=1;
    }

    return sum;
}

void solve()
{
    cout<<calSum(b)-calSum(a-1);
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}