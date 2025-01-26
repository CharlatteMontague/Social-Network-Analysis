#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Graph{
private:
    string name;
    //vector<string> followers;
    
public:
    vector<string> followers;
    Graph();
    void setName(string userName);
    string getName();
    void addEdge(string userFollower);
    int numFollowers();
    void printGraph();
};

#endif // GRAPH_H
