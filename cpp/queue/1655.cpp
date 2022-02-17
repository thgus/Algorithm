/*
1655번: 가운데를 말해요
https://www.acmicpc.net/problem/1655
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void solve()
{
    int n;
    priority_queue<int> max_heap;
    priority_queue<int> min_heap;

    cin>>n;
    while(n--){
        int input;
        cin>>input;
        if(max_heap.size()==min_heap.size()){
            max_heap.push(input);
        }
        else{
            min_heap.push(-input);
        }

        if(!min_heap.empty() && -min_heap.top()<max_heap.top()){
            int min_temp=-min_heap.top();
            int max_temp=max_heap.top();
            min_heap.pop(); max_heap.pop();

            min_heap.push(-max_temp);
            max_heap.push(min_temp);
        }

        cout<<max_heap.top()<<"\n";
    }

}

int main()
{
    sync_off;
    solve();

    return 0;
}