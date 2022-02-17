/*
1213번: 팰린드롬 만들기
https://www.acmicpc.net/problem/1213
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

string make_str(vector<char> &vec){
    string str="";
    for(int i=0;i<vec.size();i++){
        str+=vec[i];
    }
    return str;
}

string print_vec(vector<char> &vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i];
    }
    cout<<"\n";
}

string even(int n, vector<int> &sum){
    vector<char> vec(n);

    int l=0, r=n-1;
    for(int i=0;i<26;i++){
        if(sum[i]==0)   continue;
        if(sum[i]%2!=0){
            return "I'm Sorry Hansoo";
        }

        for(int j=1;j<sum[i];j+=2){
            vec[l++]=i+'A';
            vec[r--]=i+'A';
        }
    }

    return make_str(vec);
}

string odd(int n, vector<int> &sum){
    vector<char> vec(n,'.');

    int l=0, r=n-1;
    for(int i=0;i<26;i++){
        if(sum[i]==0)   continue;
        
        if(sum[i]%2!=0){
            if(vec[n/2]=='.'){
                vec[n/2]=i+'A';
            }
            else{
                return "I'm Sorry Hansoo";
            }
        }

        for(int j=1;j<sum[i];j+=2){
            vec[l++]=i+'A';
            vec[r--]=i+'A';
        }
    }

    return make_str(vec);
}

int main()
{
    sync_off;
    string str;
    cin>>str;

    vector<int> sum(26,0);
    vector<char> vec(str.size());

    for(int i=0;i<str.size();i++){
        sum[str[i]-'A']++;
    }

    if(str.size()%2==0){
        cout<<even(str.size(),sum);
    }
    else{
        cout<<odd(str.size(),sum);
    }
    
    return 0;
}