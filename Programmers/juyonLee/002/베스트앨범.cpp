#include <string>
#include <vector>
#include<map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m1;
    map<string, map<int, int>> m2;
    
    for(int i=0; i<genres.size(); i++)
    {
        m1[genres[i]]+=plays[i];
        m2[genres[i]][i]=plays[i];
    }
    
    while(m1.size()>0)
    {
        string genre{};
        int max{0};
        
        for(auto mIt:m1)
        {
            if(max < mIt.second)
            {
                max = mIt.second;
                genre = mIt.first;
            }
        }
        
        for(int i=0; i<2; i++)
        {
            int v=0;
            int idx=-1;
            
            for(auto m2It: m2[genre])
            {
                if(v<m2It.second)
                {
                    v=m2It.second;
                    idx=m2It.first;
                }
            }
            
            if(idx==-1)
                break;
            answer.push_back(idx);
            m2[genre].erase(idx);
        }
        m1.erase(genre);
    }
    return answer;
}



/*
아래 링크 참고
https://mungto.tistory.com/196
*/