#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototypes
void nextVert(vector<int>& inclVert, int len, int origin, int target);

// Global variables
vector<vector<int>> A;
int limit;
vector<int> cycleCount;

void cycleCountBacktrack(string inputFormat, string source, int limit = -1) {
    A.clear();
    cycleCount.clear();

    // Read graph from inputFormat and source (not shown here)

    int nVert = A.size();

    if (limit == -1) {
        limit = nVert;
    }
    else {
        limit = min(limit, nVert);
        limit = max(limit, 3);
    }

    cycleCount.assign(nVert, 0);

    // Generate all unique triples of connected vertices
    for (int ix = 0; ix < nVert - 2; ix++) { // v1
        for (int jx = ix + 1; jx < nVert - 1; jx++) { // v2
            if (A[ix][jx] == 1) {
                vector<int> inclVert(nVert, 0);
                inclVert[ix] = 1;
                for (int kx = jx + 1; kx < nVert; kx++) { // v3
                    if (A[kx][ix] == 1) {
                        nextVert(inclVert, 2, jx, kx);
                    }
                }
            }
        }
    }

    cout << "cycles in graph" << endl;
    cout << "size     count" << endl;
    for (int ix = 2; ix < limit; ix++) {
        cout << setw(4) << ix << "  " << setw(8) << cycleCount[ix] << endl;
    }
}

// Extend current path by one additional vertex
void nextVert(vector<int>& inclVert, int len, int origin, int target) {
    // Get candidates for extension
    for (int ca = 0; ca < inclVert.size(); ca++) {
        if (inclVert[ca] == 1 && A[origin][ca] == 1) {
            if (ca == target) {
                cycleCount[len]++;
            }
            else if (len < limit) {
                vector<int> inclVert1 = inclVert;
                inclVert1[ca] = 0; // Block vertex just added to path
                nextVert(inclVert1, len + 1, ca, target);
            }
        }
    }
}

int main() {
    string inputFormat = ""; // Specify your input format
    string source = "";      // Specify your source

    cycleCountBacktrack(inputFormat, source);

    return 0;
}
