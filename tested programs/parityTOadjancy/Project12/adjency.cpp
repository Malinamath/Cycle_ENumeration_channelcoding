
#include <iostream>
#include <vector>

using namespace std;

// Function to create the adjacency matrix of the Tanner graph
vector<vector<int>> createAdjacencyMatrix(vector<vector<int>>& parityCheckMatrix)
{
    int m = parityCheckMatrix.size(); // number of rows of parity check matrix
    int n = parityCheckMatrix[0].size(); // number of columns of parity check matrix

    vector<vector<int>> adjacencyMatrix(m + n, vector<int>(m + n, 0)); // initialize adjacency matrix with zeros

    // Iterate through each row of parity check matrix
    for (int i = 0; i < m; i++)
    {
        // Iterate through each column of parity check matrix
        for (int j = 0; j < n; j++)
        {
            // If the entry in the parity check matrix is non-zero, add an edge in the Tanner graph
            if (parityCheckMatrix[i][j] == 1)
            {
                adjacencyMatrix[i][m + j] = 1;
                adjacencyMatrix[m + j][i] = 1;
            }
        }
    }

    return adjacencyMatrix;
}

int main()
{
    vector<vector<int>> parityCheckMatrix = { {0, 1,  1, 0}, {1, 0, 1, 1}, {1,  1, 0,  1} };
    vector<vector<int>> adjacencyMatrix = createAdjacencyMatrix(parityCheckMatrix);

    // Print the adjacency matrix
    for (int i = 0; i < adjacencyMatrix.size(); i++)
    {
        for (int j = 0; j < adjacencyMatrix[0].size(); j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//0 0 0 0 1 1 0
//0 0 0 1 0 1 1
//0 0 0 1 1 0 1
//0 1 1 0 0 0 0
//1 0 1 0 0 0 0
//1 1 0 0 0 0 0
//0 1 1 0 0 0 0