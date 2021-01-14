#include <string>
#include "AdjListGraph.h"

int main(void)
{
	AdjListGraph g;

	g.load("graph1.txt");
	g.display();

	return 0;
}
