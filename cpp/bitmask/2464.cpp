/*
2464번: 비밀번호
https://www.acmicpc.net/problem/2464

https://www.acmicpc.net/board/view/41421
*/

#include <iostream>
#include <vector>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    sync_off;

    long long a;
    cin>>a;

    int max_len=log2(a)+1;

    long long presult=0;
    int pone=0;
    for(long long i=0;i<max_len;i++){
        if(~a&((long long)1<<i)&&a&((long long)1<<i+1)){
            presult=a;
            presult|=((long long)1<<(i));
            presult&=(~((long long)1<<i+1));

            for(long long j=i-1;j>=0;j--){
                if((pone--)>0){
                    presult|=((long long)1<<j);
                }
                else{
                    presult&=(~((long long)1<<j));
                }
            }
            break;
        }
        else if(a&((long long)1<<i)){
            pone++;
        }
    }

    long long nresult=0;
    int none=0;
    for(long long i=0;i<max_len;i++){
        if(~a&((long long)1<<i+1)&&(a&((long long)1<<i))){
            nresult=a;
            nresult&=(~((long long)1<<i));
            nresult|=((long long)1<<i+1);
            for(long long j=0;j<i;j++){
                if((none--)>0){
                    nresult|=((long long)1<<j);
                }
                else{
                    nresult&=(~((long long)1<<j));
                }
            }
            break;
        }
        else if(a&((long long)1<<i)){
            none++;
        }
    }

    cout<<presult<<" "<<nresult;

    return 0;
}