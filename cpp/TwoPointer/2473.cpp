/*
2473번: 세 용액
https://www.acmicpc.net/problem/2473
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<int> liquor;

void initialize(){
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        liquor.push_back(temp);
    }
    sort(liquor.begin(),liquor.end());
}

void printResult(vector<int> vec){
    sort(vec.begin(),vec.end());
    for(int i=0;i<3;i++){
        cout<<vec[i]<<" ";
    }
}

void solve(){
    vector<int> liq(3);
    long long acid;

    long long result=5000000000001;

    int left,right;
    for(int i=0;i<n;i++){
        left=0; right=n-1;
        
        while(left<right){
            if(left==i){
                left++;
                continue;
            }
            else if(right==i){
                right--;
                continue;
            }
            acid=liquor[i];
            acid+=liquor[left];
            acid+=liquor[right];

            if(result>abs(acid)){
                result=abs(acid);
                liq[0]=liquor[i];
                liq[1]=liquor[left];
                liq[2]=liquor[right];

                if(acid==0){
                    return printResult(liq);
                }
            }

            if(acid<0){
                left++;
            }
            else if(acid>0){
                right--;
            }
        }
    }

    return printResult(liq);
}

int main(){
    sync_off;
    initialize();
    solve();

    return 0;
}