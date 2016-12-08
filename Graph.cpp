/*
 * Graph.cpp
 *
 *  Created on: 17 окт. 2016 г.
 *      Author: alekseym
 */

#include "Graph.h"

Graph::Graph(int num_verticies) {
	num_verticies_ = num_verticies;
	V_ = vector<Node>(num_verticies);
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

bool operator <(const Edge &e1, const Edge &e2){
	return e1.weight_ < e2.weight_;
}

