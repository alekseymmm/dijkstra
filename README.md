# dijkstra
C++ implementation of Dijkstra's shortest path algorithm

Running time: O(E log(V))

Implementation doesn't requere adding all nodes to priority queue in the begining of algorithm. So it can be used for really big graphs, and  to find the shortest path from a single source to the closest of a set of target nodes on infinite graphs.

#Build 
To build debug version

$ cd Debug

$ make
 
To build release version

$ cd Release

$ make
