#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    while (bridge.size() != bridge_length) {
        bridge.push(0);
    }

    int t_weight = 0;               //다리 위 트럭무게
    int time = 0;
    int t_weights_size = truck_weights.size();

    vector<int>::iterator ptr = truck_weights.begin();

    while(t_weights_size != 0)
    {
        int truck = *ptr;

        if (t_weight + truck - bridge.front() > weight) {
            t_weight -= bridge.front();
            bridge.pop();
            bridge.push(0);
            
        }
        else {
            int truck = *ptr;
            t_weight -= bridge.front();
            bridge.pop();
            bridge.push(truck);
            t_weight += truck;
            t_weights_size--;
            ++ptr;
        }

        time++;

    }


    int answer = time + bridge_length;
    return answer;
}

int main() {
    vector<int> truck_weights = { 7,4,5,6};
    int weight = 10;
    int bridge_length = 2;

    int sol = solution(bridge_length, weight, truck_weights);

    cout << sol << endl;
    return 0;
}