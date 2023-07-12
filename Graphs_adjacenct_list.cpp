#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *l; // pointer is used as we have to allocate memory dynamically.
                 // each position of an array is a linked list now.
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i,int j,bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjlist(){
        // ietrate over the list.
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            for(auto node: l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
    void BFS(int src){ // level order traversal from the given node.
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(src); 
        visited[src] = true;

        while(!q.empty()){
            int f = q.front();
            cout<<f<<endl;
            q.pop();

            for(auto nbr : l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void dfsHelper(int Node,bool *visited){
        visited[Node] = true;
        cout<<Node<<",";
        // make a recursive call on all its unvisited nbrs.
        for(auto nbr: l[Node]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
        return;
    }
    void DFS(int src){
        bool *visited = new bool[V]{0};
        dfsHelper(src,visited);
    }
    void topological_sort(){
        vector<int> indegree(V,0);
        // Iterate over all the edges to find out right indegree.
        for(int i=0;i<V;i++){
            for(auto nbr : l[i]){
                indegree[nbr]++;
            }
        }
        //initialize the queue with nodes having 0 indegree.
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // start popping.
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            // iterate over nbrs of this node and reduce the indegree.
            for(auto nbr: l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
};

int main(){

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.DFS(2);

    return 0;
}