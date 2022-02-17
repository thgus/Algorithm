/*
21943번: 연산 최대로
https://www.acmicpc.net/problem/21943
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec;
int p,q;

void initialize()
{
    cin>>n;

    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cin>>p>>q;
}

int max_result=-1;
void back_tracking(vector<int> &index, int start){
    if(index.size()==q){
        index.push_back(n-1);
        int result=1;
        int js=0;

        for(int i=0;i<=q;i++){
            int sum=0;
            for(int j=js;j<=index[i];j++){
                sum+=vec[j];
            }
            js=index[i]+1;
                        result*=sum;
        }
        max_result=max(max_result,result);
        index.pop_back();
        return;
    }

    for(int i=start;i<n-1;i++){
        index.push_back(i);
        back_tracking(index,i+1);
        index.pop_back();
    }
}

void solve()
{
    vector<int> index;
    sort(vec.begin(),vec.end());
    do{
        back_tracking(index,0);
    }while(next_permutation(vec.begin(),vec.end()));

    cout<<max_result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}