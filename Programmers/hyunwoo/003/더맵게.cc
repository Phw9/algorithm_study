#include <string>
#include <vector>
#include <queue>

using namespace std;

struct customFn{
    bool operator()(const int lhs, const int rhs) {
        return lhs > rhs;
    }
};

int solution(vector<int> scoville, int K) {
    int min = 0, cnt = 0;
    priority_queue<int, vector<int>, customFn> pq(scoville.begin(), scoville.end());
    
    if(pq.top() >= K) {
        return 0;
    }
    
    while(true) {
        min = pq.top();
        if(min >= K) { 
            return cnt;
        }
        
        pq.pop();
        min += pq.top() * 2;
        pq.pop();
        
        if(pq.empty()) {
            if(min >= K) {
                return ++cnt;
            }
            else {
                break;
            }
        }
        pq.emplace(min);
        cnt++;
    }
    return -1;
}