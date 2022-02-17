/*
2467번: 용액
https://www.acmicpc.net/problem/2467

투포인터? 그게 뭐야
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	sync_off;
    int n;
    cin>>n;
    vector<int> vec;
    int temp;

    int ng=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
        if(temp<0){
            ng++;
        }
    }
    
    int left=0;
    int right=n-1;
    
    int minAcid=2000000001;
    pair<int,int> point;

    unsigned int absAcid;
    int acid;
    while(left<right){
        acid=vec[left]+vec[right];
        absAcid=abs(acid);
        if(minAcid>absAcid){
            minAcid=absAcid;
            point.first=left;
            point.second=right;
        }
        if(acid==0){
            break;
        }
        else if(acid<0){
            left++;
        }
        else{
            right--;
        }
    }

    cout<<vec[point.first]<<" "<<vec[point.second];

	return 0;
}