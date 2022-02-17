/*
2531번: 회전 초밥
https://www.acmicpc.net/problem/2531
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,d,k,c;
vector<int> vec;

void initialize()
{
    cin>>n>>d>>k>>c;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}

void solve()
{
    vector<int> choose(d+1,0);

    int cur_len=1;
    choose[c]=1;

    for(int i=0;i<k;i++){
        int cur_sushi=vec[i];
        if(choose[cur_sushi]==0){
            cur_len++;
        }
        choose[cur_sushi]++;
    }

    int max_len=cur_len;
    int left=0,right=k-1;
    while(left!=n-1){
        right++;
        if(right%n==0)  right=0;
        
        int r_sushi=vec[right];
        if(choose[r_sushi]==0)  cur_len++;
        choose[r_sushi]++;

        int l_sushi=vec[left];
        choose[l_sushi]--;
        if(choose[l_sushi]==0)  cur_len--;
        left++;

        max_len=max(max_len,cur_len);
    }

    cout<<max_len;

}   

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}