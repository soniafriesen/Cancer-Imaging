/*
Program: Breast Cancer Decision Tree Project 2
Purpose: Demonstrate a decision tree and graphs
Coder: Sonia Friesen 0813682
Date: Due Dec.8th 2019
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "Patient.hpp"
#include "DecisionTree.hpp"
#include <time.h>
using namespace std;

int main(int argc, char* argv[])
{
	vector<Patient> dataSet;
	
	ifstream patients;
	patients.open("wisconsin data.csv", 'r');
	if (!patients)
	{
		cerr << "Error, file failed to open\n";
		return EXIT_FAILURE;
	}

	
	//use getline and load files
	vector<vector<string>>patientInfo;
	vector<string> patientData;
	string ch;
	
	while (patients.good()){
		//getting each "number" 
		getline(patients, ch, ',');
		patientData.push_back(ch);
		if (ch == "\n")
		{
			patientInfo.push_back(patientData);
			patientData.clear();
		}
				
	}
	patients.close();
	

	//create the decision tree by hard codding values.
	DecisionTree* tree = new DecisionTree();	
	tree->createTree(); //function that creates the decision tree.
	
	for (auto x : patientInfo)
	{
		cout << "patientInfo printing" << endl;
		
		for (auto y : x)
			cout << y << endl;
	}
		
	//test tree
	tree->print();
	cout << endl;
	
	srand(unsigned(time(NULL))); //change randmo numbers
	for (int i = 0; i < 5; i++)
	{
		Patient p;
		p.code = rand() % 999;
		p.cThickness = rand() % 10;
		p.cellSize = rand() % 10;
		p.cellShape = rand() % 10;
		p.adhesion = rand() % 10;
		p.epithelialSize = rand() % 10;
		p.bareNuclei = rand() % 10;
		p.chromatin = rand() % 10;
		p.normalNucleoli = rand() % 10;
		p.mitoses = rand() % 10;
		p.benignorMali = 0;
		dataSet.push_back(p);
	}

	for (auto x : dataSet)
		cout << x.code << ", " << x.cThickness << ", " << x.cellSize << ", " << x.cellShape << ", "
		<< x.adhesion << ", " << x.epithelialSize << ", " << x.bareNuclei << ", " << x.chromatin << ", " 
		<< x.normalNucleoli << ", " << x.mitoses <<", " << x.benignorMali << endl; 
	
	for (auto x : dataSet)
		tree->results(x);
	cout << "\nReults are in" << endl;
	for (auto x : dataSet)
		cout << x.code << ", " << x.cThickness << ", " << x.cellSize << ", " << x.cellShape << ", "
		<< x.adhesion << ", " << x.epithelialSize << ", " << x.bareNuclei << ", " << x.chromatin << ", "
		<< x.normalNucleoli << ", " << x.mitoses << ", " << x.benignorMali << endl;

	delete tree;
}