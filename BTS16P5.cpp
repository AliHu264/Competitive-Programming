#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, C, K;
vector<int> nrofCherries;
vector<int> accumulatedCherrires;
vector<int> accumulatedWeight;
vector<int> accumulatedCuts;
map< int, vector< pair<int, int> > > adjList;

void dfs(int cur, int parent){
    accumulatedCherrires[cur] = nrofCherries[cur];

    vector< pair<int, int> > connects = adjList[cur];
    for(long unsigned int i = 0; i < connects.size(); i++){
        pair<int, int> connect = connects.at(i);
        if (connect.first != parent){
            dfs(connect.first, cur);

            accumulatedCherrires[cur] += accumulatedCherrires[connect.first];
            accumulatedWeight[cur] += accumulatedWeight[connect.first] + connect.second;
            accumulatedCuts[cur] += accumulatedCuts[connect.first];

            if (accumulatedWeight[connect.first] + connect.second <= K && accumulatedCherrires[connect.first] >= C){
                accumulatedCuts[cur] += 1;
            }
        }
    }
}

int main(){
    cin >> N >> C >> K;

    for(int i = 0; i < N; i++) {
        int nrofCherry = 0;
        cin >> nrofCherry;
        nrofCherries.push_back(nrofCherry);
        accumulatedCherrires.push_back(0);
        accumulatedWeight.push_back(0);
        accumulatedCuts.push_back(0);
    }

    for (int i = 0, a, b, w; i < N - 1; i++){
        cin >> a >> b >> w;
        adjList[a - 1].push_back(pair<int, int>(b - 1, w));
        adjList[b - 1].push_back(pair<int, int>(a - 1, w));
    }

    dfs(0, -1);

    cout<<accumulatedCuts[0];
}