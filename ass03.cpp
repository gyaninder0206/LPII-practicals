#include <iostream>
using namespace std;

#define MAX 10
#define INF 9999

//--------------------------------------
// 1. Selection Sort (Greedy)
//--------------------------------------
void selectionSort()
{
    int n, arr[20];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

//--------------------------------------
// 2. Job Scheduling (Greedy)
//--------------------------------------
void jobScheduling()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    int profit[20], deadline[20], slot[20];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter profit and deadline for job " << i+1 << ": ";
        cin >> profit[i] >> deadline[i];
    }

    // sort jobs by profit (descending)
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(profit[i] < profit[j])
            {
                swap(profit[i], profit[j]);
                swap(deadline[i], deadline[j]);
            }
        }
    }

    // initialize slots
    for(int i = 0; i < n; i++)
        slot[i] = -1;
  
    int totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = deadline[i] - 1; j >= 0; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = i;
                totalProfit += profit[i];
                break;
            }
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
}

//--------------------------------------
// 3. Dijkstra Algorithm (Greedy)
//--------------------------------------
void dijkstra()
{
    int n, graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    int dist[MAX], visited[MAX];

    for(int i = 0; i < n; i++)
    {
        dist[i] = graph[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for(int i = 1; i < n; i++)
    {
        int min = INF, u;

        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances:\n";
    for(int i = 0; i < n; i++)
        cout << start << " -> " << i << " = " << dist[i] << endl;
}

//--------------------------------------
// MAIN MENU
//--------------------------------------
int main()
{
    int choice;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Job Scheduling\n";
        cout << "3. Dijkstra Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                selectionSort();
                break;

            case 2:
                jobScheduling();
                break;

            case 3:
                dijkstra();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}




    