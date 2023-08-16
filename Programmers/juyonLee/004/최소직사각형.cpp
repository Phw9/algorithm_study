#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w=0;
    int h=0;
    //가로/세로 최대한 짧게. 긴 것 중 긴거 * 짧은 것 중 긴거
    for(int i=0; i<sizes.size(); i++)
    {
        w = max(w, max(sizes[i][0], sizes[i][1]));
        h = max(h, min(sizes[i][0], sizes[i][1]));
    }
    answer = w*h;
    return answer;
}