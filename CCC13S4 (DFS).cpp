#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[1000005]; bool visited[1000005];

void build_connection(int st, int des){
    adj[st].push_back(des); //connection from st > des
}

void dfs(int cur, int ed){
    visited[cur] = true; //set current node to visited
    for(int v:adj[cur]){ // for each node this node is connected to
        if(!visited[v]) // if not visited yet
            dfs(v, ed); // go visit that node
    }
}

int N, M;

int main() {
    cin >> N >> M; // read in N and M
    for(int i=0;i<M;i++){ // read in the M measurements and build the graph
        int st, ed; cin >> st >> ed;
        build_connection(st, ed); // build connection (directed)
    }
    int p,q; cin >> p >> q;
    dfs(p,q);

    int check = 0;
    if(visited[q]) {
        cout << "yes";
        check = 1;
    }

    memset(visited, false, sizeof visited);
    dfs(q,p);

    if(visited[p]){
        cout<<"no";

    }else if (!visited[p] && check == 0 )
        cout << "unknown";
}