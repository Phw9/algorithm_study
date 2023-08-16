#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

static int cnt = 0;
struct customFn {
    bool operator()(const vector<int> lhs, const vector<int> rhs) const { 
        if(lhs.at(0) >= cnt) {
            return (cnt + lhs.at(1) - lhs.at(0)) > (cnt + rhs.at(1) - rhs.at(0));
        }
        else {
            return (cnt + lhs.at(1) - lhs.at(0)) > (cnt + rhs.at(1) - rhs.at(0));
        }
        
    }
};

int duration(vector<int> job) {
    int res = 0;
    res = cnt + job.at(1) - job.at(0);
    return res;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, customFn> pq(jobs.begin(), jobs.end());
    while(!pq.empty()) {
        answer += cnt + pq.top().at(1) - pq.top().at(0);
        cnt += pq.top().at(1);
        pq.pop();
    }
    
    return answer / jobs.size();
}