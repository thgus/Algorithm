/*
3954번: Brainf**k 인터프리터
https://www.acmicpc.net/problem/3954
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

#define ARRAY_MAX 100000
#define STR_MAX 4096
#define LOOP_MAX 50000000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int arr[ARRAY_MAX+50];

int time[STR_MAX+50];
int match[STR_MAX+50];

inline void operation(string &str, int &str_index,string input, int &input_index,  int &arr_index, int sm, int si)
{
        switch(str[str_index])
        {
            case '-':
                arr[arr_index]--;
                if(arr[arr_index]<0)    arr[arr_index]=255;
                break;
            case '+':
                arr[arr_index]++;
                arr[arr_index]%=256;
                break;
            case '<':
                arr_index--;
                if(arr_index<0) arr_index=sm-1;
                break;
            case '>':
                arr_index++;
                arr_index%=sm;
                break;
            case '[':
                if(arr[arr_index]==0)
                {   
                    str_index=match[str_index];
                }
                break;
            case ']':
                if(arr[arr_index]!=0)
                {
                    str_index=match[str_index];
                }
                break;
            case ',':
                if(input_index==si)
                {
                     arr[arr_index]=255;
                }
                else
                {
                    arr[arr_index]=(int)input[input_index++];
                }
                break;
        }
}

void solve(int sm,int sc,int si,string str,string input)
{
    stack<int> s;
    for(int i=0;i<sc;i++)
    {
        if(str[i]=='[')
        {
            s.push(i);
        }
        else if(str[i]==']')
        {
            int cur=s.top();
            s.pop();
            match[cur]=i;
            match[i]=cur;
        }
    }

    memset(arr,0,sizeof(int)*sm);

    memset(time,0,sizeof(int)*(sc+1));
    
    int arr_index=0;
    int str_index=0;
    int input_index=0;
    
    pair<int,int> loop_index;
    bool isLoop=false;
    int total_time=0;

    while(1)
    {   
        total_time++;
        if(str_index==sc)   break;
        if(total_time>LOOP_MAX)
        {
            isLoop=true;
            break;
        }
        
        operation(str,str_index,input,input_index,arr_index,sm,si);
        str_index++;
    }

    if(!isLoop)
    {
        cout<<"Terminates\n";
    }
    else
    {
        total_time=0;
        
        while(total_time<=LOOP_MAX)
        {
            total_time++;

            operation(str,str_index,input,input_index,arr_index,sm,si);

            time[str_index]++;
            str_index++;
        }

        for (int index = str_index; index <= sc; index++)
        {
            if (str[index - 1] == ']' && time[index] == 0)
            {
                loop_index = {match[index - 1],index-1};
                if (time[loop_index.first] != 0)   break;
            }
        }

        cout<<"Loops "<<loop_index.first<<" "<<loop_index.second<<"\n";
    }
}

int main()
{
    sync_off;
 
    int t;
    cin>>t;
    while(t--)
    {
        int sm,sc,si;
        cin>>sm>>sc>>si;
        string str;
        string input;

        cin>>str;
        cin>>input;

        solve(sm,sc,si,str,input);
    }

    return 0;
}