/*
17609번: 회문
https://www.acmicpc.net/problem/17609
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int solve(string str)
{
    int start=0;
    int end=str.size()-1;

    int jump1=0;
    while(start<=end){
        char sc=str[start];
        char ec=str[end];

        if(sc==ec){
            start++;
            end--;
        }
        else{
            jump1++;
            if(jump1==2){
                break;
            }
            start++;
        }
    }

    int jump2=0;
    start=0;
    end=str.size()-1;
    while(start<=end){
        char sc=str[start];
        char ec=str[end];

        if(sc==ec){
            start++;
            end--;
        }
        else{
            jump2++;
            if(jump2==2){
                break;
            }
            end--;
        }
    }

    return min(jump1,jump2);
}

void initialize()
{
    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        cout<<solve(str)<<"\n";
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}