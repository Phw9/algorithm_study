#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;
#include <iostream>

struct customFn {
    bool operator()(const int lhs, const int rhs) const {
        return lhs > rhs;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> genresScore;
    multimap<int,string,customFn> totalScore;
    unordered_map<string, multimap<int,int,customFn>> bestAlbum;
    for(int i = 0; i < genres.size(); i++) {
        genresScore[genres.at(i)] += plays.at(i);
        bestAlbum[genres.at(i)].insert(std::make_pair(plays.at(i), i));
    }
    // 1. 속한 노래가 많이 재생된 장르 정렬
    for(auto iter = genresScore.begin(); iter != genresScore.end(); iter++) {
        totalScore.emplace((*iter).second, (*iter).first);
    }
    // 2. 장르 내에서 많이 재생된 노래를 먼저 수록(두개)
    for(auto iter = totalScore.begin(); iter != totalScore.end(); iter++) {
        auto biter = bestAlbum.find((*iter).second)->second.begin();
        auto biter_next = bestAlbum.find((*iter).second)->second.begin()++;
        for(int i = 0; i < 2; i++) {
            if((*biter).first == (*biter_next).first) {
                answer.push_back(min((*biter).second, (*biter_next).second));
            }
            else {
                answer.push_back((*biter).second);
            }
            biter++;
            biter_next++;
            // 빠졌던것 장르에 속한 곡이 하나라면, 하나의 곡만 선택
            if(biter == bestAlbum.find((*iter).second)->second.end()) {
                break;
            }
        }
    }
    
    return answer;
}
