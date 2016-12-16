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

	vector<size_t> adjacent_nodes_;
	vector<uint32_t> adjacent_weights_;
	uint32_t shortest_path_ = std::numeric_limits<uint32_t>::max();
	bool visited = false;
};

class Edge {
public:
	Edge(const Node &v1, const Node &v2, int weight = 1){
		e_ = pair<Node, Node>(v1, v2);
		weight_ = weight;
	}

	bool is_visited();

	pair<Node, Node> e_;
	uint32_t weight_;
};

bool operator <(const Edge &e1, const Edge &e2);

class Graph {
public:
	Graph(size_t num_verticies);
	Graph(size_t num_verticies, double density, uint32_t seed = 0);
	Node &get_node(size_t node_pos);
	~Graph();

	size_t num_verticies_;
	vector<Node> V_;
	vector<uint32_t> shortest_path_;

};

#endif /* GRAPH_H_ */
