#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int mul = 1;
    unordered_map<string, int> clothesMap;
    
    for(auto cloth : clothes) {
        if(clothesMap.count(cloth.at(1)) == 0) {
            clothesMap.emplace(cloth.at(1), 1);
        }
        else {
            clothesMap[cloth.at(1)]++;
        }
    }
    for(auto iter = clothesMap.begin(); iter != clothesMap.end(); iter++) {
        mul *= ((*iter).second + 1);
    }
    return (mul - 1);
}