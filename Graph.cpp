/*
 * Graph.cpp
 *
 *  Created on: 17 окт. 2016 г.
 *      Author: alekseym
 */

#include <random>
#include <limits>

#include "Graph.h"

Graph::Graph(size_t num_verticies) {
	num_verticies_ = num_verticies;
	V_ = vector<Node>(num_verticies);
	shortest_path_ = vector<int>(num_verticies, std::numeric_limits<int>::max());
}

Graph::Graph(size_t num_verticies, double density) : Graph(num_verticies){

    default_random_engine generator(0);
    uniform_int_distribution<size_t> nodes_distribution(0, 100);
    uniform_int_distribution<int> weights_distribution(1, num_verticies_);

    size_t num_adjacent = static_cast<int>(density * static_cast<double>(num_verticies_));

    for(vector<Node>::iterator it = V_.begin(); it != V_.end(); ++it){
        it->adjacent_nodes_ = vector<Node>(num_adjacent, Node());
        it->adjacent_weights_ = vector<int>(num_adjacent);

        for(size_t i = 0; i < num_adjacent; i++){
        	it->adjacent_nodes_[i] = V_[nodes_distribution(generator)];
        	it->adjacent_weights_[i] = weights_distribution(generator);
        }
    }
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

bool operator <(const Edge &e1, const Edge &e2){
	return e1.weight_ < e2.weight_;
}

