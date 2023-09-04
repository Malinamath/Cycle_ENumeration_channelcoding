#include <iostream>
#include <vector>
#include <functional>
using namespace std;
// this function takes adjency matrix and gives the number of cycles through from a vertex
const int MAXN = 1000; // maximum number of vertices in graph

int N; // number of vertices in graph
bool G[MAXN][MAXN]; // adjacency matrix of graph
bool visited[MAXN]; // whether a vertex has been visited
vector<int> path; // current path being explored
int girth; // length of cycle being searched for
int num_cycles; // number of cycles found

int count_cycles(bool G[][MAXN], int N, int start, int girth) {
    int num_cycles = 0;
    bool visited[MAXN];
    vector<int> path;

    // recursive DFS function to find cycles of length girth
    function<void(int)> find_cycles = [&](int v) {
        visited[v] = true;
        path.push_back(v);

        // check if we have a cycle of length girth
        if (path.size() == girth && G[v][start]) {
            num_cycles++;
        }

        // continue exploring neighbors if path length is less than girth
        if (path.size() < girth) {
            for (int i = 0; i < N; i++) {
                if (G[v][i] && !visited[i]) {
                    find_cycles(i);
                }
            }
        }

        visited[v] = false;
        path.pop_back();
    };

    // initialize visited array and call DFS
    fill(visited, visited + N, false);
    find_cycles(start);

    return num_cycles;
}



int main() {
    // read in graph from adjacency matrix
    int N;
    bool G[MAXN][MAXN];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }

    // get input vertex and girth
    int start, girth;
    cin >> start >> girth;

    // find cycles starting from input vertex
    int num_cycles = count_cycles(G, N, start, girth)/2;  // because a cycle is read in two direction

    cout << "Number of cycles of length " << girth << " starting from vertex " << start << ": " << num_cycles << endl;

    return 0;
}
//input
//7
//0 0 0 0 1 1 0
//0 0 0 1 0 1 1
//0 0 0 1 1 0 1
//0 1 1 0 0 0 0
//1 0 1 0 0 0 0
//1 1 0 0 0 0 0
//0 1 1 0 0 0 0
//3 4
//out put
//Number of cycles of length 4 starting from vertex 3: 2




