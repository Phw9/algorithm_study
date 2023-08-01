#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt = 0;
    int days = 1;
    
    for(int i = 0; i < speeds.size(); i++) {
        progresses.at(i) += days * speeds.at(i);
        if(progresses.at(i) >= 100) {
            cnt++;
            if(i == speeds.size() - 1) {
                answer.push_back(cnt);
            }
            continue;
        }
        else {
            if(cnt != 0) {
                answer.push_back(cnt);
                cnt = 0;
            }
        }
        
        while(progresses.at(i) < 100) {
            progresses.at(i) += speeds.at(i);
            days++;
        }
        cnt++;
        
        if(i == speeds.size() - 1) {
            answer.push_back(cnt);
        }
    }
    
    return answer;
}