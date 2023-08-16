#include <string>
#include <vector>
#include<math.h>
#include<set>
#include<algorithm>

using namespace std;

bool isPrime(int n)
{
    if(n<2)
        return false;
    
    for(int i=2; i<sqrt(n); i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    vector<int> n;
    
    for(int i=0;i<numbers.size();i++)
        v.push_back(numbers[i]);
    sort(v.begin(), v.end());
    
    do
    {
        string tmp="";
        for(int i=0;i<v.size(); i++)
        {
            tmp.push_back(v[i]);
            n.push_back(stoi(tmp));
        }
        
    }while(next_permutation(v.begin(), v.end()));
    
    //중복 지우기
    sort(n.begin(), n.end());
    n.erase(unique(n.begin(), n.end()), n.end());
    
    for(int i=0; i<n.size(); i++)
    {
        if(isPrime(n[i]))
            answer+=1;
    }
    return answer;
}

/*
1. numbers로 만들 수 있는 숫자의 경우의 수 구하기(1~7 미만)
1.1. 문자열 split
1.2. split한 문자열 합쳐서 숫자 경우의 수 만들기
1.2.3. 배열로 담아서 중복제거 이슈 해결하기.
1.2.1. 재귀로 조합을 짤까..더 간단한 방법 있나?
2. 만들어진 숫자들의 소수 판정.
2.1. 소수 판정 알고리즘(에라토스테네스의 체였나..그거)

*/