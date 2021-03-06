/*
 * djikstra.h
 *
 *  Created on: 16 дек. 2016 г.
 *      Author: alekseym
 */

#ifndef DIJKSTRA_ALG_H_
#define DIJKSTRA_ALG_H_

#include <tuple>

#include "Graph.h"

std::tuple<uint64_t, bool> Dijkstra_SP(Graph &G, size_t src_node_pos, size_t dst_node_pos);

list<Node> Recover_Path(Graph& G, size_t src_node_pos, size_t dst_node_pos);


#endif /* DIJKSTRA_ALG_H_ */
