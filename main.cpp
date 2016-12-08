/*
 * main.cpp
 *
 *  Created on: 17 окт. 2016 г.
 *      Author: alekseym
 */

#include <iostream>
#include <set>

#include "Graph.h"

using namespace std;

int main(){

	Graph G(10);
	vector<Node> V(10);

	Edge e1(V[0], V[1], 20);
	Edge e2(V[1], V[2], 10);
	Edge e3(V[2], V[5], 15);
	Edge e4(V[3], V[0], 2);
	Edge e5(V[5], V[1], 10);
//
//	multiset<Edge> ms_edges;
//	ms_edges.insert(e1);
//	ms_edges.insert(e2);
//	ms_edges.insert(e3);
//	ms_edges.insert(e4);
//	ms_edges.insert(e5);
//
//	for(multiset<Edge>::iterator it = ms_edges.begin(); it != ms_edges.end(); ++it){
//		cout << "weight = " << it->weight_ << endl;
//	}
//	cout << (e1 < e2) << endl;
	cout << "done" << endl;
	return 0;
}
