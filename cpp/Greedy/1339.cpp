/*
1339번: 단어 수학
https://www.acmicpc.net/problem/1339
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<string> vec;

void initialize()
{
    cin>>n;
    string str;

    int maxSize=0;
    for(int i=0;i<n;i++){
        cin>>str;
        int strlen=str.length();
        maxSize=max(maxSize,strlen);
        vec.push_back(str);
    }
}

void solve()
{
    vector<pair<int,char>> alphabetScore(26);
    for(int i=0;i<26;i++){
        alphabetScore[i].second=(char)('A'+i);
        alphabetScore[i].first=0;
    }

    for(int i=0;i<vec.size();i++){
        int p=1;
        string str=vec[i];
        int strlen=str.size();
        for(int j=strlen-1;j>=0;j--){
            int index=str[j]-'A';
            alphabetScore[index].first+=p;
            p*=10;
        }
    }
    sort(alphabetScore.begin(),alphabetScore.end(),greater<>());

    vector<int> num(26,0);
    for(int i=0;i<9;i++){
        int index=alphabetScore[i].second-'A';
        num[index]=9-i;
    }
    
    int result=0;
    for(int i=0;i<vec.size();i++){
        string str=vec[i];
        int strlen=str.size();

        int p=1;
        for(int j=strlen-1;j>=0;j--){
            int index=str[j]-'A';
            result+=p*(num[index]);

            p*=10;
        }
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