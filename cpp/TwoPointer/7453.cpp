/*
7453번: 합이 0인 네 정수
https://www.acmicpc.net/problem/7453
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 4000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec1(MAX);
vector<int> vec2(MAX);
vector<int> vec3(MAX);
vector<int> vec4(MAX);
void initialize()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vec1[i]>>vec2[i]>>vec3[i]>>vec4[i];
    }
}

void solve()
{
    vector<int> arr1;
    vector<int> arr2;

    int sum;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum=vec1[i]+vec2[j];
            arr1.push_back(sum);
            sum=vec3[i]+vec4[j];
            arr2.push_back(sum);
        }
    }
    sort(arr2.begin(),arr2.end());


    int left=0;
    int right=arr1.size()-1;

    long long cnt=0;
    for(int i=0;i<arr1.size();i++){
        int cur=arr1[i];
        int upb=upper_bound(arr2.begin(),arr2.end(),-cur)-arr2.begin();
        int lob=lower_bound(arr2.begin(),arr2.end(),-cur)-arr2.begin();

        if(upb>lob){
            cnt+=(upb-lob);
        }
    }

    cout<<cnt;

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}