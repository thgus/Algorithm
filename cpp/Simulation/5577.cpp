/*
5577번: RBY팡!
https://www.acmicpc.net/problem/5577
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> ball;

void initialize()
{
    cin>>n;
    ball.resize(n);
    for(int i=0;i<n;i++){
        cin>>ball[i];
    }
}

void solve()
{
    int m = n;
    for (int k = 0; k < n; k++)
    {
        for(int i=1;i<=3;i++){
            if (ball[k] == i) continue;
            int temp=ball[k];
            ball[k] = i;            

            int cur=k;
            int left, right;
            left = right = cur;

            int erase_len=0;
            while (erase_len != n)
            {
                int cur_color = ball[cur];
                while (left >= 0 && ball[cur] == ball[left])
                    left--;
                while (right < n && ball[cur] == ball[right])
                    right++;

                left++; right--;

                if (right - left + 1 -erase_len < 4)
                    break;

                erase_len += right - left + 1 - erase_len;

                left--; right++;

                if (left < 0)   break;
                cur = left;
            }
            ball[k]=temp;
            m=min(m,n-erase_len);
        }
    }

    cout<<m;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}