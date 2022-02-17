/*
2342번: Dance Dance Revolution
https://www.acmicpc.net/problem/2342
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXNUM 4*100000+1
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<int> seq;

void initialize()
{
    int temp;
    while(1){
        cin>>temp;
        if(temp==0){
            break;
        }
        seq.push_back(temp);
    }
}

int calCost(int from, int to){
    if(from==0){
        return 2;
    }
    else if(from==to){
        return 1;
    }
    else if((from%2==0)&&(to%2==0)||(from%2==1)&&(to%2==1)){
        return 4;
    }
    else{
        return 3;
    }
}

void solve()
{
    if(seq.size()==0){
        cout<<"0";
        return;
    }

    vector<vector<int>> dp(5,vector<int>(5,MAXNUM));
    vector<vector<bool>> isStart(5,vector<bool>(5,false));

    int cur=seq[0];

    dp[cur][0]=2;
    dp[0][cur]=2;

    isStart[cur][0]=true;
    isStart[0][cur]=true;    

    int leftCost, rightCost;
    for(int k=1;k<seq.size();k++){
        vector<vector<bool>> saveStart(5,vector<bool>(5,false));
        vector<vector<int>> saveCost(5,vector<int>(5,MAXNUM));

        cur=seq[k];
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(isStart[i][j]){
                    if(i==cur||j==cur){
                        saveCost[i][j]=min(saveCost[i][j],dp[i][j]+1);
                        saveStart[i][j]=true;
                        continue;
                    }

                    leftCost=calCost(i,cur);
                    rightCost=calCost(j,cur);

                    saveCost[i][cur]=min(saveCost[i][cur],dp[i][j]+rightCost);
                    saveCost[cur][j]=min(saveCost[cur][j],dp[i][j]+leftCost);

                    saveStart[i][cur]=true;
                    saveStart[cur][j]=true;
                }
            }
        }

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                isStart[i][j]=saveStart[i][j];
                dp[i][j]=saveCost[i][j];
            }
        }
    }

    int result=MAXNUM;

    int lastNum=seq.back();
    for(int i=0;i<5;i++){
        result=min(result,min(dp[lastNum][i],dp[i][lastNum]));
    }
    cout<<result;

}

int main()
{
    initialize();
    solve();

    return 0;
}