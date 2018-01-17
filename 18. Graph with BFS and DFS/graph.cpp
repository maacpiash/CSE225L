#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "D:\CSE225L_Lab18\BFS and DFS\graph.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

Graph::Graph(int max)
{
    numVerticies = 0;
    maxVerticies = max;
    Initialize();
}

Graph::~Graph()
{
    MakeEmpty();
}

bool Graph::IsFull()
{
    return (numVerticies == 0);
}

bool Graph::IsEmpty()
{
    return (numVerticies == maxVerticies);
}

void Graph::MakeEmpty()
{
    numVerticies = 0;
}

int Graph::IndexOf(Vertex* v)
{
    for(int i = 0; i < maxVerticies; i++) {
        if(v->num == verticies[i]->num)
            return i;
    }
    return -1;
}

int Graph::WeightIs(Vertex* v, Vertex* w)
{
    int x = IndexOf(v);
    int y = IndexOf(w);
    return edges[x][y];
}

void Graph::AddEdge(Vertex* v, Vertex* w, int d)
{
    int x = IndexOf(v);
    int y = IndexOf(w);
    edges[x][y] = d;
}

void Graph::PrintGraph()
{
    if(IsEmpty())
        cout << "There is no vertex in the graph" << endl;

    for(int i = 0; i < numVerticies; i++) {
        cout << "\t" << i;
    }
    cout << endl << endl;

    for(int i = 0; i < numVerticies; i++) {
        cout << i;
        for(int j = 0; j < numVerticies; j++) {
            if(WeightIs(verticies[i], verticies[j]) == INF)
                cout << "\t*";
            else
                cout << "\t" << WeightIs(verticies[i], verticies[j]);
        }
        cout << endl << endl;
    }
    cout << endl;
}


void Graph::Initialize()
{
    for(int i = 0; i < maxVerticies; i++)
        for(int j = 0; j < maxVerticies; j++)
            edges[i][j] = INF;
}

void Graph::AddVertex(Vertex* v)
{
    verticies[numVerticies] = v;
    numVerticies++;
}

int Graph::OutDegree(Vertex* v)
{
    int n = IndexOf(v);

    int out = 0;
    for(int i = 0; i < maxVerticies; i++)
        if(edges[n][i] != INF)
            out++;
    return out;
}

int Graph::InDegree(Vertex* v)
{
    int n = IndexOf(v);

    int in = 0;
    for(int i = 0; i < maxVerticies; i++)
        if(edges[i][n] != INF)
            in++;
    return in;
}

bool Graph::IsEdge(Vertex* v, Vertex* w)
{
    int x = IndexOf(v);
    int y = IndexOf(w);
    if(edges[x][y] != INF || edges[y][x] != INF)
        return true;
    else
        return false;
}

void Graph::MarkVertex(Vertex* v)
{
    marked[v->num] = true;
}

bool Graph::IsMarked(Vertex* v)
{
    return marked[v->num];
}

void Graph::BFS(Vertex* w)
{
    for(int i = 0; i < numVerticies; i++)
        marked[verticies[i]->num] = false;
    marked[w->num] = true;
    queue<int> q;
    q.push(w->num);
    cout << "Breadth First Search starting from vertex " << w->num << " : " << endl;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int i = 0; i < numVerticies; i++) {
            if(IsEdge(verticies[v], verticies[i]) && !IsMarked(verticies[i])) {
                q.push(verticies[i]->num);
                marked[verticies[i]->num] = true;
            }
        }
        cout << " ";
    }
    cout << endl;
}

bool Graph::DFS(Vertex* v, Vertex* w)
{
    stack<int> s;
    for(int i = 0; i < numVerticies; i++)
        marked[verticies[i]->num] = false;

    s.push(v->num);
    marked[v->num] = true;
    bool found = false;
    if(v->num == w->num) {
        cout << "Same starting and ending vertex" << endl;
        cout << w->num << endl;
    }
    cout << "Depth First Search starting from vertex " << v->num << " : " << endl;
    while(!s.empty()) {
        int k = s.top();
        s.pop();
        if(k == w->num) {
            found = true;
            cout << k;
            break;
        }
        cout << k << " ";
        for(int i = numVerticies - 1; i>= 0; i--) {
            if(IsEdge(verticies[k], verticies[i]) && !IsMarked(verticies[i])) {
                s.push(verticies[i]->num);
                marked[verticies[i]->num] = true;
            }
        }
    }
    cout << endl;
    return found;
}

Vertex** Graph::Adjacent(Vertex* v)
{
    Vertex** neighbours = new Vertex*[5];
    int n = IndexOf(v);
    int j = 0;
    for(int i = 0; i < numVerticies; i++)
        if(IsEdge(verticies[i], verticies[n]) || IsEdge(verticies[n], verticies[i]))
            neighbours[j++] = verticies[i];
    return neighbours;
}

bool Graph::IsCycle(Vertex* v)
{
    bool cycle = false;
    Vertex** adj = Adjacent(v);
    for(int i = 0; i < OutDegree(v); i++)
        if(DFS(v, adj[i])) {
            cycle = true;
            break;
        }

    return cycle;
}

#endif // GRAPH_CPP

