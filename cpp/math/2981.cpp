/*
2981번: 검문
https://www.acmicpc.net/problem/2981

https://st-lab.tistory.com/155 
이런류의 문제도 많이 풀어봐야 할 것 같다.

v[i] - v[i - 1] = m * (temp[i] - temp[i-1]) + (r - r)
출처: https://jaimemin.tistory.com/1251 [꾸준함]
m이 v[i]-v[i-1]의 약수가 되면 v[i]-v[i-1]=m*(temp[i]-temp[i-1])이 된다.
이러면 (r-r)=0이 된 것이므로 v[i]-v[i-1]의 약수가 되는 m이 나머지가 같게 되는 경우라고 볼 수 있다-> 문제 요구사항 충족
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec;

void initialize()
{
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }    
}

int get_gcd(int a, int b){
    if(a<b){
        int temp=a;
        a=b;
        b=temp;
    }

    while(b>0){
        int temp=a;
        a=b;
        b=temp%b;
    }

    return a;
}

void get_common_factor(set<int> &result, int a){
    result.insert(a);
    for(int i=2;i<=a/2;i++){
        if(a%i==0){
            result.insert(i);
        }
    }
}

void solve()
{
    set<int> result;

    int a=abs(vec[0]-vec[1]);
    int b;

    for(int i=1;i<n-1;i++){
        b=abs(vec[i]-vec[i+1]);
        a=get_gcd(a,b);
    }
    get_common_factor(result,a);

    for(auto it=result.begin();it!=result.end();it++){
        cout<<*it<<" ";
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}