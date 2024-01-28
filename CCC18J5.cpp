#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int BFS(int startNode, int distance[]);
int N;
vector<int> connectedEndings;
vector<int> endings;
vector<int>Pages[10001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>> N;

    int distance[N];
    for(int i=0;i<N;i++){
        distance[i]=1;
    }

    for(int i=0;i<N;i++) {//connecting the pages
        int Connections;
        cin >> Connections;

        for (int j=0; j < Connections; j++) {
            int ConnectedTo;
            cin >> ConnectedTo;
            Pages[i].push_back(ConnectedTo-1);
        }
        if (Connections == 0){
            endings.push_back(i);
        }
    }
    //searches their dist
    if (BFS(0,distance)==1){
        cout << "Y" << "\n";
    }
    else cout << "N" << "\n";
    int shortest = INFINITY;
    for(int i: connectedEndings){
        if (distance[i] < shortest){
            shortest = distance[i];
        }
    }
    cout << shortest;
}

int BFS(int startNode, int distance[]){
    queue<int> q;
    bool visited [N];
    for(int i=0;i<N;i++){
        visited[i] = false;
    }
    visited[startNode] = true;
    q.push(startNode);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto v: Pages[cur]){
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
                distance[v] += distance[cur];
            }
        }

        if(find(endings.begin(),endings.end(),cur)!=endings.end()){
            connectedEndings.push_back(cur);
        }
    }

    int count = 0;
    for(int i=0;i<N;i++){
        if (visited[i]){
            count++;
        }
    }
    if (count == N){
        return 1;
    }
    else return 0;
}
