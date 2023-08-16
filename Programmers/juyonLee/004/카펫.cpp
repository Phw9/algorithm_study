#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int c=brown+yellow;
    
    for(int i=c/2; i>0; i--)
    {
        if(c%i==0)
        {
            int n1=i;
            int n2=c/i;
            
            if((n1-2)*(n2-2) == yellow)
            {
                answer.push_back(n1);
                answer.push_back(n2);
                break;
            }
        }
    }
    
    return answer;
}

//테두리 1줄 갈색 격자이므로 w-2 h-2 후 w*h=노란격자
//카펫 약수 구하면서 w-2 h-2가 y와 같은지 확인