#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.reserve(prices.size());
    
    for(int i = 0; i < prices.size(); i++) {
        int time = 0;
        answer.emplace_back(move(time));
        for(int j = i+1; j < prices.size(); j++) {
            if(prices.at(j) >= prices.at(i)) {
                answer.back()++;
            }
            else {
                answer.back()++;
                break;
            }
        }
    }
    return answer;
}