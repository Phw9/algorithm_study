#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    if(arr.size() != 0) answer.emplace_back(arr.at(0));
    for(int i = 1; i < arr.size(); i++) { 
        if(arr.at(i-1) == arr.at(i)) {
            continue;
        }
        else {
            answer.emplace_back(arr.at(i));
        }
    }

    return answer;
}