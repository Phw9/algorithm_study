#include <string>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

struct compare
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, j = 0, time = 0;
    
    
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; 
    
    //대기열 x
    while (j < jobs.size() || !pq.empty()) {
        //대기열 공간 존재, 현재시간보다 작은 대기열
        if (jobs.size() > j && time >= jobs[j][0]) {
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1];
            //대기 시간만큼 추가(현재시간 - 들어온 시간)
            answer += time - pq.top()[0];

            pq.pop();
        }
        //비어있는 큐
        else 
            time = jobs[j][0];
    }
    //평균
    return answer / jobs.size();
}