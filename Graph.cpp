/*
Project: Project 2: Graph class
Purpose: To create a tree for decisions
Coder: Sonia Friesen 0813682
Date: Due Dec.11th 2019
*/
#include "Graph.hpp"
#include<iostream>
#include <fstream>
#include <string>

Graph::Graph(int size) : numVerticies_(size)
{
	adjacencyList = new AdjList[size];
	//initalize the adjList
	for (size_t i = 0; i < size; i++)
	{
		adjacencyList[i].head_ = nullptr;
	}
}

Graph::~Graph()
{
	for (size_t i = 0; i < numVerticies_; i++)
	{
		delete adjacencyList[i].head_;
	}
	delete adjacencyList;
}

void Graph::addEdge(int src, int dest, int weight)
{
	//The node is added to the beginning of each list of src
	Node* newNode = new Node(dest, weight);
	newNode->next_ = adjacencyList[src].head_;
	adjacencyList[src].head_ = newNode;

	//because it is undirected, we need to add the Node to dest
	/*Node* newNode1 = new Node(src, weight);
	newNode1->next_ = adjacencyList[dest].head_;
	adjacencyList[dest].head_ = newNode;*/
}

void Graph::printGraph()
{
	for (size_t i = 0; i < numVerticies_; i++)
	{
		Node* ptr = adjacencyList[i].head_;
		std::cout << "[" << i << "]";
		while (ptr != nullptr)
		{
			std::cout << " -> " << ptr->weight << "(" << ptr->data << ")";
			ptr = ptr->next_;
		}
		std::cout << std::endl;
	}
}

void Graph::createCSV(std::string name)
{
	ofstream graph;
	graph.open(name);
	for (size_t i = 0; i < numVerticies_; i++)
	{
		Node* ptr = adjacencyList[i].head_;		
		while (ptr != nullptr)
		{
			graph<< ptr->weight << ", ";
			ptr = ptr->next_;
		}		
		graph << "\n";
	}
	graph.close();
}
