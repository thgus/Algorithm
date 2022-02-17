/*
2276번: 물 채우기
https://www.acmicpc.net/problem/2276
*/

#include <iostream>
#include <vector>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

long long k;
void initialize()
{
    cin>>k;
}

void solve()
{
    if(k==1){
        cout<<"4";
        return;
    }

    if(k==2){
        cout<<"7";
        return;
    }

    int len=1;
    long long pow=2;
    long long n=2;
    while(k>n){
        len++;
        pow*=2;
        n+=pow;
    }
    n-=pow;
    n=k-n;
    n--;

    vector<char> vec(len);
    for(int i=0;i<len;i++){
        if(~n&(1<<i)){
            vec[len-1-i]='4';
        }
        else{
            vec[len-1-i]='7';
        }
    }

    for(int i=0;i<len;i++){
        cout<<vec[i];
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}