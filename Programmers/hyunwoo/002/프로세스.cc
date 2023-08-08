#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct customFn {
    bool operator()(const int& lhs, const int& rhs) const { return lhs > rhs; }
};

int solution(vector<int> priorities, int location) {
    int answer = 0, idx = 0;
    
    queue<pair<int,int>> pq;
    for(int i = 0; i < priorities.size(); i++) {
        pair<int,int> temp{priorities.at(i), i};
        pq.emplace(temp);
    }
    
    sort(priorities.begin(), priorities.end(), customFn());
    while(idx != priorities.size() - 1) {
        if(pq.front().first == priorities.at(idx)) {
            idx++;
            if(pq.front().second == location) {
                return idx;
            }
            else {
                pq.emplace(pq.front());
                pq.pop();
            }
        }
        else {
            pq.emplace(pq.front());
            pq.pop();
        }
    }
    
}