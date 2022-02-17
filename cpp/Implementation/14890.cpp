/*
14890번: 경사로
https://www.acmicpc.net/problem/14890
*/

#include <iostream>
#include <vector>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,l;
vector<vector<int>> map;

void initialize()
{
    cin>>n>>l;
    map.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
}

bool check_row(int r){
    int cur_height=map[r][0];
    int cur_len=1;
    for(int i=1;i<n;i++){
        if(abs(cur_height-map[r][i])>=2){
            return false;
        }

        if(map[r][i]==cur_height){
            cur_len++;
        }
        else if(cur_height<map[r][i]){
                if(cur_len<l)   return false;
            cur_height=map[r][i];
            cur_len=1;
        }
        else{
            cur_height=map[r][i];
            cur_len=1;
            for(i=i+1;i<n;i++){
                if(cur_height!=map[r][i])   break;
                cur_len++;
            }
            if(cur_len<l)   return false;
            cur_len=cur_len-l;
            i--;
        }
    }

    //cout<<"r:"<<r<<"\n";
    return true;
}

bool check_col(int c){
    int cur_height=map[0][c];
    int cur_len=1;
    for(int i=1;i<n;i++){
        if(abs(cur_height-map[i][c])>=2){
            return false;
        }

        if(map[i][c]==cur_height){
            cur_len++;
        }
        else if(cur_height<map[i][c]){
                if(cur_len<l)   return false;
            cur_height=map[i][c];
            cur_len=1;
        }
        else{
            cur_height=map[i][c];
            cur_len=1;
            for(i=i+1;i<n;i++){
                if(cur_height!=map[i][c])   break;
                cur_len++;
            }
            if(cur_len<l)   return false;
            cur_len=cur_len-l;
            i--;
        }
    }

    //cout<<"c:"<<c<<"\n";
    return true;
}

void solve()
{
    int result=0;
    for(int i=0;i<n;i++){
        if(check_row(i))    result++;
        if(check_col(i))    result++;
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