/*
19940번: 피자오븐
https://www.acmicpc.net/problem/19940
*/

#include <iostream>
#include <vector>
#include <cmath>

#define MAX 10000000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void print_vec(vector<int> &vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

void check(vector<int> &result_vec, vector<int> &temp, int &result, int &sum){
    //print_vec(temp);

    if(result>sum||result==sum&&result_vec>temp){
        result=sum;
        result_vec=temp;
    }

    for(int i=0;i<5;i++){
        temp[i]=0;
    }
}

void solve(int n)
{
    vector<int> temp(5,0);

    int result=n;
    vector<int> result_vec={0,0,0,n,0};

    int sum;

    int p1=n/60;
    int q1=n%60;

    //60*p1+q1;
    sum=p1+q1;
    temp[0]=p1; temp[3]=q1;
    check(result_vec,temp,result,sum);

    int p2=q1/10;
    int q2=q1%10;
    //60*p1+10*p2+q2;
    sum=p1+p2+q2;
    temp[0]=p1; temp[1]=p2; temp[3]=q2;
    check(result_vec,temp,result,sum);

    //60*p1+10*(p2+1)-(10-q2)
    sum=p1+p2+1+(10-q2);
    temp[0]=p1; temp[1]=p2+1; temp[4]=10-q2;
    check(result_vec,temp,result,sum);

    int res=60-q1;
    int rp=res/10;
    int rq=res%10;
    //60(p1+1)-res
    sum=p1+1+res;
    temp[0]=p1+1;   temp[4]=res;
    check(result_vec,temp,result,sum);

    //60(p1+1)-10*(rp)-rq
    sum=p1+1+rp+rq;
    temp[0]=p1+1; temp[2]=rp; temp[4]=rq;
    check(result_vec,temp,result,sum);

    //60(p1+1)-10*(rp+1)+res2;
    sum=(p1+1)+(rp+1)+(10-rq);
    temp[0]=p1+1;   temp[2]=rp+1;   temp[3]=10-rq;
    check(result_vec,temp,result,sum);

    print_vec(result_vec);
}

void initialize()
{
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
        solve(n);
	}
}

int main()
{
	sync_off;
	initialize();

	return 0;
}