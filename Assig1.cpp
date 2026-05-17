#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {

        int v;
        vector<int> adj[20];


        public:

        void createGraph() {
            int edges ,u,w;
            cout<<"Enter the number of Vertices "<<endl;
            cin>>v;
            cout<<"Enter the number of Edges"<<endl;
            cin>>edges;

            cout<<"Enter Edges"<<endl;
            for(int i=0;i<edges;i++) {

                cin>>u>>w;
                adj[u].push_back(w);
                adj[w].push_back(u);
            }
        }

        void BFS(int start) {
            bool visited[20] ={false};
            queue<int> q;

            visited[start]=true;
            q.push(start);

            cout<<"BFS Traversal"<<endl;
            while(!q.empty() ) {
                int current =q.front();
                q.pop();

                cout<<current<<" ";

                for(int i=0;i<adj[current].size();i++) {
                    int neighbour = adj[current][i];

                    if(visited[neighbour]==false) {
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            }
        }


        void DFSrecursive(int startnode,bool visited[]) {
            visited[startnode]=true;

            cout<<startnode<<" ";
            for(int i=0;i<adj[startnode].size();i++) {
                int neighbour=adj[startnode][i];
                if(visited[neighbour]==false) {
                    DFSrecursive(neighbour,visited);
                }
            }

        }

        void DFS(int start) {
            bool visited[20]={false};
            cout<<"\n DFS Traversal"<<endl;
            DFSrecursive(start,visited);
        }



};

        int main () {
            Graph g;
            g.createGraph();

            cout<<"Enter the starting Vertex"<<endl;
            int start; cin>>start;

            g.BFS(start);
            g.DFS(start);

            return 0;
        }


