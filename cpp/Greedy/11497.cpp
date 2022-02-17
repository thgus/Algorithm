/*
11497번: 통나무 건너뛰기
https://www.acmicpc.net/problem/11497

차이가 가장 작게 되기 위해서는 작은 값은 작은값끼리 큰 값은 큰 값끼리 이웃해주게 하면 된다.
만약 맨 처음 값과 마지막 값의 차이를 고려하지 않는다면 그냥 정렬하면 되지만 이 문제는 맨 처음 값과 마지막 값의 차이도 고려를 해야 한다. 
왼쪽, 오른쪽을 번갈아가면서 차례대로 작은 수 들을 넣어주면
정규분포와 같은 형태를 띄게 되는데 이 때 양 옆의 차가 가장 작아진다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    sync_off;
    int t;
    cin>>t;
    
    int n,temp;
    while(t--){
        vector<int> vec;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>temp;
            vec.push_back(temp);
        }

        sort(vec.begin(),vec.end());
        int max_sub=-1;

        vector<int> seq(n);
        for(int i=0;i<n;i++){
            if(i%2==0){
                seq[i/2]=vec[i];
            }
            else{
                seq[n-1-(i/2)]=vec[i];
            }
        }        

        int result=0;
        for(int i=0;i<n;i++){
            result=max(result,abs(seq[i]-seq[(i+1)%n]));
        }
        cout<<result<<"\n";
    }

    return 0;
}