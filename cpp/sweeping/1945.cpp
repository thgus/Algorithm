/*
1945번: 직사각형
https://www.acmicpc.net/problem/1945

와 기울기로 정렬이라니 대단하다
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define _USE_MATH_DEFINES
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Square{
    int x,y,isRight;
    bool operator<(Square s){
        double grad1=(double)y/(double)x;
        double grad2=(double)s.y/(double)s.x;
        if(grad1==grad2){
            return isRight<s.isRight;
        }
        return grad1>grad2;
    }
};

int n;
vector<Square> vec;

void initialize()
{
    cin>>n;
    int a,b,c,d;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        vec.push_back({a,d,0});
        vec.push_back({c,b,1});
    }
}

void solve()
{
    sort(vec.begin(),vec.end());

    int result=0;
    int curNum=0;
    for(int i=0;i<vec.size();i++){
        int isRight=vec[i].isRight;
        
        (isRight)?curNum--:result=max(result,++curNum);
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