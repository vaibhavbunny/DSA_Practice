#include<iostream>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;

class Node{
public:
    string name;
    list<string> nbrs;
    Node(string name){
        this->name = name;
    }

};

class Graph{
    unordered_map<string,Node*> m;
public:
    Graph(vector<string> cities){
        for(auto city: cities){
            m[city] = new Node(city);
        }
    }

    void addedge(string x,string y,bool undir = true){
        m[x]->nbrs.push_back(y);
        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }
    void printAdjlist(){
        for(auto cityPair: m){
            auto city = cityPair.first;
            Node *Node = cityPair.second;
            cout<<city<<"->";

            for(auto nbrs: Node->nbrs){
                cout<<nbrs<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    vector<string> cities = {"Delhi","London","Paris","NewYork"};
    Graph g(cities);
    g.addedge("Delhi","London");
    g.addedge("NewYork","London");
    g.addedge("Delhi","Paris");
    g.addedge("Paris","NewYork");
    g.printAdjlist();
    return 0;
}