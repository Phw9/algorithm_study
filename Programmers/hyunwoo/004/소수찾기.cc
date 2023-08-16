#include <string>
#include <vector>
#include <set>
using namespace std;

bool IsPrime(const int& num) {
    if(num == 1) return false;
    if(num == 2) return true;
    for(int i = 2; i < num; i++) {
        if((num % i) == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0, temp;
    set<int> nums;
    
    for(int i = 0; i < numbers.length(); )
    return answer;
}