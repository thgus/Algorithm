/*
16918번: 봄버맨
https://www.acmicpc.net/problem/16918
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r, c, n;
vector<vector<char>> map;

void initialize()
{
	cin >> r >> c >> n;
	map.resize(r, vector<char>(c));

	char ch;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
            cin>>map[i][j];         
		}
	}
}

void boom(vector<vector<char>> &s, vector<vector<char>> &result){
    int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (s[i][j] == 'O')
            {
                result[i][j] = '.';
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + d[k][0];
                    int nx = j + d[k][1];
                    if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                        continue;
                    result[ny][nx] = '.';
                }
            }
        }
    }
}

void print_map(vector<vector<char>> &vec){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
}

void solve1(){

    if(n==1){
        print_map(map);
    }
    else if(n%2==0){
        vector<vector<char>> result(r,vector<char>(c,'O'));

        print_map(result);
    }
    else if(n%4==1){
        vector<vector<char>> result(r,vector<char>(c,'O'));
        vector<vector<char>> s(r,vector<char>(c,'O'));
        
        boom(map,s);
        boom(s,result);
        print_map(result);
    }
    else{
        vector<vector<char>> result(r,vector<char>(c,'O'));

        boom(map,result);
        print_map(result);
    }
}

void solve2(){
    if(n%2==0){
        vector<vector<char>> result(r,vector<char>(c,'O'));
        print_map(result);
        return;
    }

    int time=3;
    while(time<=n){
        vector<vector<char>> result(r,vector<char>(c,'O'));
        boom(map,result);
        map=result;
        time+=2;
    }
    print_map(map);
}


int main()
{
	sync_off;
	initialize();
	solve1();
    //solve2();

	return 0;
}