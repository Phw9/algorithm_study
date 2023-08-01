#include <vector>
#include <iostream>
#include<stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    bool isNum[10] = {false};

    for(int i=0; i<arr.size(); i++)
    {
        int n = arr[i];
        
        if(!isNum[n] || arr[i-1] != arr[i])
        {
            answer.push_back(n);
            isNum[n] = true;
        }
        else
            continue;
        
    }
    
    return answer;
}