#include <iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

struct State {
    string node;
    int gcost; // actual cost from start node g(n)
    int fcost;// total estimated cost f(n)=g(n)+h(n)
    string path;// stores complete path
//Simple Analogy
// Think of one node record like:
// Field	Value
// Node	    B
// gCost	3
// fCost	7
// Path	A → B
// This complete record is called:
// State

   bool operator<(const State &other) const {
    return fcost >other.fcost;

   }
};

map<string, vector<pair<string,int>>> graph;
map<string,int> heuristic;

void astar(string start,string goal) {
    priority_queue<State> pq;
    // insert starting node 
    pq.push({
        start,
        0,
        heuristic[start],
        start
    });

    while(!pq.empty()) {
        State current=pq.top();
        // smallest fcost we have
        pq.pop();
        cout<<"Visited Node:"<<current.node<<endl;

        if(current.node==goal){
            cout<<"\nGoal Reached"<<endl;
            cout<<"Path "<<current.path<<endl;
            cout<<"Total Cost:"<<current.gcost<<endl;

            return;
        }

        // loop through neighbours
        for(auto neighbour : graph[current.node]) {
            // loop means go through all the neighbours of the current node
            string next = neighbour.first;//neighbor = ("B",1) then next = "B"
            int edgecost= neighbour.second;
            int  newgcost=current.gcost+edgecost;
            int newfcost = newgcost+heuristic[next];// f(n)=g(n)+h(n)

            // insert new state 
            pq.push({
                next,
                newgcost,
                newfcost,
                current.path + " -> " + next
            });

        }
    }
}

int main()
{
    graph["A"].push_back({"B",1});
    graph["A"].push_back({"C",4});

    graph["B"].push_back({"D",2});

    graph["C"].push_back({"G",3});

    graph["D"].push_back({"G",1});

    heuristic["A"] = 6;
    heuristic["B"] = 4;
    heuristic["C"] = 2;
    heuristic["D"] = 1;
    heuristic["G"] = 0;

    astar("A","G");

    return 0;
}


