#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

class Car{
public:
    string id;
    int x,y;
    Car(string id,int x,int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist() const{
        return x*x+y*y;
    }
};

class CarCompare{
public:
    bool operator()(const Car A,const Car B){
        return A.dist() < B.dist(); // it will create a max heap.
    }
};

bool distCompare(Car A,Car B){
        return A.dist() < B.dist();
    }

void printNearestCars(vector<Car> cars,int k){

    // create a maxheap of k cars.
    priority_queue<Car,vector<Car>,CarCompare > max_heap(cars.begin(),cars.begin()+k); 

    // check for remaining N-K cars.
    for(int i=k;i<cars.size();i++){
        if(cars[i].dist() < max_heap.top().dist()){
            max_heap.pop();
            max_heap.push(cars[i]);
        }
    }
    // print all the cars inside the heap they will be smallest.
    vector<Car> output;

    while(!max_heap.empty()){
        // cout<<max_heap.top().id<<endl;
        output.push_back(max_heap.top());
        max_heap.pop();
    }
    sort(output.begin(),output.end(),distCompare);
    for(int i=0;i<output.size();i++){
        cout<<output[i].id<<endl;
    }
    return;

}

int main(){
    int N,K;cin>>N>>K;
    string id;
    int x,y;

    vector<Car> cars;

    for(int i=0;i<N;i++){
        cin>>id>>x>>y;
        Car Car(id,x,y);
        cars.push_back(Car);
    }
    printNearestCars(cars,K);

    return 0;
}
