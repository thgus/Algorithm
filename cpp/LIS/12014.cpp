/*
12014번: 주식
https://www.acmicpc.net/problem/12014
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int t;
int n,k;
vector<int> stock(MAX);

bool solve();

void initialize()
{  
    cin>>t;
    for(int s=1;s<=t;s++){
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> stock[i];
        }

        cout<<"Case #"<<s<<"\n"<<solve()<<"\n";
    }

}

bool solve()
{
    vector<int> seq(MAX);
    seq[0]=stock[0];

    int len=1;
    for(int i=1;i<n;i++){
        int cur=stock[i];
        if(seq[len-1]<cur){
            seq[len++]=cur;
        }
        else{
            int index=lower_bound(seq.begin(),seq.begin()+len,cur)-seq.begin();
            seq[index]=cur;
        }
    }
    
    bool isBuy;
    (len>=k)?isBuy=true:isBuy=false;
    return isBuy;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}