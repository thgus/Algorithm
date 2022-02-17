/*
9935번: 문자열 폭발
https://www.acmicpc.net/problem/9935
*/

#include <iostream>
#include <vector>
#include <stack>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

string str, boom;

void initialize()
{
    cin>>str;
    cin>>boom;
}

void solve()
{
    string s;
    
    for(int i=0;i<str.size();i++){
        s+=str[i];
        if(s.size()<boom.size()){
            continue;
        }

        bool isBoom=true;
        for(int j=0;j<boom.size();j++){
            if(s[s.size()-1-j]!=boom[boom.size()-1-j]){
                isBoom=false;
                break;
            }
        }

        if(isBoom){
            for(int j=0;j<boom.size();j++){
                s.pop_back();
            }
        }
    }
    if(s.size()>0){
        cout<<s;
    }
    else{
        cout<<"FRULA";
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}