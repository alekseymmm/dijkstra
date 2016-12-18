/*
 * Graph.cpp
 *
 *  Created on: 17 окт. 2016 г.
 *      Author: alekseym
 */

#include <random>
#include <limits>

#include "Graph.h"
#include <queue>

Graph::Graph(size_t num_verticies) {
	num_verticies_ = num_verticies;
	V_ = vector<Node>(num_verticies);
	for (size_t i; i < num_verticies; i++) {
		V_[i].node_pos_ = i;
	}
}

Graph::Graph(size_t num_verticies, double density, uint32_t seed) : Graph(num_verticies){
    default_random_engine generator(seed);
    uniform_int_distribution<size_t> nodes_distribution(0, num_verticies_);
    uniform_int_distribution<uint32_t> weights_distribution(1, num_verticies_);

    size_t num_adjacent = static_cast<size_t>(density * static_cast<double>(num_verticies_));

    for(vector<Node>::iterator it = V_.begin(); it != V_.end(); ++it){
        it->adjacent_nodes_ = vector<size_t>(num_adjacent);
        it->adjacent_weights_ = vector<uint32_t>(num_adjacent);

        for(size_t i = 0; i < num_adjacent; i++){
        	it->adjacent_nodes_[i] = nodes_distribution(generator);
        	it->adjacent_weights_[i] = weights_distribution(generator);
        }
    }
}

Node& Graph::get_node(size_t node_pos){
	return V_[node_pos];
}
size_t Node::get_pos() {
	return node_pos_;
}

bool operator <(const Node &n1, const Node &n2) {
	return n1.shortest_path_ < n2.shortest_path_;
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}



