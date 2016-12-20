/*
 * Graph.h
 *
 *  Created on: 17 окт. 2016 г.
 *      Author: alekseym
 */
#include <vector>
#include <list>
#include <limits>
#include <unordered_set>

using namespace std;

#ifndef GRAPH_H_
#define GRAPH_H_

class Node {
public:
	Node(){
	}
	
	size_t get_pos() const;

	size_t node_pos_ = 0;
	vector<size_t> adjacent_nodes_;
	vector<uint32_t> adjacent_weights_;
	uint32_t shortest_path_ = std::numeric_limits<uint32_t>::max();
	bool visited = false;
	Node *parent_node = nullptr;
};

bool operator <(const Node &n1, const Node &n2);
ostream& operator<<(ostream& os, const Node& n);

class Graph {
public:
	Graph(size_t num_verticies);
	Graph(size_t num_verticies, double density, uint32_t seed = 0);
	Node &get_node(size_t node_pos);
	~Graph();

	size_t num_verticies_;
	vector<Node> V_;
};

#endif /* GRAPH_H_ */
