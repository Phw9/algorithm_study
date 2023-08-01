#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int curIdx = 0;
    int sum = 0;
    queue<int> q;

    while(1)
    {
        if(curIdx == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }

        answer+=1;

        int curWeight = truck_weights[curIdx];

        if(q.size() == bridge_length)
        {
            sum -= q.front();
            q.pop();
        }

        if(sum + curWeight <= weight)
        {
            sum += curWeight;
            q.push(curWeight);
            curIdx+=1;
        }
        else
            q.push(0);
    }


    return answer;
}