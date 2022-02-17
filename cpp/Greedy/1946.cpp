/*
1946번: 신입 사원
https://www.acmicpc.net/problem/1946
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int t,n;

void initialize()
{
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> vec;
        int a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            vec.push_back({a,b});
        }
        sort(vec.begin(),vec.end());

        int num=1;
        int first_score=vec[0].second;
        for(int i=1;i<n;i++){
            if(vec[i].second<first_score){
                first_score=vec[i].second;
                num++;
            }
        }

        cout<<num<<"\n";
    }
}

void solve()
{

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}