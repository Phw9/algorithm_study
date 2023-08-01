#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    /*
    aC0+aC1 -> a!/a!0! + a!/(a-1)!1! -> a -> a개의 옷을 입을 때 경우의 수
    (1+a)(1+b)....(1+z)-1 안입을 경우의 수 1을 더해서 계산 후 1 빼주기
    */
    int answer = 1;
    
    unordered_map<string, int> clothes_Map;
    
    for(int i=0; i<clothes.size(); i++)
    {
        clothes_Map[clothes[i][1]]+=1;
    }
    
    for(auto i: clothes_Map)
    {
        answer *= i.second+1;
    }
    return answer-1;
}
