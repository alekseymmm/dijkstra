/*
 * main.cpp
 *
 *  Created on: 17 окт. 2016 г.
 *      Author: alekseym
 */

#include <iostream>

#include "dijkstra_alg.h"
#include "Graph.h"

using namespace std;


int main(void){

	//Graph G(10, 0.3);
	//Djikstra_SP(G, 0, 5);

	Graph G_test(4);
	G_test.V_[0].adjacent_nodes_ = vector<size_t> {1, 2};
	G_test.V_[0].adjacent_weights_ = vector<uint32_t> {1, 4};

	G_test.V_[1].adjacent_nodes_ = vector<size_t> {2, 3};
	G_test.V_[1].adjacent_weights_ = vector<uint32_t> {2, 6};

	G_test.V_[2].adjacent_nodes_ = vector<size_t>{3};
	G_test.V_[2].adjacent_weights_ = vector<uint32_t>{3};

	G_test.V_[3].adjacent_nodes_ = vector<size_t>{};
	G_test.V_[3].adjacent_weights_ = vector<uint32_t>{};

	uint32_t sp = Dijkstra_SP(G_test,0, 3);
	cout << "Shortest path = " << sp << endl;
	cout << "done" << endl;
	return 0;
}
