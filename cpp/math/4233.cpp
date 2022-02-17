/*
4233번: 가짜소수
https://www.acmicpc.net/problem/4233
*/

#include <iostream>
#include <vector>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

bool isPrime(long long p){
    if(p<=1)    return false;
    for(int i=2;i*i<=p;i++){
        if(p%i==0){
            return false;
        }
    }
    return true;
}

bool solve(long long a, long long p)
{
    int save_a=a;
    long long ret=1;
    long long mod=p;

    // 한번에 나머지를 구하지 않고
    // 거듭제곱을 하면서 나머지를 구해도 결과에 지장을 주지 않는 이유는?
    // 내 생각) 이미 만약 5를 3으로 나눈다고 할 때
    //      5의 제곱은 5*5*5*5*5이다. 
    //      이는(3+2)*(3+2)*(3+2)*(3+2)*(3+2)로 나타낼 수 있고 3으로 나눈 나머지 결과값은
    //      (3+2)*(3+2)*(3+2)*(3+2)*(3+2)/3=2*2*2*2*2= 2^5
    //      5를 3으로 나눈 나머지의 결과값과 같아진다.
    while(p){
        if(p&1){
            ret=(ret*a)%mod;
        }
        a=(a*a)%mod;
        p/=2;
    }
    
    //a와 a^p의 나머지가 a라면
    if(ret==save_a){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    sync_off;
    
    int a,p;
    while(1){
        cin>>p>>a;
        if(a==0||p==0){
            break;
        }
        
        //p가 소수가 아닌데
        //a를 제곱한 뒤, p로 나눴을 때, 나머지가 a가 된다면
        if(!isPrime(p)&&solve(a,p)){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }

    return 0;
}