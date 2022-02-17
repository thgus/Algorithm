/*
2470번: 두 용액
https://www.acmicpc.net/problem/2470
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
    int n;
    cin>>n;

    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    
    int left=0;
    int right=n-1;

    int result=2000000001;
    int mleft, mright;
    while(left<right){
        int sum=vec[right]+vec[left];
        
        if(result>abs(sum)){
            mleft=left;
            mright=right;
            result=abs(sum);
        }

        if(sum<0){
            left++;
        }
        else if(sum>0){
            right--;
        }
        else{
            break;
        }
    }
    cout<<vec[mleft]<<" "<<vec[mright]<<"\n";

    return 0;
}