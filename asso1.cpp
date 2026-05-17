#include <iostream>
using namespace std;

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;
int found;

//--------------------------------------
// Reset visited
//--------------------------------------
void reset()
{
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    found = 0;
}

//--------------------------------------
// DFS Traversal (Recursive)
//--------------------------------------
void DFS_traversal(int node)
{
    cout << node << " ";
    visited[node] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[node][i] == 1 && visited[i] == 0)
        {
            DFS_traversal(i);
        }
    }
}

//--------------------------------------
// DFS Search (Recursive)
//--------------------------------------
void DFS_search(int node, int key)
{
    visited[node] = 1;

    if(node == key)
    {
        found = 1;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(adj[node][i] == 1 && visited[i] == 0)
        {
            DFS_search(i, key);
        }
    }
}

//--------------------------------------
// BFS Traversal
//--------------------------------------
void BFS_traversal(int start)
{
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear)
    {
        int current = queue[front++];
        cout << current << " ";

        for(int i = 0; i < n; i++)
        {
            if(adj[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

//--------------------------------------
// BFS Search
//--------------------------------------
void BFS_search(int start, int key)
{
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear)
    {
        int current = queue[front++];

        if(current == key)
        {
            found = 1;
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(adj[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

//--------------------------------------
// Main Menu
//--------------------------------------
int main()
{
    int choice, u, v, start, key;

    cout << "Enter number of vertices: ";
    cin >> n;

    // initialize
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Edge\n";
        cout << "2. DFS Traversal\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Search\n";
        cout << "5. BFS Search\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                adj[u][v] = adj[v][u] = 1;
                break;

            case 2:
                reset();
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "DFS: ";
                DFS_traversal(start);
                break;

            case 3:
                reset();
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "BFS: ";
                BFS_traversal(start);
                break;

            case 4:
                reset();
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "Enter element to search: ";
                cin >> key;
                DFS_search(start, key);

                if(found)
                    cout << "Element Found\n";
                else
                    cout << "Element Not Found\n";
                break;

            case 5:
                reset();
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "Enter element to search: ";
                cin >> key;
                BFS_search(start, key);

                if(found)
                    cout << "Element Found\n";
                else
                    cout << "Element Not Found\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 6);

    return 0;
}