#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto cmd : commands) {
        vector<int> temp;
        for(int i = cmd.at(0) - 1; i < cmd.at(1); i++ ) {
            temp.emplace_back(array.at(i));
        }
        sort(temp.begin(), temp.end());
        answer.emplace_back(temp.at(cmd.at(2)-1));
    }
    return answer;
}