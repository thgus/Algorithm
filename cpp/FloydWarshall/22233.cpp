/*
22233번: 가희와 키워드
https://www.acmicpc.net/problem/22233

map 사용할까 했는데 입력 크기가 안주어져 있어서
문제 분류가 이분탐색으로 되어있길래 이분탐색 써서 품.
아 입력 범위 있네. map에 200,000개 넣으면 죽을라 하긴 하겟다.

와 무슨 시간 1.2초 걸리네ㅋㅋㅋㅋㅋㅋ
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<string> keyword;
vector<bool> isUse; 

int find_keyword(string key)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(keyword[mid]==key){
            return mid;
        }
        else if(keyword[mid]<key){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }

    return -1;
}

int main()
{
    sync_off;
 
    cin>>n>>m;
    isUse.resize(n,false);

    string temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        keyword.push_back(temp);
    }
    sort(keyword.begin(),keyword.end());

    int left_keyword=n;
    for(int i=0;i<m;i++)
    {
        cin>>temp;
        istringstream ss(temp);
        string stringBuffer;
        while(getline(ss,stringBuffer,',')){
            int index=find_keyword(stringBuffer);
            
            if(index==-1)   continue;
            if(!isUse[index]){
                isUse[index]=true;
                left_keyword--;
            }
        }
        cout<<left_keyword<<"\n";
    }
    return 0;
}