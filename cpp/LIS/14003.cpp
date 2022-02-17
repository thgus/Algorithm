/*
14003번: 가장 긴 증가하는 부분 수열 5
https://www.acmicpc.net/problem/14003
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec;

void initialize()
{
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }
}

void solve()
{
    vector<int> seq;
    vector<int> seqindex;
    vector<int> route;
    seq.push_back(vec[0]);
    seqindex.push_back(0);
    route.push_back(-1);

    int lastindex=0;

    for(int i=1;i<n;i++){
        int cur=vec[i];
        if(cur>seq.back()){
            seq.push_back(cur);
            route.push_back(seqindex.back());
            seqindex.push_back(i);
            lastindex=i;
        }
        else{
            int index=lower_bound(seq.begin(),seq.end(),cur)-seq.begin();
            seq[index]=cur;
            seqindex[index]=i;

            (index==0)?route.push_back(-1):route.push_back(seqindex[index-1]);
        }
    }

    vector<int> result;
    while(1){
        result.push_back(vec[lastindex]);
        lastindex=route[lastindex];
        if(lastindex==-1){
            break;
        }
    }

    cout<<result.size()<<"\n";
    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i]<<" ";
    }

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}