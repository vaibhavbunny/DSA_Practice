#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<cstring>
using namespace std;

class Graph{
    int V;
    list<pair<int,int> > *l;
public:
    Graph(int v){
        V = v;
    }
    void addEdge(int i,int j,int wt,bool undir = true){
        l[i].push_back({wt,j});
        if(undir){
            l[j].push_back({wt,i});
        }
    }
    int dijk(int src,int dest){

        // data structure.
        vector<int> dist(V,INT16_MAX);// this well tell both whether a node is visited or not and shortest distance.
        set<pair<int,int> > s;
        dist[src] = 0;
        s.insert({0,src});

        while(!s.empty()){

            auto it = s.begin();
            int node = it->second;
            int DistTillNow = it->first;
            s.erase(it);// pop

            for(auto nbrpair : l[node]){

                int nbr = nbrpair.second;
                int currentEdge = nbrpair.first;

                if(DistTillNow + currentEdge < dist[nbr]){
                    // if the pair is already there we need to update it by removing.
                    auto f = s.find({dist[nbr],nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    // insert the updated one.

                    dist[nbr] = DistTillNow + currentEdge;
                    s.insert({dist[nbr],nbr});
                }
            }
        }
        // single set shortest distance to all nodes.
        for(int i;i<V;i++){
            cout<<"Node i"<<i<<"Dist"<<dist[i]<<endl;
        }
        return dist[dest];
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);
    
    cout<<g.dijk(0,4)<<endl;

    return 0;
}