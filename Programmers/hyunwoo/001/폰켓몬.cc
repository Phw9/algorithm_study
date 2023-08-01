#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> phoneKetMonSet(nums.begin(), nums.end());

    answer = min(nums.size() / 2, phoneKetMonSet.size());
    
    return answer;
}
