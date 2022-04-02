#include <string>
#include <vector>
#include <iostream>

using namespace std;

int change_str(string str)
{
    if(str=="zero"||str=="0")
    {
        return 0;
    }
    else if(str=="one"||str=="1")
    {
        return 1;
    }
    else if(str=="two"||str=="2")
    {
        return 2;
    }
    else if(str=="three"||str=="3")
    {
        return 3;
    }
    else if(str=="four"||str=="4")
    {
        return 4;
    }
    else if(str=="five"||str=="5")
    {
        return 5;
    }
    else if(str=="six"||str=="6")
    {
        return 6;
    }
    else if(str=="seven"||str=="7")
    {
        return 7;
    }
    else if(str=="eight"||str=="8")
    {
        return 8;
    }
    else if(str=="nine"||str=="9")
    {
        return 9;
    }
    
    return -1;
}

int solution(string s) {
    int answer = 0;
    
    string cur="";
    for(int i=0;i<s.size();i++)
    {
        cur+=s[i];
        int result=change_str(cur);
        
        if(result!=-1)
        {
            answer*=10;
            answer+=result;
            
            cur="";
        }

        
        cout<<cur<<" ";
    }
    
    return answer;
}