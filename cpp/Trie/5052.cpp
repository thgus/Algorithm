/*
5052번: 전화번호 목록
https://www.acmicpc.net/problem/5052

TRY한번 써서 함
배열 써서 하는 방법도 있다는데
=> 911 957 9112가 있으면 
숫자열 정렬 같은 경우에는 911 957 9112 겠지만 
문자열로 정렬하면 911 9112 957 와 같이 정렬 된다.
따라서 인접한 배열들 끼리 같은 같은 요소를 가지고 있는지 확인하면 됨.
*/

#include <iostream>
#include <vector>
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int t;

struct TRIE{
    bool isFinish=false;    
    TRIE *node[11];

    TRIE(){
        for(int i=0;i<10;i++){
            node[i]=NULL;
        }
    }
};

TRIE *root;

void initialize();
void solve(vector<string> &vec);
void insertTRIE(TRIE &t, string str, int index );

int main()
{
    sync_off;
    initialize();

    return 0;
}

void initialize()
{
    cin>>t;

    string temp;
    int n;
    while(t--){
        vector<string> vec(0);
        cin>>n;
        while(n--){
            cin>>temp;
            vec.push_back(temp);
        }
        solve(vec);
    }
}

void insertTRIE(TRIE &t, string str, int index )
{
    int c=str[index]-'0';
    if(t.node[c]==NULL){
        t.node[c]=new TRIE();
    }

    if(str.size()-1!=index){
        insertTRIE(*t.node[c],str,index+1);
    }
    else{
        t.node[c]->isFinish=true;
    }
}

bool isSuceess(TRIE &t, string str){
    for(int i=0;i<10;i++){
        if(t.node[i]!=NULL){
            if(t.isFinish){
                return false;
            }
            char c=i+'0';
            string _str=str+c;
            bool flag = isSuceess(*t.node[i],_str);
            if(!flag){
                return false;
            }
        }
    }
    return true;
}

void solve(vector<string> &vec)
{
    root= new TRIE();
    for(int i=0;i<vec.size();i++){
        string str=vec[i];
        insertTRIE(*root,str,0);
    }

    cout<<((isSuceess(*root,""))?"YES\n":"NO\n");

    delete root;
}