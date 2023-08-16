#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct customFn {
  bool operator()(const int& lhs, const int& rhs) const { return lhs > rhs; }    
};

int solution(vector<int> citations) {
    int h = 0;
    sort(citations.begin(), citations.end(), customFn());
    for(int i = 0; i < citations.size(); i++) {
        if(citations.at(i) >= (i+1)) {
            h = i+1;
        }
    }
    return h;
}