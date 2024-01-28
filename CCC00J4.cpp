#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int,double>> streams;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int water;
        cin >> water;
        streams.emplace_back(i, water);
    }
    int input;
    while(true) {
        cin >> input;
        int streamN, leftPercent;

        if (input == 77) {//break
            break;
        } else if (input == 99) {//split
            cin >> streamN >> leftPercent;
            for (int i = streamN; i < streams.size(); i++) {
                streams[i].first++;
            }
            streams.emplace_back(streamN, streams[streamN - 1].second * ((double)(100 - leftPercent)/100));
            streams[streamN - 1].second *= (double)(leftPercent)/100;
            sort(streams.begin(), streams.end());
        }
        else if (input == 88) {//combine
            cin >> streamN;
            streams[streamN-1].second += streams[streamN].second;
            streams.erase(streams.begin() + streamN);
            for(int i = streamN;i<streams.size();i++){
                streams[i].first--;
            }
        }
    }
    for (auto &stream: streams){
        cout << round(stream.second) << " ";
    }
}



