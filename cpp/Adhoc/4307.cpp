/*
4307번: 개미
https://www.acmicpc.net/problem/4307
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

    int l,n;
    vector<int> vec;
    while(t--){
        vec.clear();

        cin>>l>>n;  
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            vec.push_back(temp);
        }  
        sort(vec.begin(),vec.end());

        int min_time=0;
        double ml=l/2;
        for(int cur:vec){
            if(cur<ml){
                min_time=max(min_time,cur);
            }
            else if(cur==ml){
                if(cur==l)  continue;
                min_time=max(min_time,cur);
            }
            else{
                min_time=max(min_time,l-cur);
            }
        }

        double max_time=0;
        double left=vec[0];

        for(int i=1;i<vec.size();i++){
            double right=vec[i]-max_time;
            double mid=(left+right)/2;

            max_time+=(mid-left);
            left=mid;
        }
        max_time+=max(left,l-left);

        cout<<min_time<<" "<<max_time<<"\n";
    }

    return 0;
}