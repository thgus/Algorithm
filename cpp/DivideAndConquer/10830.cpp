/*
10830번: 행렬 제곱
https://www.acmicpc.net/problem/10830

a^n*a^m=a^(n+m)
*/

#include <iostream>
#include <vector>

#define MAX 5
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<vector<int>> matrix(MAX,vector<int>(MAX));
int n;
long long b;

void initialize()
{
    cin>>n>>b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            matrix[i][j]%=1000;
        }
    }
}

void printResult(vector<vector<int>> &result){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}

vector<vector<int>> mulMatrix(vector<vector<int>> &vec1, vector<vector<int>> &vec2){
    vector<vector<int>> result(MAX,vector<int>(MAX,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                result[i][j]+=(vec1[i][k]*vec2[k][j])%1000;
            }
            result[i][j]%=1000;
        }
    }
    //printResult(result);
    return result;
}

vector<vector<int>> findMatrix(long long num){
    if(num==1){
        return matrix;
    }

    vector<vector<int>> vec1, vec2, vec3;
    vec2=vec1=findMatrix(num/2);
    vec3=mulMatrix(vec1,vec2);

    if(num%2==0){
        return vec3;
    }
    else{
        return mulMatrix(vec3,matrix);
    }
    
}

void solve()
{
    vector<vector<int>> result=findMatrix(b);
    printResult(result);
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}