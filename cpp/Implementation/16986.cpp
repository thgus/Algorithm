/*
16986번: 인싸들의 가위바위보
https://www.acmicpc.net/problem/16986

시간이 너무 오래걸려 왜지? 다른 사람 풀이도 한번 봐야지
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,k;
vector<vector<int>> compatibility;
vector<vector<int>> player;

struct Node{
    int a=0,b=1;

    vector<bool> isPay;
    int index[3]={0,0,0};
    int win[3]={0,0,0};
};

void initialize()
{
    cin>>n>>k;
    compatibility.resize(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>compatibility[i][j];
        }
    }

    player.resize(3,vector<int>(20));
    for(int i=1;i<3;i++){
        for(int j=0;j<20;j++){
            cin>>player[i][j];
            player[i][j]--;
        }
    }
}

void solve()
{
    queue<Node> que;
    Node temp;
    temp.isPay.resize(n,false);
    que.push(temp);

    while(!que.empty()){
        temp=que.front();
        int a=temp.a;
        int b=temp.b;
        que.pop();

        if(temp.win[0]>=k){
            cout<<"1";
            return;
        }

        bool isBreak=false;
        for(int i=1;i<3;i++){
            if(temp.win[i]>=k){
                isBreak=true;
                break;
            }
        }
        if(isBreak) continue;

        if(a==0){
            for(int i=0;i<n;i++){
                if(temp.isPay[i])    continue;
                Node save=temp;

                temp.isPay[i]=true;
                if(compatibility[i][player[b][temp.index[b]]]==2){
                    temp.win[a]++;  temp.index[b]++;
                    temp.b=(temp.b==1)?2:1;
                    que.push(temp);
                }
                else{
                    temp.win[b]++;  temp.index[b]++;
                    temp.a=1;   temp.b=2;
                    que.push(temp);
                }
            
                temp=save;
            }
        }
        else{
            if(compatibility[player[a][temp.index[a]]][player[b][temp.index[b]]]==2){
                temp.win[a]++;  temp.index[a]++; temp.index[b]++;
                temp.b=temp.a;  temp.a=0;
                que.push(temp);
            }
            else{
                temp.win[b]++;  temp.index[a]++; temp.index[b]++;
                temp.a=0;
                que.push(temp);
            }
        }
    }

    cout<<"0";
    return;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}