#include<string>

using namespace std;

bool solution(string s)
{
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s.at(i) == '(') {
            cnt++;
        }
        else if(s.at(i) == ')') {
            cnt--;
        }
        else return false;
        
        if(cnt < 0) {
            return false;
        }
    }
    return cnt == 0;
}
