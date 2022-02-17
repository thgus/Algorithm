/*
12849번: 본대 산책
https://www.acmicpc.net/problem/12849
*/

#include <iostream>
#include <vector>

#define MAX 8
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int d;
/*
0. 정보과학관
1. 전산관
2. 미래관
3. 신양관
4. 한경직기념관
5. 진리관
6. 학생회관
7. 형남공학관
*/
int map[MAX];
vector<vector<bool>> route(MAX,vector<bool>(MAX,false));

void initialize()
{
    cin>>d;
    
    //전산관 - 정보과학관
    route[1][0]=true; route[0][1]=true;
    //미래관 - 정보과학관
    route[2][0]=true; route[0][2]=true;
    //전산관 - 신양관
    route[1][3]=true; route[3][1]=true;
    //전산관 - 미래관
    route[1][2]=true; route[2][1]=true;
    //신양관 - 미래관
    route[2][3]=true; route[3][2]=true;
    //신양관 - 환경직기념관
    route[3][4]=true; route[4][3]=true;
    //미래관 - 환경직기념관
    route[2][4]=true; route[4][2]=true;
    //진리관 - 환경직기념관
    route[4][5]=true; route[5][4]=true;
    //신양관 - 진리관
    route[3][5]=true; route[5][3]=true;
    //진리관 - 학생회관
    route[5][6]=true; route[6][5]=true;
    //학생회관 - 형남공학관
    route[6][7]=true; route[7][6]=true;
    //형남공학관 - 한경직기념관
    route[4][7]=true; route[7][4]=true;
}

void solve()
{
    map[0]=1;
    while(d-->0){
        vector<long long> temp(MAX,0);
        for(int i=0;i<MAX;i++){       
            for(int j=0;j<MAX;j++){
                if(route[i][j]){
                    temp[j]+=map[i];
                    temp[j]%=1000000007;
                }
            }
        }

        for(int i=0;i<MAX;i++){
            map[i]=temp[i];
        }

    }
    cout<<map[0];
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}