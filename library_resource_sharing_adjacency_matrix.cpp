#include <iostream>
#include <string>
using namespace std;

#define V 6

int main()
{
    // Adjacency matrix:
    // 1 = direct resource-sharing connection
    // 0 = no direct connection
    int graph[V][V] = {
        {0, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 0}
    };

    string library[V] = {
        "Main Library",
        "Science Library",
        "Engineering Library",
        "Medical Library",
        "Digital Library",
        "Research Library"
    };

    // Display the adjacency matrix.
    cout << "LIBRARY RESOURCE-SHARING NETWORK\n";
    cout << "\nAdjacency Matrix:\n\n";
    cout << "    A B C D E F\n";

    for (int i = 0; i < V; i++)
    {
        cout << char('A' + i) << "   ";

        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << '\n';
    }

    // Display each undirected direct connection only once.
    cout << "\nDirect Connections Between Libraries:\n";

    int connectionCount = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] == 1)
            {
                cout << library[i] << " <--> "
                     << library[j] << '\n';

                connectionCount++;
            }
        }
    }

    cout << "\nTotal Direct Connections: "
         << connectionCount << '\n';

    return 0;
}
