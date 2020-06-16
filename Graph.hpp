#pragma once
/*
Project: Project 2: Graph class
Purpose: To create a tree for decisions
Coder: Sonia Friesen 0813682
Date: Due Dec.11th 2019
*/
#include "AdjList.hpp"
#include <string>
using namespace std;

class Graph {	
public:
	int numVerticies_;
	AdjList* adjacencyList;

	Graph(int size);
	~Graph();
	void addEdge(int, int, int);
	void printGraph();
	void createCSV(string name);
};