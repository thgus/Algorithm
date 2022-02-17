/*
1254번: 팰린드롬 만들기
https://www.acmicpc.net/problem/1254
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

string str;
void initialize()
{
    cin>>str;
}

void solve()
{
    for(int i=0;i<str.size();i++){
        
        bool isPalindrome=true;
        for(int j=i;j<(str.size()+i)/2;j++){
            if(str[j]!=str[str.size()-1-(j-i)]){
                isPalindrome=false;
                break;
            }
        }

        if(isPalindrome){
            cout<<str.size()+i;
            break;
        }
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}