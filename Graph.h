/*
 * Graph.h
 *
 *  Created on: 17 окт. 2016 г.
 *      Author: alekseym
 */
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

#ifndef GRAPH_H_
#define GRAPH_H_

class Node {
public:
	Node(){
	}
private:
	list<Node> adjacent_nodes_;
};

class Edge : pair<Node, Node> {
public:
	Edge(const Node &v1, const Node &v2, int weight = 1){
		e_ = pair<Node, Node>(v1, v2);
		weight_ = weight;
	}

private:
	pair<Node, Node> e_;
	int weight_;
};


class Graph {
public:
	Graph(int num_verticies);
	~Graph();

	void AddEdge(const Edge &e);

private:
	int num_verticies_;
	vector<Node> V_;

};

#endif /* GRAPH_H_ */
