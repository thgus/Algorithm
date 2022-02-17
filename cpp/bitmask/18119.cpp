/*
18119번: 단어 암기
https://www.acmicpc.net/problem/18119

비트마스크 신기한 알고리즘이네
*/

#include <iostream>
#include <vector>

#define MAX 10000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<int> words(MAX);

void initialize()
{
    cin>>n>>m;

    string temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        for(char c:temp){
            //알파벳 추가
            words[i]|=(1<<c-'a');
        }
    }
    
}

void solve()
{
    int o;
    char x;

    int mem=0;
    while(m--){
        int count=0;
        cin>>o>>x;
        //이미 알파벳을 기억하고 있다는 전제이므로
        //o에 관계 없이 toggle(XOR)을 이용하여
        //mem에 기억하는 단어 기억하지 못하는 단어를 저장
        mem^=(1<<(x-'a'));

        for(int i:words){
            //기억하지 못하는 알파벳이 들어간 단어라면 
            if(mem&i){
                //카운트 증가
                count++;
            }
        }

        cout<<n-count<<"\n";
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}