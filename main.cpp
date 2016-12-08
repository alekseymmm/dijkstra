/*
 * main.cpp
 *
 *  Created on: 17 окт. 2016 г.
 *      Author: alekseym
 */

#include <iostream>
#include "Graph.h"

using namespace std;

int main(){
	Graph G(10);

	vector<Node> V(10);
	Edge e1(V[0], V[1], 20);
	Edge e2(V[1], V[2], 10);

	cout << (e1 < e2) << endl;
	cout << "done" << endl;
	return 0;
}
