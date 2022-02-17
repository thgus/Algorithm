/*
1139번: 울타리
https://www.acmicpc.net/problem/1139
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

int n;
vector<double> vec;

void initialize()
{
    cin>>n;
    double temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }
}

void pick_triangle(vector<double> &dp, int bit){
    for(int i=0;i<n;i++){
        if(bit&(1<<i)) continue;
        
        for(int j=i+1;j<n;j++){
            if(bit&(1<<j))  continue;
            
            for(int k=j+1;k<n;k++){
                if(bit&(1<<k))  continue;

                int next_bit=bit+(1<<i)+(1<<j)+(1<<k);
    
                vector<double> rope={vec[i],vec[j],vec[k]};
                sort(rope.begin(),rope.end());

                if(rope[0]+rope[1]<=rope[2])    continue;

                double next_area=dp[bit];
                double p=(rope[0]+rope[1]+rope[2])/2;
                
                next_area+=sqrt(p*(p-rope[0])*(p-rope[1])*(p-rope[2]));

                if(dp[next_bit]>=next_area) continue;
                dp[next_bit]=next_area;

                pick_triangle(dp,next_bit);
            }
        }
    }
}

void solve()
{
    vector<double> dp((1<<n),0);
    pick_triangle(dp,0);

    double result=0;
    for(int i=0;i<(1<<n);i++){
        result=max(result,dp[i]);
    }
    printf("%.10f",result);
}

int main()
{
    initialize();
    solve();

    return 0;
}