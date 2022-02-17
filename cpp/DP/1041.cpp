/*
1041번: 주사위
https://www.acmicpc.net/problem/1041
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define DICE_NUM 6
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

long long n;
long long dice[DICE_NUM];

void initialize()
{  
    cin>>n;
    for(int i=0;i<DICE_NUM;i++){
        cin>>dice[i];
    }     
}

void solve1()
{
    long long sum=0;
    long long max_num=-1;
    for(int i=0;i<6;i++){
        sum+=dice[i];
        max_num=max(max_num,dice[i]);
    }
    cout<<sum-max_num;
}

void solve2()
{
    long long cmin=987654321;
    for(int i=0;i<6;i++){
        cmin=min(cmin,dice[i]);
    }

    int sum1[8][3]={{0,3,4},{0,4,2},{0,1,2},{0,1,3},{1,2,5},{1,5,3},{2,4,5},{3,4,5}};
    long long min_sum1=987654321;
    for(int i=0;i<8;i++){
        long long cur_sum=dice[sum1[i][0]]+dice[sum1[i][1]]+dice[sum1[i][2]];
        min_sum1=min(min_sum1,cur_sum);
    }

    long long min_sum2=98765431;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i==j)    continue;
            if(i==0&&j==5||i==5&&j==0)  continue;
            if(i==1&&j==4||i==4&&j==1)  continue;
            if(i==2&&j==3||i==3&&j==2)  continue;

            min_sum2=min(min_sum2,dice[i]+dice[j]);
        }
    }

    long long result=0;
    result+=min_sum1*4;
    result+=min_sum2*(((n-2)*4)+((n-1)*4));
    result+=cmin*(((n-2)*(n-2))+((n-1)*(n-2))*4);

    cout<<result;
}

int main()
{
    sync_off;
    initialize();

    if(n==1){
        solve1();
    }
    else{
        solve2();
    }

    return 0;
}