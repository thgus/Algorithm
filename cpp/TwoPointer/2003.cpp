/*
2003번: 수들의 합 2
https://www.acmicpc.net/problem/2003
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<int> vec;

void initialize()
{
    cin >> n>>m;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        vec.push_back(temp);
    }
}

int solution(){
    int result=0;
    int left=0;
    int right=0;

    int sum=vec[0];
    //수열의 값은 항상 1보다 크므로 left를 증가시키면 값은 항상 작아지고
    //right를 증가시키면 값은 항상 커짐
    while(left<=right&&right<n){
        if(sum==m){
            result++;
            sum-=vec[left++];
            sum+=vec[++right];
        }
        else if(sum<m || left==right ){
            sum+=vec[++right];
        }
        else{
            sum-=vec[left++];
        }
    }

    return result;
}

int main()
{
    sync_off;
    initialize();
    cout<<solution();

    return 0;
}