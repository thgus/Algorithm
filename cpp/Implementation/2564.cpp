/*
2564번: 경비원
https://www.acmicpc.net/problem/2564
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r,c;
int n;
vector<pair<int,int>> vec;
pair<int,int> donggeun;

void initialize()
{
    cin>>c>>r;
    cin>>n;

    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec.push_back({a,b});
    }
    cin>>donggeun.first>>donggeun.second;
}

// 1은 블록의 북쪽, 2는 블록의 남쪽, 3은 블록의 서쪽, 4는 블록의 동쪽
int result=0;
void east()
{
    for(int i=0;i<n;i++){
        int direction=vec[i].first;
        int index=vec[i].second;

        switch (direction)
        {
        case 1:
            result+=donggeun.second+c-index;
            break;
        case 2:
            result+=r-donggeun.second+c-index;
            break;
        case 3:
            result+=c+min(donggeun.second+index,2*r-donggeun.second-index);
            break;
        case 4:
            result+=abs(donggeun.second-index);
            break;
        }
    }
}

void west()
{
    for(int i=0;i<n;i++){
        int direction=vec[i].first;
        int index=vec[i].second;

        switch (direction)
        {
        case 1:
            result+=index+donggeun.second;
            break;
        case 2:
            result+=index+r-donggeun.second;
            break;
        case 3:
            result+=abs(donggeun.second-index);
            break;
        case 4:
            result+=c+min(donggeun.second+index,2*r-donggeun.second-index);
            break;
        }
    }
}

void south()
{
    for(int i=0;i<n;i++){
        int direction=vec[i].first;
        int index=vec[i].second;

        switch (direction)
        {
        case 1:
            result+=r+min(donggeun.second+index,2*c-donggeun.second-index);
            break;
        case 2:
            result+=abs(donggeun.second-index);
            break;
        case 3:
            result+=donggeun.second+r-index;
            break;
        case 4:
            result+=c-donggeun.second+(r-index);
            break;
        }

    }
}

void north()
{
    for(int i=0;i<n;i++){
        int direction=vec[i].first;
        int index=vec[i].second;

        switch (direction)
        {
        case 1:
            result+=abs(donggeun.second-index);
            break;
        case 2:
            result+=r+min(donggeun.second+index,2*c-donggeun.second-index);
            break;
        case 3:
            result+=index+donggeun.second;
            break;
        case 4:
            result+=c-donggeun.second+index;
            break;
        }

    }
}

int main()
{
    sync_off;
    initialize();

    switch(donggeun.first){
        case 1:
            north();
            break;
        case 2:
            south();
            break;
        case 3:
            west();
            break;
        case 4:
            east();
            break;
    }

    cout<<result;
    return 0;
}