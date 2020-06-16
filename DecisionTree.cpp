/*
Project: Project 2: tree class
Purpose: To create a tree for decisions
Coder: Sonia Friesen 0813682
Date: Due Dec.8th 2019
*/
#include "DecisionTree.hpp"
#include <iostream>
using namespace std;
/*
Desc: Inserts a number into the tree, recurssive function
Parm: Int, and node pointer
Returns: N/A
*/
void DecisionTree::insert(int val, Node*& leaf)
{
	if (leaf == nullptr)
	{
		leaf = new Node(val);
		return;
	}		
	//by using the opposite meaning in from the Pruned Tree, we can create a tree similar to the data.
	if (val > root->data || val > leaf->data)
  //go left which represents the <=
		insert(val, leaf->left);	
	if (val <= root->data || val <= leaf->data) //go right presenting the < 
		insert(val, leaf->right);	
}
/*
Desc: Calls the recurssive function
Parm: int 
Returns: N/A
*/
void DecisionTree::insert(int val)
{
	//resursion
	insert(val, root);
}

/*
Desc: Creates a binary tree, not in order. Actually  preorder technique used here
Parm: N/A
Returns: N/A
*/
void DecisionTree::createTree()
{
	insert(2); //cell size
	//<= 2 cell size
	insert(3); //bare N  --left side	
	//if the bare Nuceli <=3 benign results	
	//Bare nucli more than 3
	insert(3); //clumpThick -- right side	of left	
	insert(2);//blan chr--left side		
	//bland chormatin <= 2
	insert(3); //marginal adhesion--left side	
		
	//cell Size > 2
	insert(2);//cell shape --right side
	//cell shape <= 2
	insert(5);//clump thickness --right side	
	//cell shape > 2
	insert(4);//cell size--right side 
	//cell size <= 4
	insert(2);//bare nucli --right side 
	//bare nucli<=2 check marginal 
	insert(3);//marginal adhesion --right side	
	//bare nucli> 2 check clump thickness --right side
	insert(6);//clump thickness --right side
	//clumpthickness <=6
	insert(3);//cell size --right side	
	//cell size > 3
	insert(5);//maringal adhession --right side	
}
/*
Desc: Test if binary tree workes?
Parm: N/A
Returns: N/A
*/
void DecisionTree::preorder(Node* root)
{
	if (root == nullptr) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

/*
Desc: Gives the results of a patient 
Parm: Node pointer and Patient object
Returns: N/A , however it does assign the last value to 2 (benign) 4 (malignant)
*/
void DecisionTree::results(Node* root,Patient& p)
{
	if (p.cellSize <= root->data)
		results(root->left, p);
	if (p.cellSize > root->data)
		results(root->right, p);
		
}
/*
Desc: Prints out tree
Parm: N/A
Returns: N/A
*/
void DecisionTree::print()
{
	preorder(root);
}

/*
Desc: Calls the recurssive function
Parm: Patient object
Return: N/A
*/
void DecisionTree::results(Patient& p)
{
	results(root,p); 
}
