#include <iostream>
#include "HeaderLL.h"
#include "F:\Programming\C++\DSA-in-University\QueueArray\QueueArray.h"
#include "F:\Programming\C++\DSA-in-University\Stack\StackArray.exe"
using namespace std;

class Graph {
	private:
		int vertices;	//numberOfVertics
		HeaderLL* adjList;
	public:
		Graph(int vertices=5){
			this->vertices = vertices;
			adjList = new HeaderLL[vertices];			
		}
		void addEdge(int srcVertex, int destVetrex);
		void printGraph();
		void BFS(int startV);	
		void DFS(int startV);			
};

void Graph::addEdge(int srcVertex, int dstVertex){
	adjList[srcVertex].insert(dstVertex); // for source slot
	adjList[dstVertex].insert(srcVertex); // for destination slot

}

void Graph::printGraph(){
	for (int i=0; i<this->vertices; i++){
		cout<< "Vertex " <<i << ": ";
		adjList[i].print();
		cout<< endl;
	}
}

void Graph::BFS(int startV){
	bool visited[this->vertices] = {false};
	QueueArray<int> q(this->vertices);
	
	visited[startV] = true;
	q.Enqueue(startV);
	
	while (!q.isEmpty()){
		int v = q.Dequeue();
		cout<< v << "\t";
		
		Node* temp = adjList[v].getHead();
		
		while (temp != 0){
			if (visited[temp->getInfo()] != true){
				q.Enqueue(temp->getInfo());
				visited[temp->getInfo()] = true;
			}
			temp = temp->getNext();
		}
	}
}

//void Graph::DFS(int startV){
////	bool visited[this->vertices] = {false};
//	StackArray<int> s(this->vertices);
//	
////	visited[startV] = true;
//	s.push(startV);
//	
//	while (!s.isEmpty()){
//		int v = s.pop();
//		cout<< v << "\t";
//		
//		Node* temp = adjList[v].getHead();
//		
//		while (temp != 0){
//			if (!visited[temp->getInfo()]){
//				s.push(temp->getInfo());
////				visited[temp->getInfo()] = true;
//			}
//			temp = temp->getNext();
//		}
//	}
//}
