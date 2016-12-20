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


//	Graph G_test(4);
//	G_test.V_[0].adjacent_nodes_ = vector<size_t> {1, 2};
//	G_test.V_[0].adjacent_weights_ = vector<uint32_t> {1, 4};
//
//	G_test.V_[1].adjacent_nodes_ = vector<size_t> {2, 3};
//	G_test.V_[1].adjacent_weights_ = vector<uint32_t> {2, 6};
//
//	G_test.V_[2].adjacent_nodes_ = vector<size_t>{3};
//	G_test.V_[2].adjacent_weights_ = vector<uint32_t>{3};
//
//	G_test.V_[3].adjacent_nodes_ = vector<size_t>{};
//	G_test.V_[3].adjacent_weights_ = vector<uint32_t>{};

	Graph G_test(6);
	G_test.V_[0].adjacent_nodes_ = vector<size_t> {1, 2, 5};
	G_test.V_[0].adjacent_weights_ = vector<uint32_t> {7, 9 ,14};

	G_test.V_[1].adjacent_nodes_ = vector<size_t> {0, 2, 3};
	G_test.V_[1].adjacent_weights_ = vector<uint32_t> {7, 10 ,15};

	G_test.V_[2].adjacent_nodes_ = vector<size_t> {0, 1, 3, 5};
	G_test.V_[2].adjacent_weights_ = vector<uint32_t> {9, 10, 11, 2};

	G_test.V_[3].adjacent_nodes_ = vector<size_t> {1, 2, 4};
	G_test.V_[3].adjacent_weights_ = vector<uint32_t> {15, 11, 6};

	G_test.V_[4].adjacent_nodes_ = vector<size_t> {3, 5};
	G_test.V_[4].adjacent_weights_ = vector<uint32_t> {6, 9};

	G_test.V_[5].adjacent_nodes_ = vector<size_t> {0, 2, 4};
	G_test.V_[5].adjacent_weights_ = vector<uint32_t> {14, 2, 9};

	size_t src_node_pos = 0;
	size_t dst_node_pos = 4;
	uint32_t sp = Dijkstra_SP(G_test, src_node_pos, dst_node_pos);
	list<Node> path = Recover_Path(G_test, src_node_pos, dst_node_pos);

	cout << "Shortest path len : " << sp << endl;
	cout << "Shortest path : ";

	for(list<Node>::iterator it = path.begin(); it != path.end(); it++){
		cout << *it;
	}
	cout << endl;
	cout << "done" << endl;
	return 0;
}
