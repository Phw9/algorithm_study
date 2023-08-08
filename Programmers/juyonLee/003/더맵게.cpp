#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //데이터 자동정렬되어서 우선순위큐 사용.
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    
    while(pq.size()>1 && pq.top() < K)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        pq.push(first+(second*2));
        answer+=1;
    }
    
    //모든 음식 스코빌 지수 k이상일 때가 없음.
    if(pq.top()<K)
        return -1;
    
    return answer;
}