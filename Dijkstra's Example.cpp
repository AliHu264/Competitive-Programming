#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
//// link to the picture of the graph: https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg


using namespace std;

struct SortSecond ////comparator to sort a priority queue of pairs by second element
{
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};

int printSolution(int dist[]) { // function to print distances from src
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < 9; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(vector<pair<int, int>> graph[], int src) { ////dijkstra's algorithm
    int dist[9]; // The output array.  dist[i] will hold the shortest distance from source to i
    //// distance array with a size of x, with x being the number of nodes

    fill(dist,dist + sizeof(dist)/sizeof(dist[0]),INT_MAX);

    dist[src] = 0;

    // Find shortest path for all vertices
    //// replaced with priority queue

    priority_queue<pair<int, int>, vector<pair<int, int>>, SortSecond> pq;
    //// queue elements: nodeID, weight

    pq.push(make_pair(src, 0));
    //// push source/start NodeID with distance of 0 (obviously)

    while(!pq.empty()){////bfs
        pair<int,int> pv = pq.top(); // NodeID, weight
        pq.pop();

        for(pair<int,int> p: graph[pv.first]){
            if (dist[p.first] > pv.second + p.second){
                dist[p.first] = pv.second + p.second;
                pq.push(make_pair(p.first, dist[p.first]));
            }
        }

    }
    // print the constructed distance array
    printSolution(dist);
}
int main() {
    //// graph in 2d array
    int graph[9][9] = {{0, 4,  0, 0,  0,  0,  0, 8,  0},
                       {4, 0,  8, 0,  0,  0,  0, 11, 0},
                       {0, 8,  0, 7,  0,  4,  0, 0,  2},
                       {0, 0,  7, 0,  9,  14, 0, 0,  0},
                       {0, 0,  0, 9,  0,  10, 0, 0,  0},
                       {0, 0,  4, 14, 10, 0,  2, 0,  0},
                       {0, 0,  0, 0,  0,  2,  0, 1,  6},
                       {8, 11, 0, 0,  0,  0,  1, 0,  7},
                       {0, 0,  2, 0,  0,  0,  6, 7,  0}};

    //// this graph will use an array vectors
    vector<pair<int, int>> Graph[9];

    Graph[0].emplace_back(1, 4);
    Graph[0].emplace_back(7, 8);

    Graph[1].emplace_back(0, 4);
    Graph[1].emplace_back(2, 8);
    Graph[1].emplace_back(7, 11);

    Graph[2].emplace_back(1, 8);
    Graph[2].emplace_back(3, 7);
    Graph[2].emplace_back(5, 4);
    Graph[2].emplace_back(8, 2);

    Graph[3].emplace_back(2,7);
    Graph[3].emplace_back(4,9);
    Graph[3].emplace_back(5,14);

    Graph[4].emplace_back(3,9);
    Graph[4].emplace_back(5,10);

    Graph[5].emplace_back(2,4);
    Graph[5].emplace_back(3,14);
    Graph[5].emplace_back(4,10);
    Graph[5].emplace_back(6,2);

    Graph[6].emplace_back(5,2);
    Graph[6].emplace_back(7,1);
    Graph[6].emplace_back(8,6);

    Graph[7].emplace_back(0,8);
    Graph[7].emplace_back(1,11);
    Graph[7].emplace_back(6,1);
    Graph[7].emplace_back(8,7);

    Graph[8].emplace_back(2,2);
    Graph[8].emplace_back(6,6);
    Graph[8].emplace_back(7,7);

    dijkstra(Graph, 0);

}