/*
 * djikstra_alg.cpp
 *
 *  Created on: 15 дек. 2016 г.
 *      Author: alekseym
 */
#include <queue>
#include <unordered_map>

#include "Graph.h"

uint32_t Djikstra_SP(Graph &G, uint32_t src_node_pos, uint32_t dst_node_pos){

	Node cur_node = G.V_[src_node_pos];
	cur_node.shortest_path_ = 0;
	cur_node.visited = true;

	priority_queue<Edge> E;

	while(1){

		for(size_t i = 0; i < cur_node.adjacent_nodes_.size(); i++){
			Node &adjacent_node = G.get_node(cur_node.adjacent_nodes_[i]);
			uint32_t weight = cur_node.adjacent_weights_[i];

			uint32_t djikstra_weight = weight + cur_node.shortest_path_;

			Edge e = Edge(cur_node, adjacent_node, djikstra_weight);

			E.push(e);
		}

		if(E.empty()){
			//all possible nodes proceeded
		}
		else{
			Edge smallest_edge = E.top();
			while (smallest_edge.e_.second.visited == true && !E.empty()){
				smallest_edge = E.top();
				E.pop();
			}
			E.pop();
			cur_node = smallest_edge.e_.second;
			if(smallest_edge.weight_ < cur_node.shortest_path_){
				cur_node.shortest_path_ = smallest_edge.weight_;
				cur_node.visited = true;
			}
		}

	}
	return 0;
}


