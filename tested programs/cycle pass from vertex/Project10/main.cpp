#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000; // maximum number of vertices in graph

int N; // number of vertices in graph
bool G[MAXN][MAXN]; // adjacency matrix of graph
bool visited[MAXN]; // whether a vertex has been visited
vector<int> path; // current path being explored
int girth; // length of cycle being searched for
int num_cycles;