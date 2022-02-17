/*
10253번: 헨리
https://www.acmicpc.net/problem/10253
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

long long gcd(long long a, long long b){
    long long c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

long long solve(long long a, long long b)
{
    while(a!=1){
        long long  d=b/a+1;

        long long g=gcd(b,d);
        long long lcm=(b*d)/g;

        a=(a*(lcm/b))-((lcm/d));
        b=lcm;

		long long ab = gcd(a, b);
		a /= ab;
		b /= ab;
    }

    return b;
}

void initialize()
{
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<"\n";
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}