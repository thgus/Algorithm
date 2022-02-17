/*
1176번: 섞기
https://www.acmicpc.net/problem/1176
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,k;
vector<int> vec;

void initialize()
{
    cin>>n>>k;
    vec.resize(n);

    for(int i=0;i<n;i++){
        cin>>vec[i];    
    }    
}

struct Node{
    int bit;
    int last_student;
};

void solve()
{
    vector<vector<int>> dp((1<<n),vector<int>(n,0));
    queue<Node> que;
    for(int i=0;i<n;i++){
        que.push({1<<i,i});
        dp[(1<<i)][i]=1;
    }    

    while(!que.empty()){
        int last_student=que.front().last_student;
        int cur_bit=que.front().bit;
        que.pop();

        if(cur_bit==(1<<n)-1)   break;

        int student_len=vec[last_student];
        for(int next_student=0;next_student<n;next_student++){
            // 이미 배열된 학생일 경우
            if(cur_bit&(1<<next_student))   continue;

            int nstudent_len=vec[next_student];
            // 학생끼리의 키 차이가 k 이하일 경후
            if(abs(nstudent_len-student_len)<=k)    continue;

            int next_bit=cur_bit|(1<<next_student);
            if(dp[next_bit][next_student]==0){
                que.push({next_bit,next_student});
            }
            dp[next_bit][next_student]+=dp[cur_bit][last_student];
        }
    }

    long long result=0;
    for(int i=0;i<n;i++){
        result += dp[(1<<n)-1][i];
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