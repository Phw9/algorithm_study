#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    multiset<string> completionSet;
    multiset<string> participantSet;
    for(auto c : completion) {
        completionSet.emplace(c);
    }
    for(auto p : participant) {
        participantSet.emplace(p);
    }
    auto iterCompletion = completionSet.begin();
    auto iterParticipant = participantSet.begin();
    while(iterParticipant != participantSet.end()) {
        if(iterCompletion == completionSet.end() || *iterCompletion != *iterParticipant) {
            return *iterParticipant;
        }
        iterCompletion++;
        iterParticipant++;
    }
}

