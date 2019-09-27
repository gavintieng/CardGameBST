// This file contains the declaration of the member variables, 
// member functions, etc implemented in movies.cpp
#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MovieBST{

public:

	struct MovieNode{

		//int depth;
		string name;
		double rating;
		int depth;
		
		MovieNode *left,*right,*parent;

		MovieNode(string n="",double r=0.0,int dep=0): name(n),rating(r),depth(dep),
		left(0),right(0),parent(0) { }


	};



	// Constructor
	MovieBST();

	// Destructor
	~MovieBST();

	// Member functions
	void insert(string name,double rating);

	// Inserts movie data into a BST sorted by rating
	void insertByRating(string name,double rating);
	
	void printPreOrder() const;
	
	bool contains(MovieNode* n)const;
	
	// Function to get the depth for a given MovieNode
	int getDepth(MovieNode* root,MovieNode* n,int depth)const;
	
	// Recursive function to search for MovieNodes with matching prefix
	void search(string prefix);
	
	// Helper function for the search function
	void searchHelper(MovieBST &a,MovieNode *n, string prefix);
	
	// Searches the BST for the movie with the highest rating 
	void getHighestRated();
	
	//MovieNode* searchMovies(MovieNode* root, string prefix) const;
	//void search(MovieBST &a,string prefix) const; //should return a vector of all the movies with prefix

	double searchTime(MovieBST &test,int w);
	void inOrderSearch(MovieNode *n);
	int nVisited(MovieNode* root,int depth);


	MovieNode *root;

	
private:

	//MovieNode *root;



	// Member functions for MovieNode
	void insert(string name,double rating,MovieNode *n);
	void insertByRating(string name,double rating,MovieNode *n);
	void clear(MovieNode *n);
	void printPreOrder(MovieNode *n)const;


};



#endif