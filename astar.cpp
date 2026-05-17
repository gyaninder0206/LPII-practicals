// #include <iostream>
// #include<queue>
// #include<vector>
// #include<map>

// using namespace std;

// struct State {
//     string node;
//     int gcost; // actual cost from start node g(n)
//     int fcost;// total estimated cost f(n)=g(n)+h(n)
//     string path;// stores complete path
// //Simple Analogy
// // Think of one node record like:
// // Field	Value
// // Node	    B
// // gCost	3
// // fCost	7
// // Path	A → B
// // This complete record is called:
// // State

//    bool operator<(const State &other) const {
//     return fcost >other.fcost;

//    }
// };

// map<string, vector<pair<string,int>>> graph;
// map<string,int> heuristic;

// void astar(string start,string goal) {
//     priority_queue<State> pq;
//     // insert starting node 
//     pq.push({
//         start,
//         0,
//         heuristic[start],
//         start
//     });

//     while(!pq.empty()) {
//         State current=pq.top();
//         // smallest fcost we have
//         pq.pop();
//         cout<<"Visited Node:"<<current.node<<endl;

//         if(current.node==goal){
//             cout<<"\nGoal Reached"<<endl;
//             cout<<"Path "<<current.path<<endl;
//             cout<<"Total Cost:"<<current.gcost<<endl;

//             return;
//         }

//         // loop through neighbours
//         for(auto neighbour : graph[current.node]) {
//             // loop means go through all the neighbours of the current node
//             string next = neighbour.first;//neighbor = ("B",1) then next = "B"
//             int edgecost= neighbour.second;
//             int  newgcost=current.gcost+edgecost;
//             int newfcost = newgcost+heuristic[next];// f(n)=g(n)+h(n)

//             // insert new state 
//             pq.push({
//                 next,
//                 newgcost,
//                 newfcost,
//                 current.path + " -> " + next
//             });

//         }
//     }
// }

// int main()
// {
//     graph["A"].push_back({"B",1});
//     graph["A"].push_back({"C",4});

//     graph["B"].push_back({"D",2});

//     graph["C"].push_back({"G",3});

//     graph["D"].push_back({"G",1});

//     heuristic["A"] = 6;
//     heuristic["B"] = 4;
//     heuristic["C"] = 2;
//     heuristic["D"] = 1;
//     heuristic["G"] = 0;

//     astar("A","G");

//     return 0;
// }


#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct Node {

    string city;
    int g;      // actual cost
    int f;      // total cost = g + h
    string path;

    // Min Priority Queue
    bool operator<(const Node &other) const {

        return f > other.f;
    }
};

map<string, vector<pair<string,int>>> graph;
map<string,int> heuristic;

//--------------------------------------
// A* Algorithm
//--------------------------------------

void astar(string start, string goal) {

    priority_queue<Node> pq;

    // Insert start node

    pq.push({
        start,
        0,
        heuristic[start],
        start
    });

    while(!pq.empty()) {

        Node current = pq.top();
        pq.pop();

        cout << "Visited Node: "
             << current.city << endl;

        // Goal Found

        if(current.city == goal) {

            cout << "\nGoal Reached\n";

            cout << "Path: "
                 << current.path << endl;

            cout << "Total Cost: "
                 << current.g << endl;

            return;
        }

        // Explore neighbours

        for(auto neighbour : graph[current.city]) {

            string next = neighbour.first;

            int edgeCost = neighbour.second;

            int newG = current.g + edgeCost;

            int newF = newG + heuristic[next];

            pq.push({
                next,
                newG,
                newF,
                current.path + " -> " + next
            });
        }
    }

    cout << "Path not found\n";
}

//--------------------------------------
// MAIN MENU
//--------------------------------------

int main() {

    int nodes, edges;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    // Input node names and heuristic values

    for(int i=0; i<nodes; i++) {

        string name;
        int h;

        cout << "\nEnter node name: ";
        cin >> name;

        cout << "Enter heuristic value: ";
        cin >> h;

        heuristic[name] = h;
    }

    // Input edges

    cout << "\nEnter number of edges: ";
    cin >> edges;

    for(int i=0; i<edges; i++) {

        string u, v;
        int cost;

        cout << "\nEnter source node: ";
        cin >> u;

        cout << "Enter destination node: ";
        cin >> v;

        cout << "Enter edge cost: ";
        cin >> cost;

        graph[u].push_back({v,cost});
    }

    // Start and Goal

    string start, goal;

    cout << "\nEnter start node: ";
    cin >> start;

    cout << "Enter goal node: ";
    cin >> goal;

    // Run A*

    astar(start, goal);

    return 0;
}