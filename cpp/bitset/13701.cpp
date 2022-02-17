/*
13701번: 중복 제거
https://www.acmicpc.net/problem/13701
*/

#include <iostream>
#include <vector>
#include <stack>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

string str;

int recursion(int &index){
    int len=0;
    while(index++<str.size()){
        char cur=str[index];
        if(cur=='('){
            int mul=str[index-1]-'0';
            int result=recursion(index);
            len--;
            len+=mul*result;
        }
        else if(cur==')'){
            return len;
        }
        else{
            len++;
        }
    }

    return len;
}

int main()
{
    sync_off;
    cin>>str;
    
    int start=0;
    cout<<recursion(start);
    return 0;
}