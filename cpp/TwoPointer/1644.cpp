/*
1644번: 소수의 연속합
https://www.acmicpc.net/problem/1644
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

vector<int> getPrimeNum(){
    vector<bool> isPrimeNum(n+1,true);
    for(int i=2;i<=n/2;i++){
        if(!isPrimeNum[i]){
            continue;
        }
        int index=i*2;

        while(index<=n){
            isPrimeNum[index]=false;
            index+=i;
        }
    }

    vector<int> primeNum;
    for(int i=2;i<=n;i++){
        if(isPrimeNum[i]){
            primeNum.push_back(i);
        }
    }

    return primeNum;
}

void solve()
{
    vector<int> primeNum=getPrimeNum();
    if(primeNum.size()==0){
        cout<<"0";
        return;
    }

    int result=0;
    int curSum=primeNum[0];
    int left=0, right=0;

    while(1){
        if(curSum==n){
            result++;
        }

        if(curSum<=n){
            if(right<primeNum.size()-1){
                curSum+=primeNum[++right];
            }
            else{
                break;
            }
        }
        else{
            curSum-=primeNum[left++];
        }
    }

    cout<<result;

}

int main()
{
    initialize();
    solve();

    return 0;
}