#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> end_day;
    
    for(int i=0; i<progresses.size(); i++)
    {
        int day = 0;
        while(progresses[i] < 100)
        {
            day+=1;
            progresses[i] += speeds[i];
        }
        end_day.push(day);
    }
    
    while(!end_day.empty())
    {
        int first_day = end_day.front();
        int progress_num = 1;
        end_day.pop();
        
        while((!end_day.empty() && (end_day.front() <= first_day)))
        {
            end_day.pop();
            progress_num+=1;
        }
        answer.push_back(progress_num);
    }
    
    return answer;
}


/*
참고 링크
https://mjmjmj98.tistory.com/54

기능 개발에 걸리는 시간을 큐에 담는 것까지는 알았지만, 키워드가 큐라서 큐에 담았지 다음 이유를 생각하지 못함.
큐의 앞에 위치한 것=가장 먼저 배포되는 기능의 개발 완료 날짜. 
값을 담은 후 해당 원소보다 값이 작은 원소들은 기능개발이 끝났으므로 같이 배포.
*/