#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> GetDivisor(const int& num) {
    vector<int> divisor;
    int temp;
    divisor.emplace_back(1);
    divisor.emplace_back(num);
    for(int i = 2; i <= int(sqrt(double(num))); i++) {
        if(num % i == 0) {
            divisor.emplace_back(i);            
            temp = num/i;
            divisor.emplace_back(temp);
        }
    }
    sort(divisor.begin(),divisor.end());
    return divisor;
}

struct customFn {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs;
    }
};

// yellow가 mxn이 되면 brown은 (m+1)+(n+1) 개가 필요하고, return 값은 (m+2)x(n+2)가됨 이 때 (m>=n)
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> divisor;
    
    divisor = GetDivisor(yellow);
    for(int i = 0; i < divisor.size(); i++) {
        for(int j = i+1; j < divisor.size(); j++) {
            if(2*(divisor.at(i)+divisor.at(j)+2) == brown && divisor.at(i)*divisor.at(j) == yellow) {
                answer.emplace_back(divisor.at(i)+2);
                answer.emplace_back(divisor.at(j)+2);
                sort(answer.begin(), answer.end(), customFn());
                return answer;
            }
        }
    }
    return answer;
}