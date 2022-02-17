/*
10775번: 공항
https://www.acmicpc.net/problem/10775
*/

#include <iostream>
#include <vector>
#include <set>

#define MAX 100000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;


int main()
{
    sync_off;

    int g,p;
    cin>>g>>p;
    
    set<int> s;
    
    for(int i=1;i<=g+1;i++){
        s.insert(i);
    }

    int cur;
    int result=0;
    while(p--){
        cin>>cur;

        auto it=s.upper_bound(cur);
        if(it==s.begin()){
            break;
        }
        else{
            s.erase(--it);
            result++;
        }
    }

    cout<<result;


    return 0;
}