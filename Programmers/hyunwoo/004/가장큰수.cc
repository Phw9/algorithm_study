#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int getFirstPlace(int num) {
    while(num/10 != 0) {
        num /= 10;
    }
    return num;
}

vector<int> getDigit(int num) {
    int digit;
    vector<int> temp;
    temp.reserve(4);
    while(num/10 != 0 || num%10 != 0) {
        digit = num % 10;
        num /= 10;
        temp.emplace_back(digit);
    }
    return temp;
}

struct customFn {
    bool operator()(int lhs, int rhs) { 
        
        vector<int> lv = getDigit(lhs);
        vector<int> rv = getDigit(rhs);
        
        int ltemp, rtemp;
        while(lv.size() != 0 || rv.size() != 0) {
            ltemp = lv.back();
            rtemp = rv.back();
            if(ltemp > rtemp) {
                return true;
            }
            else if (ltemp < rtemp){
                return false;
            }
            lv.pop_back();
            rv.pop_back();
        }
        
        while(lv.size() != 0) {
            if(lv.back() >= rtemp) {
                return true;
            }
            else {
                return false;
            }
        }
        
        while(rv.size() != 0) {
            if(rv.back() >= ltemp) {
                return false;
            }
            else {
                return true;
            }
        }
    }
};

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),customFn());
    for(auto num : numbers) {
        answer += to_string(num);
    }
    return answer;
}