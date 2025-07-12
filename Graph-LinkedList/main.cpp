#include <iostream>
#include "Graph.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Graph g1(5);
	
//	g1.addEdge(5, 6);
	
	
	g1.addEdge(0, 1);
	g1.addEdge(0, 4);
	g1.addEdge(1, 2);
	g1.addEdge(1, 3);
	g1.addEdge(1, 4);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	g1.BFS(2);
//	g1.printGraph();
	return 0;
}
