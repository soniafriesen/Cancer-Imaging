/*
Project: Project 2: tree class
Purpose: To create a tree for decisions
Coder: Sonia Friesen 0813682
Date: Due Dec.8th 2019
*/
#pragma once
#include "Node.hpp"
#include"Patient.hpp"
#include <vector>
class DecisionTree {
private:
	Node* root;
	void insert(int val, Node*& leaf); //this is the recurssive function
	void preorder(Node* root);
	void results(Node* root,Patient& p); // recurssive function using preorder as example
public:
	DecisionTree() : root(nullptr) {}
	~DecisionTree() { delete root; }
	//insert
	void insert(int val);
	//create tree
	void createTree();
	//test creation by printing
	void print();
	//pass in a patient object to test through
	void results(Patient& p);

};
