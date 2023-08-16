#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int n1 = 0, n2 = 0, n3 = 0;
    int temp;
    for(int i = 0; i < answers.size(); i++) {
        if(answers.at(i) == (i % 5) + 1) { n1++; }
        switch(i % 8) {
            case 1: if(answers.at(i) == 1) { n2++; } break;
            case 3: if(answers.at(i) == 3) { n2++; } break;
            case 5: if(answers.at(i) == 4) { n2++; } break;
            case 7: if(answers.at(i) == 5) { n2++; } break;
            default :
                if(answers.at(i) == 2) { n2++; } break;
        }
        switch(i % 10) {
            case 0:
            case 1: if(answers.at(i) == 3) { n3++; } break;
            case 2:
            case 3: if(answers.at(i) == 1) { n3++; } break;
            case 4: 
            case 5: if(answers.at(i) == 2) { n3++; } break;
            case 6:
            case 7: if(answers.at(i) == 4) { n3++; } break;
            case 8:
            case 9: if(answers.at(i) == 5) { n3++; } break;
        }
    }
    temp = max(n1, max(n2, n3));
    if(temp == n1) answer.emplace_back(1);
    if(temp == n2) answer.emplace_back(2);
    if(temp == n3) answer.emplace_back(3);
    
    return answer;
}