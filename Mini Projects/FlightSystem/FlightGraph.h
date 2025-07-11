#include <iostream>
#include "RouteList.h"

using namespace std;

class FlightGraph {
    private:
        int numCities;
        RouteList* citiesList;
    public:
        FlightGraph(int cities=5){
            this->numCities = cities;
            this->citiesList = new RouteList[cities];
        }
        void addRoute(int source, int destination, int distance);
        void removeRoute(int source, int destination);
        void addCity();
        void showRoutes();
        void removeCity(int cityID);
        void dijkstra(int source);
};

void FlightGraph::addRoute(int source, int destination, int distance){
    citiesList[source].insert(destination, distance);
}

void FlightGraph::showRoutes(){
    for (int i=0; i<numCities; i++){
        cout<< "City " <<i << ": ";
        citiesList[i].displayVertices();
    }
}

void FlightGraph::addCity(){
    if (numCities >= 20){
        cout<< "Reached maximum number of cities.\n";
        return;
    }
    RouteList* newAdjList = new RouteList[numCities + 1];
    for (int i=0; i<numCities; i++){
        newAdjList[i] = citiesList[i];
    }

    delete[] citiesList;
    citiesList = newAdjList;
    numCities++;
}

void FlightGraph::removeRoute(int source, int destination){
    if (source < 0 || source >= numCities || destination >= numCities){
        cerr<< "Invalid Route.\n";
        return;
    }
    
    Node* temp = citiesList[source].getHead();
    if (temp->getCityID() == destination){
        Node* next = temp->getNext();
        delete temp;
        citiesList[source].setHead(next);
    }

    else {
        while (temp->getNext()->getCityID() != destination){
            temp = temp->getNext();
        }
        Node* newV = temp->getNext();
        temp->setNext(newV->getNext());
        cout<< newV->getCityID() <<endl;
        delete newV;
    }    
}


void FlightGraph::removeCity(int cityID) {
    if (cityID < 0 || cityID >= numCities) {
        cerr << "Invalid city ID.\n";
        return;
    }

    for (int i=0; i<numCities; i++){
        if (i != cityID){
            Node* curr = citiesList[i].getHead();
            Node* prev = 0;

            while (curr != 0){
                if (curr->getCityID() == cityID){
                    Node* toDelete = curr;
                    if (prev == 0){
                        citiesList[i].setHead(curr->getNext());
                        curr = curr->getNext();
                    }
                    else {
                        prev->setNext(curr->getNext());
                        curr = curr->getNext();
                    }
                    delete toDelete;
                }
                else {
                    prev = curr;
                    curr = curr->getNext();
                }
            }
        }

    }
    Node* temp = citiesList[cityID].getHead();
    while (temp)
    {
        Node* toDelete = temp;
        temp = temp->getNext();
        delete toDelete;
    }
    citiesList[cityID].setHead(0);
}

void FlightGraph::dijkstra(int source) {
    const int INF = INT_MAX;
    int distance[numCities], previous[numCities];
    bool visited[numCities] = {false};

    for (int i = 0; i < numCities; i++) {
        distance[i] = INF;
        previous[i] = -1;
    }
    distance[source] = 0;

    for (int count = 0; count < numCities - 1; count++) {
        int u = -1, minDistance = INF;

        for (int i = 0; i < numCities; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                u = i;
            }
        }

        if (u == -1) break; 
        visited[u] = true;

        Node* neighbor = citiesList[u].getHead();
        while (neighbor != nullptr) {
            int v = neighbor->getCityID();
            int weight = neighbor->getDistance();
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
            }
            neighbor = neighbor->getNext();
        }
    }

    for (int i = 0; i < numCities; i++) {
        cout << "City " << source << ": -> ";
        
        int path[100];
        int count = 0, temp = i;
        while (temp != -1) {
            path[count++] = temp;
            temp = previous[temp];
        }

        for (int j = count - 1; j >= 0; j--) {
            cout << path[j];
            if (j > 0) cout << " -> ";
        }

        if (distance[i] == INF)
            cout << " (unreachable)";
        else
            cout << " (" << distance[i] << " km)";
        
        cout << endl;
    }
}


