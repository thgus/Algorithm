/*
1539번: 이진 검색 트리
https://www.acmicpc.net/problem/1539

와 신기하다
https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=221133866451&proxyReferer=https:%2F%2Fwww.google.com%2F

처음에는 최소공통조상 문제처럼 부모노드들 정보를 저장하면서 찾으려 했는데 이러면 왼쪽자식인지 오른쪽 자식인지 판단해야하고 여러모로 까다로우니까
위의 블로그를 참고로 해서 풀어보겠음.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec;

void initialize()
{
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }
}

void solve()
{
    vector<int> depth(n,0);
    set<int> s;

    depth[vec[0]]=1;
    s.insert(vec[0]);
    long long result=1;

    int d;
    for(int i=1;i<n;i++){
        int cur=vec[i];
        auto it= s.lower_bound(cur);
        
        auto right=it--;
        auto left=it;

        if(right==s.end()){
            d=depth[*left]+1;
        }
        else if(right==s.begin()){
            d=depth[*right]+1;
        }
        else{     
            d=max(depth[*left],depth[*right])+1; 
        }

        s.insert(cur);
        depth[cur]=d;
        result+=d;
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