/*
2138번: 전구와 스위치
https://www.acmicpc.net/problem/2138
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
string b;
string g;

void initialize()
{
    cin>>n;
    cin>>b;
    cin>>g;
}

void change(string &str, int m){
    int left=m-1;
    if(left>=0){
        str[left]=(str[left]=='0')?'1':'0';
    }
    str[m]=(str[m]=='0')?'1':'0';
    int rihgt=m+1;
    if(rihgt<n){
        str[rihgt]=(str[rihgt]=='0')?'1':'0';
    }
}

void solve()
{   
    string str1=b;
    int sum1=0;
    for(int i=1;i<n;i++){
        if(str1[i-1]!=g[i-1]){
            change(str1,i);
            sum1++;
        }
    }

    string str2=b;
    change(str2,0);
    int sum2=1;
    for(int i=1;i<n;i++){
        if(str2[i-1]!=g[i-1]){
            change(str2,i);
            sum2++;
        }
    }

    if(str1[n-1]==g[n-1]){
        cout<<sum1;
    }
    else if(str2[n-1]==g[n-1]){
        cout<<sum2;
    }
    else{
        cout<<"-1";
    }

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}