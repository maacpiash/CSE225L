#ifndef GRAPH_H
#define GRAPH_H

#define INF 999

struct Vertex
{
public:
    int num;
};

class Graph
{
public:
    Graph(int);
    ~Graph();
    bool IsFull();
    bool IsEmpty();
    void MakeEmpty();
    void Initialize();
    void AddVertex(Vertex*);
    int IndexOf(Vertex*);
    void AddEdge(Vertex*, Vertex*, int);
    int WeightIs(Vertex*, Vertex*);
    void PrintGraph();
    int OutDegree(Vertex*);
    int InDegree(Vertex*);
    bool IsEdge(Vertex*, Vertex*);
    void MarkVertex(Vertex*);
    bool IsMarked(Vertex*);
    void BFS(Vertex*);
    bool DFS(Vertex*, Vertex*);
    Vertex** Adjacent(Vertex*);
    bool IsCycle(Vertex*);
private:
    int numVerticies;
    int maxVerticies;
    Vertex* verticies[50];
    int edges[50][50];
    bool marked[50];
};

#endif // GRAPH_H

