#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for(int i=0; i<citations.size(); i++)
    {
        int h=citations.size()-i;
        if(citations[i] >= h) return h;
    }
    
    return answer;
}
/*
h번 이상 인용된 논문이 h편 이상

k번 idx 탐색 : idx를 포함해서 남은 논문의 수가 n-k개.
index 번호가 커질수록 h값 작아짐.
*/