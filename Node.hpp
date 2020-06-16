/*
Project: Project 2: node class
Purpose: To create a tree for decisions
Coder: Sonia Friesen 0813682
Date: Due Dec.8th 2019
*/
#pragma once
class Node {
public:
	int data;
	Node* left;
	Node* right;


	//constructor
	Node(int val) : data(val), left(nullptr), right(nullptr) {};

	//deconstructor
	~Node()
	{
		if (left != nullptr) delete left;
		if (right != nullptr) delete right;
	}

};

