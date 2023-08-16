#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int first = 0, second = 0;
    for(auto size : sizes) {
        if(max(size.at(0), size.at(1)) > first) {
            first = max(size.at(0), size.at(1));
        }
        if(min(size.at(0), size.at(1)) > second) {
            second = min(size.at(0), size.at(1));
        }
    }
    return (first * second);
}