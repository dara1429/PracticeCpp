#include "graph.h"
#include <limits.h>
#include <list>
using namespace std;


graph::graph(int n)
{
  vector<edge> edges =
  //(vert->destination,weight).
  {{0,1,4},{0,7,8},
  {1,0,4},{1,2,8},{1,7,11},
  {2,8,2},{2,3,7},{2,1,8},{2,5,4},
  {3,5,14},{3,4,9},{3,2,7},
  {4,3,9},{4,5,10},
  {7,1,11},{7,8,7},{7,6,1},{7,0,8},
  {6,8,6},{6,5,2},{6,7,1},
  {5,4,10},{5,3,14},{5,2,4},{5,6,2},
  {8,2,2},{8,6,6},{8,7,7}};

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

int graph::dijkstraMinDistance(int dist[], bool shortestPath[])
{
  //initialize minimum value
  int minimum = INT_MAX;
  int minimum_index;

  for(int i = 0; i < 9; i++)
  {
    if(shortestPath[i] == false && dist[i] <= minimum)
    {
      minimum = dist[i];
      minimum_index = i;
    }
  }
  return minimum_index;
}

void graph::dijkstra()
{
  //example graph
  int dGraph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
  					{4, 0, 8, 0, 0, 0, 0, 11, 0},
  					{0, 8, 0, 7, 0, 4, 0, 0, 2},
  					{0, 0, 7, 0, 9, 14, 0, 0, 0},
  					{0, 0, 0, 9, 0, 10, 0, 0, 0},
  					{0, 0, 4, 14, 10, 0, 2, 0, 0},
  					{0, 0, 0, 0, 0, 2, 0, 1, 6},
  					{8, 11, 0, 0, 0, 0, 1, 0, 7},
  					{0, 0, 2, 0, 0, 0, 6, 7, 0}
  					};
  int sourceVertex = 0;
  ////////////////////////////////////////////////////////////////////////////
  //output of dijkstra. dist[i] = shortest distance from 0 -> i.
  int dist[9];
  //checks if current vertex is in the shortest path or if shortest distance is finalized.
  bool shortestPath[9];

  //initialize all distances to verticies as INT_MAX and bools to false.
  for(int i = 0; i < 9; i++)
  {
    dist[i] = INT_MAX;
    shortestPath[i] = false;
  }

  dist[sourceVertex] = 0;

  //find shortest path for each vertex.
  for(int i = 0; i < 9-1; i++)
  {
    int currentV = dijkstraMinDistance(dist,shortestPath);
    shortestPath[currentV] = true;

    for(int j = 0; j < 9; j++)
    {
      if(!shortestPath[j] && dGraph[currentV][j] && dist[currentV] != INT_MAX && dist[currentV]+dGraph[currentV][j] < dist[j])
      {
        dist[j] = dist[currentV] + dGraph[currentV][j];
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
  //print solution
  cout << "Dijkstra, shortest distance from source -> destination : " << endl;
  for(int i = 0; i < 9; i++)
  {
    cout << i << " -> " << dist[i] << endl;
  }
  return;
}

void graph::bfs(graph const &graph, int source)
{
  int numVerticies = 9;
  bool *visited = new bool[numVerticies];

  for(int i = 0; i < numVerticies; i++)
  {
		visited[i] = false;
  }

  list<int> queue;

  //set current node as visited and put in queue
  visited[source] = true;
  //queue.push_back(adjList[source][0]);
  //cout << graph.adjList[source] << endl;

  while(!queue.empty())
  {
    //pop queue and print
    source = queue.front();
    cout << source << " ";
    queue.pop_front();

    //see if current vert has adj verts and queue them
    for(int i = 0; i < adjList.size() ;i++)
    {
      if(visited[i] == false)
      {
        visited[i] = true;
        queue.push_back(i);
      }
    }
  }
}
