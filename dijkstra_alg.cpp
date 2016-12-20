/*
 * djikstra_alg.cpp
 *
 *  Created on: 15 дек. 2016 г.
 *      Author: alekseym
 */
#include <set>
#include <limits>
#include <list>

#include "Graph.h"

uint32_t Dijkstra_SP(Graph &G, size_t src_node_pos, size_t dst_node_pos){
	for (vector<Node>::iterator it = G.V_.begin(); it != G.V_.end(); ++it) {
		it->shortest_path_ = numeric_limits<uint32_t>::max();
		it->visited   = false;
	}

	Node &start_node = G.get_node(src_node_pos);
	start_node.shortest_path_ = 0;
	start_node.visited = true;

	std::multiset<Node> frontier;
	frontier.insert(start_node);

	//while we didn't find out destination node
	while (!G.get_node(dst_node_pos).visited) {
		if (frontier.empty()) {
			//there is no path
			return -1;
		}

		//get the nearest node in frontier
		multiset<Node>::iterator nearest_node_it = frontier.begin();
		Node &nearest_node = G.get_node(nearest_node_it->node_pos_);
		frontier.erase(nearest_node_it);

		nearest_node.visited = true;

		//if we find the path it is the shortest path
		if (nearest_node.get_pos() == dst_node_pos) {
			return nearest_node.shortest_path_;
		}

		//proceed all adjacent nodes
		for (size_t i = 0; i < nearest_node.adjacent_nodes_.size(); i++) {
			Node &node = G.get_node(nearest_node.adjacent_nodes_[i]);

			//if node has already been visited then just skip it
			if (node.visited == false) {

				//calculate new possible shortest distance to node
				uint32_t current_sp = nearest_node.shortest_path_ + nearest_node.adjacent_weights_[i];

				//if new calculated path is shorter then path calculated before
				if(current_sp < node.shortest_path_){
					//find if this node in frontier
					multiset<Node>::iterator ret = frontier.find(node);

					//if it is and we find shorter path then update path and
					//position of this node in multiset
					if (ret != frontier.end()){
						frontier.erase(ret);
					}

					//we have found shorter path to this node
					node.shortest_path_ = current_sp;
					node.parent_node = &nearest_node;
					//update node in multiset
					frontier.insert(node);
				}

			}
		}
	}

	return 0;
}

list<Node> Recover_Path(Graph& G, size_t src_node_pos, size_t dst_node_pos){
	list<Node> path;

	Node& src_node = G.get_node(src_node_pos);
	Node& cur_node = G.get_node(dst_node_pos);

	//recover path starting from destination node
	while(cur_node.get_pos() != src_node.get_pos()){
		path.push_front(cur_node);
		//get node from witch we have came to this one
		cur_node = *cur_node.parent_node;
	}

	path.push_front(src_node);
	return path;
}

