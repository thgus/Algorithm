/*
16925번: 문자열 추측
https://www.acmicpc.net/problem/16925
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;
int n;
vector<string> vec;

bool check(string str, vector<char> &sp){
    vector<vector<bool>> visited(n-1,vector<bool>(2,false));

    for(int i=0;i<vec.size();i++){
        bool can1=true;
        for(int j=0;j<vec[i].size();j++){
            if(str[j]!=vec[i][j]){
                can1=false;
                break;
            }
        }

        bool can2=true;
        int start=n-vec[i].size();
        for(int j=0;j<vec[i].size();j++){
            if(str[start+j]!=vec[i][j]){
                can2=false;
                break;
            }
        }

        if(can1&&!visited[vec[i].size()-1][0]){
            visited[vec[i].size()-1][0]=true;
            sp[i]='P';
        }
        else if(can2&&!visited[vec[i].size()-1][1]){
            visited[vec[i].size()-1][1]=true;
            sp[i]='S';
        }
        else{
            return false;
        }
    }

    return true;
}   

int main()
{
    sync_off;
    cin>>n;

    vec.resize(n*2-2);
    
    string m1="",m2="";
    for(int i=0;i<2*n-2;i++){
        cin>>vec[i];

        if(vec[i].size()==n-1){
            if(m1=="")  m1=vec[i];
            else if(m2=="") m2=vec[i];
        }
    }

    string str1=m1+m2[m2.size()-1];
    string str2=m2+m1[m1.size()-1];

    vector<char> sp1(n*2-2);
    vector<char> sp2(n*2-2);

    bool check1=check(str1,sp1);
    bool check2=check(str2,sp2);

    if(check1){
        cout<<str1<<"\n";
        for(int i=0;i<2*n-2;i++){
            cout<<sp1[i];
        }
    }
    else if(check2){
        cout<<str2<<"\n";
        for(int i=0;i<2*n-2;i++){
            cout<<sp2[i];
        }
    }

    return 0;
}