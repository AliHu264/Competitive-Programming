// In order to validate a graph is a tree
// We need to check whether <the number of edges> = <the number of nodes> - 1
#include <iostream>
using namespace std;

int adj[4][4];
int nrofAccessedV = 0;		// This is used to track the number of vertex which are accessed by us
int nrofAccessedE = 0;		// This is used to track the number of the Edges which are accessed by us
bool visited[4];			// Define a visited array to check whether the node is accessed or not.

void DFS(int index, int previousIndex){
	if(visited[index]) return;
	visited[index] = true;
	nrofAccessedV++;

	for(int i = 0; i < 4; i++){
		if ( 1 == adj[index][i] && index != i && index != previousIndex) {
			nrofAccessedE++;
			DFS(i, index);
		}
	}
}

int main() {

	// Read the input from the disk
	for(int i = 0; i < 4; i++){
		cin>>adj[i][0]>>adj[i][1]>>adj[i][2]>>adj[i][3];
	}

	// Initialize the visited array
	for(int i = 0; i < 4; i++){
		visited[i] = false;
	}

	DFS(0,-1);

	if((nrofAccessedV - 1) * 2 == nrofAccessedE && nrofAccessedE != 0){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}
