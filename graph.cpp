#include "graph.h"
using namespace std;


graph::graph(int n)
{
  vector<edge> edges =
  //(vert->destination,weight).
  {{0,1,4},{1,2,3},{2,0,7},{2,1,3},{3,2,8},{4,5,2},{5,4,4},{6,1,10}};

  //resize edge list to user input.
  adjList.resize(n);

  //add edges to directed graph.
  for(auto &edge: edges)
  {
    int vert = edge.vert;
    int destination = edge.destination;
    int weight = edge.weight;

    //insert at the end (Use second line below for an undirected graph).
    adjList[vert].push_back(make_pair(destination,weight));
    //adjList[vert].push_back(make_pair(vert,weight));
  }
}

graph::~graph()
{
  //deinit
}

void graph::graphPrint(graph const &graph, int n)
{
  for(int i = 0; i < n; i++)
  {
    //print all edges of vert[i]
    for(Pair v: graph.adjList[i])
    {
      cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
    }
    cout << endl;
  }
}
