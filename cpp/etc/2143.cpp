/*
2143번: 두 배열의 합
https://www.acmicpc.net/problem/2143
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int t;
int n,m;
vector<long long> A;
vector<long long> B;

void initialize()
{
    cin>>t;
    cin>>n;
    long long temp;

    for(int i=0;i<n;i++){
        cin>>temp;
        A.push_back(temp);
    }

    cin>>m;
    for(int i=0;i<m;i++){
        cin>>temp;
        B.push_back(temp);
    }

}

void makeSumArr(vector<long long> &sumArr, vector<long long> &arr){
    for(int i=0;i<arr.size();i++){
        long long sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            sumArr.push_back(sum);
        }
    }
}

void solve()
{
    vector<long long> sumA;
    vector<long long> sumB;
    makeSumArr(sumA,A);
    makeSumArr(sumB,B);

    sort(sumB.begin(),sumB.end());

    long long result=0;
    for(long long index:sumA){
        int lb=lower_bound(sumB.begin(),sumB.end(),t-index)-sumB.begin();
        int rb=upper_bound(sumB.begin(),sumB.end(),t-index)-sumB.begin();

        result+=(rb-lb);
    }

    cout<<result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}