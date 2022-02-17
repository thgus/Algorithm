/*
2064번: IP 주소
https://www.acmicpc.net/problem/2064
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
//vector<int> ip;

long long first=LLONG_MAX;
long long last=-1;

void initialize()
{
    cin >> n;

    string str;

    int index;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        str += '.';
        index = 0;
        
        long long temp=0;
        for (int j = 0; j < 4; j++)
        {
            temp<<=8;

            int nindex = str.find('.', index);
            int num = stoi(str.substr(index, nindex - index));

            for(int k=0;k<8;k++)
            {
                if(num%2!=0)    temp|=(1<<k);

                num/=2;
            }

            index = nindex + 1;
        }

        if(temp>last)   last=temp;
        if(temp<first)  first=temp;
    }
}

void print(long long mask) {
    long long shift = 24;
    for (int i = 0; i < 4; i++, shift -= 8) {
        cout << ((mask >> shift) & (1 << 8) - 1);
        if (i != 3) cout << '.';
    }
    cout << '\n';
}

void solve()
{
    //cout<<first<<" "<<last<<"\n";

    int index;
    long long mask=0;
    bool flag=false;

    for(index=31;index>=0;index--)
    {
        long long t1=first&(1<<index);
        long long t2=last&(1<<index);
        
        mask<<=1;  
        if(!flag&&t1==t2){
            mask|=(1<<0);
        }   
        else flag=true;
    }

    print(first&mask);
    print(mask);
}


int main()
{
    sync_off;

    initialize();
    solve();

    return 0;
}