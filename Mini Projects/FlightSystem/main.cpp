#include <iostream>
#include "FlightGraph.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	FlightGraph* rg = new FlightGraph(4);

	rg->addRoute(0, 2, 20);
	rg->addRoute(2, 3, 18);
	rg->addRoute(3, 1, 30);
	// rg->addRoute(1, 0, 8);
	rg->addRoute(1, 2, 25);
	rg->addRoute(0, 3, 15);
	rg->addRoute(0, 1, 9);

	// rg->addCity();
	// rg->addCity();
	// rg->addCity();

	rg->showRoutes();
	// rg->removeRoute(0, 3);
	// rg->removeCity(0);

	cout<< endl;
	// rg->showRoutes();

	// rg->showRoutes();
	rg->dijkstra(0);
	return 0;
}
