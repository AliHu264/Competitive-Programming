#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair

#define endl '\n'

using namespace std;

vector<int> graph[101];

bool bfs(int start, int end);

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int nodeID = 0;

    unordered_map<string, int> UtoI;
    unordered_map<int, string> ItoU;
    unordered_set<string> urlset;

    for (int i = 0; i < n; i++) {
        string fromURL;
        cin >> fromURL;
        if (urlset.find(fromURL) == urlset.end()) {
            UtoI.insert(mkp(fromURL, nodeID));
            ItoU.insert(mkp(nodeID, fromURL));
            urlset.insert(fromURL);
            nodeID++;
        }
        string str;
        getline(cin, str);
        while (str != "</HTML>") {
            int findindex = str.find("<A HREF=");
            while (findindex >= 0) {
                int findindex2 = str.find("\">", findindex);
                string tourl = str.substr(findindex + 9, findindex2 - (findindex + 9));

                if (urlset.find(tourl) == urlset.end()) {
                    urlset.insert(tourl);
                    UtoI.insert(mkp(tourl, nodeID));
                    ItoU.insert(mkp(nodeID, tourl));
                    nodeID++;
                }
                cout << "Link from " << fromURL << " to " << tourl << endl;
                graph[UtoI[fromURL]].push_back(UtoI[tourl]);
                findindex = str.find("<A HREF=", findindex2);
            }
            getline(cin, str);
        }
    }

    string from, to;
    cin >> from >> to;
    while(from != "The"){
        int start = UtoI[from];
        int end = UtoI[to];
        if (bfs(start,end)){
            cout << "Can surf from "<< from << " to " << to << "." << endl;
        }
        else cout << "Can't surf from " << from << " to " << to << "." << endl;
        cin >> from >> to;
    }
}

bool bfs(int start, int end) {
    queue<int> q;
    bool visited[101]{false};

    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int v:graph[cur]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return visited[end];
}