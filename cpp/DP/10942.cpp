/*
10942번: 팰린드롬?
https://www.acmicpc.net/problem/10942
*/

#include <iostream>
#include <vector>

#define MAX 2000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> num(MAX+1);
vector<vector<bool>> isPalindrome(MAX+1,vector<bool>(MAX+1));

void solve();

void initialize()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }

    solve();

    int m;
    cin>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        cout<<isPalindrome[a][b]<<"\n";
    }
}

void solve()
{
    for(int i=1;i<=n;i++){
        isPalindrome[i][i]=true;
    }

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int left=i+1;
            int right=i+len;

            bool palindrom=false;
            if(num[left]==num[right]){
                if(left+1<=right-1){
                    if(isPalindrome[left+1][right-1]){
                        palindrom=true;
                    }
                }
                else{
                    palindrom=true;
                }
            }
            isPalindrome[left][right]=palindrom;
        }
    }
    
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<isPalindrome[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
}

int main()
{
    sync_off;
    initialize();

    return 0;
}