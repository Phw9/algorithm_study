#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    auto next_itr = phone_book.begin() + 1;
    for(auto phone_num : phone_book) {
        if(next_itr != phone_book.end() && (*next_itr).find(phone_num) == 0) return false;
        next_itr++;
    }
    
    return true;
}