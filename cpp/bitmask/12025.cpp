/*
12025번: 장난꾸러기 영훈
https://www.acmicpc.net/problem/12025
*/

#include <iostream>
#include <vector>
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

string str;
long long k;

void initialize()
{
    cin>>str;
    cin>>k;
}

void solve()
{
    for(int i=0;i<str.size();i++){
        if(str[i]=='6'||str[i]=='7'){
            //6이라면 1로, 7이라면 2로 바꿔줌
            str[i]-=5;
        }
    }

    long long n=1;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]=='1'||str[i]=='2'){
            if((k-1)&n){
                str[i]+=5;
            }
            n*=2;
        }
    }

    cout<<(n<k?"-1":str);
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}