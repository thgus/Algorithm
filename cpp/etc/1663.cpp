/*
1663번: XYZ문자열
https://www.acmicpc.net/problem/1663
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int k,n;

void cal_sum(vector<long long> &sum, long long x, long long y, long long z, long long len)
{
    sum.resize(n+1);
    sum[1]=len;

    long long tx,ty,tz;
    for(int i=2;i<=n;i++){
        len=len-x+x*2;  
        tx=x;   ty=y;   tz=z;
        x=tz;   y=tx;   z=ty+tx;
        sum[i]=len;
    }
}

void cal_sum(long long &x, long long &y, long long &z)
{
    long long tx,ty,tz;
    for(int i=2;i<=n;i++){
        tx=x;   ty=y;   tz=z;
        x=tz;   y=tx;   z=ty+tx;    
    }
}

void cal_sum(long long x, long long y, long long z, long long &len)
{
    long long tx,ty,tz;
    for(int i=2;i<=n;i++){
        len=len-x+x*2;

        tx=x;   ty=y;   tz=z;
        x=tz;   y=tx;   z=ty+tx;
    }
}

void solve1(){
    long long len=1;
    cal_sum(1,0,0,len);
    cout<<len;
}

void solve2(){
    long long goal;
    cin>>goal;

    char cur='X';
    vector<long long> xsum;
    vector<long long> ysum;
    vector<long long> zsum;

    cal_sum(xsum,1,0,0,1);
    cal_sum(ysum,0,1,0,1);
    cal_sum(zsum,0,0,1,1);

    long long start=1;
    long long end=xsum[n];
    for(int i=1;i<n;i++){
        if(cur=='X'){
            long long y_end=start+ysum[n-i]-1;
            if(goal>=start&&goal<=y_end){
                end=y_end;
                cur='Y';
            }
            else{
                start=y_end+1;
                cur='Z';
            }
        }
        else if(cur=='Y'){
            cur='Z';
        }
        else if(cur=='Z'){
            cur='X';
        }
    }
    cout<<cur;
}

void solve3()
{
    char c;
    cin >> c;

    long long x,y,z;
    x=1;
    y=z=0;
    cal_sum(x,y,z);

    if (c == 'X')
    {
        cout<<x;
    }
    else if (c == 'Y')
    {
        cout << y;
    }
    else if (c == 'Z')
    {
        cout << z;
    }
}

void solve()
{    
    switch(k){
        case 1:
            solve1();
            break;
        case 2:
            solve2();
            break;
        case 3:
            solve3();
            break;
    }

}

void initialize()
{
    cin>>k>>n;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}