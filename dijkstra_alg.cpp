/*
 * djikstra_alg.cpp
 *
 *  Created on: 15 дек. 2016 г.
 *      Author: alekseym
 */
#include <set>
#include <limits>

#include "Graph.h"

uint32_t Dijkstra_SP(Graph &G, uint32_t src_node_pos, uint32_t dst_node_pos){
	for (vector<Node>::iterator it = G.V_.begin(); it != G.V_.end(); ++it) {
		it->shortest_path_ = numeric_limits<uint32_t>::max();
		it->visited   = false;;
	}

	Node &start_node = G.get_node(src_node_pos);
	start_node.shortest_path_ = 0;
	start_node.visited = true;

	std::set<Node> frontier;
	frontier.insert(start_node);

	while (1) {
		if (frontier.empty()) {
			//there is no path
			return -1;
		}
		set<Node>::iterator nearest_node_it = frontier.begin();
		Node &nearest_node = G.get_node(nearest_node_it->node_pos_);
		frontier.erase(nearest_node_it);

		if (nearest_node.get_pos() == dst_node_pos) {
			return nearest_node.shortest_path_;
		}
		nearest_node.visited = true;

		for (size_t i = 0; i < nearest_node.adjacent_nodes_.size(); i++) {
			Node &node = G.get_node(nearest_node.adjacent_nodes_[i]);
			if (node.visited == false) {
				set<Node>::iterator ret = frontier.find(node);

				//if this adjacent node is not in frontier 
				if (ret == frontier.end()) {
					size_t node_pos = node.get_pos();

					//Dijkstra criteria
					node.shortest_path_ = nearest_node.shortest_path_ + nearest_node.adjacent_weights_[i];
					frontier.insert(node);
				}
				else {
					uint32_t current_sp = nearest_node.shortest_path_ + nearest_node.adjacent_weights_[i];

					if(current_sp < node.shortest_path_){
						frontier.erase(ret);
						node.shortest_path_ = current_sp;
						frontier.insert(node);
					}
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


