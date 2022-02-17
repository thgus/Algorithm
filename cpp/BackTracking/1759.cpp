/*
1759번: 암호 만들기
https://www.acmicpc.net/problem/1759
*/

#include<iostream>
#include<vector>
#include<algorithm>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int l,c;
vector<char> chs;

void initialize(){
    cin>>l>>c;
    char temp;
    for(int i=0;i<c;i++){
        cin>>temp;
        chs.push_back(temp);
    }
}

void getPass(string pass, vector<bool> &visited, int lastIndex, int con, int vowel){
    if(pass.length()==l){
        if(con<2||vowel<1){
            return;
        }
        cout<<pass<<"\n";
    }

    for(int i=lastIndex+1;i<c;i++){
        if(visited[i]){
            continue;
        }
        visited[i]=true;
        pass+=chs[i];
        if(chs[i]=='a'||chs[i]=='e'||chs[i]=='i'||chs[i]=='o'||chs[i]=='u'){
            getPass(pass,visited,i,con,vowel+1);
        }
        else{
            getPass(pass,visited,i,con+1,vowel);
        }
        pass.pop_back();
        visited[i]=false;
    }
}

void solve(){
    sort(chs.begin(),chs.end());

    vector<bool> visited(c,false);
    getPass("", visited,-1,0,0);
}

int main(){
    sync_off;
    initialize();
    solve();

    return 0;
}