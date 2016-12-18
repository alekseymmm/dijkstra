/*
 * djikstra_alg.cpp
 *
 *  Created on: 15 дек. 2016 г.
 *      Author: alekseym
 */
#include <set>

#include "Graph.h"

uint32_t Djikstra_SP(Graph &G, uint32_t src_node_pos, uint32_t dst_node_pos){
	for (vector<Node>::iterator it = G.V_.begin(); it != G.V_.end(); ++it) {
		it->shortest_path_ = std::numeric_limits<uint32_t>::max();
		it->visited = false;
	}

	Node cur_node = G.V_[src_node_pos];
	cur_node.shortest_path_ = 0;
	cur_node.visited = true;

	multiset<Node> frontier;
	frontier.insert(cur_node);

	while (1) {
		if (frontier.empty()) {
			//there is no path
			return -1;
		}
		multiset<Node>::iterator nearest_node_it = frontier.begin();
		Node nearest_node = *nearest_node_it;
		frontier.erase(nearest_node_it);

		if (nearest_node.get_pos() == dst_node_pos) {
			//we find it!
		}
		nearest_node.visited = true;

		for (size_t i = 0; i < nearest_node.adjacent_nodes_.size(); i++) {
			Node node = G.get_node(nearest_node.adjacent_nodes_[i]);
			if (node.visited == false) {
				multiset<Node>::iterator ret = frontier.find(node);
				//if this adjacent node is not in frontier 
				if (ret == frontier.end()) {
					//add it
				}
				else {

				}
			}
		}
	}
	/*
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
			while (smallest_edge.is_visited()){
				E.pop();
				if(E.empty()){
					//handle this return graph is not connected
				}
				smallest_edge = E.top();
			}

			cur_node = smallest_edge.e_.second;
			//if we cfound shorter past then before the nsave it
			if(smallest_edge.weight_ < cur_node.shortest_path_){
				cur_node.shortest_path_ = smallest_edge.weight_;
				cur_node.visited = true;
			}
		}

	}
	*/
	return 0;
}


