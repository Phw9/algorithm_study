#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int weightSum = 0, cnt = 0;
    
    deque<pair<int,int>> onBridge;
    
    for(const auto& tw : truck_weights) {
        weightSum += tw;
        if(weightSum <= weight) {
            // ranged for 사용하면 random access가 안되는 이유? => 값이 변하지 않음
            pair<int,int> temp{tw, bridge_length};
            onBridge.emplace_back(move(temp));
            for(int i = 0; i <onBridge.size(); i++) {
                onBridge.at(i).second--;
            }
            cnt++;
        }
        else {
            int res = onBridge.front().second;
            // ranged for 사용하면 random access가 안되는 이유?
            for(int i = 0; i < onBridge.size(); i++) {
                onBridge.at(i).second -= res;
            }
            cnt += res + 1;
            pair<int,int> temp{tw, bridge_length - 1};
            onBridge.emplace_back(move(temp));
            cout << "res: " << res << endl;
        }
        cout << "cnt: " << cnt << endl;
        cout << weightSum << ", ";
        if(onBridge.front().second == 0) {
            weightSum -= onBridge.front().first;
            onBridge.pop_front();
        }
        cout << weightSum << endl;
    }

    return cnt + bridge_length;
}