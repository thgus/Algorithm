/*
1019번: 책 페이지
https://www.acmicpc.net/problem/1019

참고. 어렵다
https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
void initialize()
{
    cin>>n;
}

vector<long long> vec(10,0);

//만약 15~20으로 값을 증가시키면 빈 16~19의 값을 추가해주는 역할
//위의 상황과 같다면 16에서 1, 6 17에서 1,7 18에서 1,8 19에서 1,9 값을 추가해 줄 수 있도록 함.
//그리고 150~200이었는데 15~20의 단계에서 왔다면 16,17,18,19가 10번씩 나왔을 것이다. 이를 제시해주는 변수가 r
void calculate(int i, int r){
    while(i!=0){
        vec[i%10]+=r;
        i/=10;
    }
}

void printResult(){
    for(int i=0;i<=9;i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

void solve()
{
    int s=1;
    int e=n;
    int r=1;

    while (1)
    {
        while (s % 10 != 0)
        {
            calculate(s, r);
            s++;
            if(e<s){
                printResult();
                return;
            }
        }

        while (e % 10 != 9)
        {
            calculate(e, r);
            e--;
            if(e<s){
                printResult();
                return;
            }
        }

        s /= 10;
        e /= 10;
        int order = (e - s + 1)*r;
        for (int i = 0; i <= 9; i++)
        {
            vec[i] += order;
        }
        r*=10;
    }

}

int main()
{
    //sync_off;
    initialize();
    solve();

    return 0;
}