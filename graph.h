#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

struct edge
{
  int vert;
  int destination;
  int weight;
};

typedef std::pair<int,int> Pair;

class graph
{
  public:
    graph(int n);
    ~graph();
    void graphPrint(graph const &graph, int n);
    int dijkstraMinDistance(int dist[], bool shortestPath[]);
    void dijkstra();
    void bfs(graph const &graph, int source);
  private:
    // vector of Pairs to make edge list of every vert.
    std::vector<std::vector<Pair>> adjList;
  protected:

};

#endif //GRAPH_H
