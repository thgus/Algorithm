/*
1790번: 수 이어 쓰기 2
https://www.acmicpc.net/problem/1790

101852 2889 
1000 1
999 9
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

long long n,k;
string str_k;

void initialize()
{
    cin>>n>>k;    
}

void solve()
{
    long long nine=9;
    long long num;
    long long index=0;
    
    long long digit=1;
    long long p=1;
    while(1){
        long long cur=digit*nine*pow(10,digit-1);
        long long next=index+cur;
        cout<<cur<<" "<<digit<<" "<<pow(10,digit-1)<<" "<<digit*nine*pow(10,digit-1)<<"\n";

        if(next>=k){
            long long res=k-index;
            string str="";
            for(int i=digit-1;i>=0;i--){
                long long p=(res-1)/(digit*pow(10,i));
                if(i==digit-1){
                    str+=p+'1';
                }
                else{
                    str+=p+'0';
                }
                res-= p*(digit*pow(10,i));
            }

            cout<<str<<" "<<res<<" "<<digit<<"\n";
            char result=str[(res-1)%digit];
            long long res_long=stoll(str);
            if(res_long>n){
                cout<<"-1";
            }
            else{
                cout<<result;
            }
            
            break;
        }

        digit++;
        index=next;
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}