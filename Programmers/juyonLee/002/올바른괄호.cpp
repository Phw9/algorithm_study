#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int n = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
            n+=1;
        else if(s[i] == ')')
            n-=1;
        
        if(n < 0)
            return false;
            
    }

    return n == 0;
}