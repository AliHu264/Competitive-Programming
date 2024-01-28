#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> adj[1000005];

void build_connection(int st, int des){
    adj[st].push_back(des); //connection from st > des
}

int bfs(int start, int end){
    bool visited[1000005]{false};
//    memset(visited, false, sizeof visited);
    queue<int> q;
    visited[start] = true; //set current node to visited
    q.push(start);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v:adj[cur]) { // for each node this node is connected to
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    if (visited[end]){
        return true;}
    return false;
}


int N, M;

int main() {

    cin >> N >> M;
    for(int i=0;i<M;i++){
        int st, ed; cin >> st >> ed;
        build_connection(st, ed);
    }
    int start,des; cin >> start >> des;

    if(bfs(start,des))
        cout << "yes";
    else if(bfs(des,start))
        cout << "no";
    else
        cout << "unknown";
}





