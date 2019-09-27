// This file contains the implementation of the BST to store
// movie information

#include "movies.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using std::cout;



// IMPLEMENTATION FOR MOVIEBST CLASS

MovieBST::MovieBST(){
	root=0;
}

MovieBST::~MovieBST(){
	clear(root);
}

void MovieBST::clear(MovieNode *n){
	if(n){
		clear(n->left);
		clear(n->right);
		delete n;
	}
}

void MovieBST::insert(string name,double rating){

	if(!root){
	root=new MovieNode(name,rating);
	}
	insert(name,rating,root);

}

void MovieBST::insert(string name, double rating,MovieNode *n){

	if (name<n->name){
	if (n->left)
		insert(name,rating,n->left);
	else {
		n->left = new MovieNode(name,rating);
		n->left->parent = n;
		
	}
	}
	else if(name>n->name){
	if (n->right)
		insert(name,rating,n->right);
	else {
		n->right = new MovieNode(name,rating);
		n->right->parent = n;

	}
	}
}

void MovieBST::insertByRating(string name,double rating){
	if(!root){
		root=new MovieNode(name,rating);
	}
	insertByRating(name,rating,root);
}

void MovieBST::insertByRating(string name,double rating,MovieNode *n){
	if(rating<n->rating){
	if(n->left)
		insertByRating(name,rating,n->left);
	else {
		n->left=new MovieNode(name,rating);
		n->left->parent=n;
	}
	}
	else if(rating>n->rating){
	if(n->right)
		insertByRating(name,rating,n->right);
	else{
		n->right=new MovieNode(name,rating);
		n->right->parent=n;
	}
	}
}

void MovieBST::printPreOrder()const{
	printPreOrder(root);
}

void MovieBST::printPreOrder(MovieNode *n)const{
	if(n){
		cout << n->name << ", " << n->rating << ", " << getDepth(root,n,0) << endl;
		printPreOrder(n->left);
		printPreOrder(n->right);
	}
}

/*
bool MovieBST::contains(string prefix)const{
	vector<MovieNode> movieVector;
	MovieNode* ptr=root;
	while(ptr!=NULL){
		if(ptr->name.substr(0,prefix.length())==prefix){movieVector.push_back(ptr);}
		if(ptr->name.substr(0,prefix.length())>prefix){ptr=ptr->right;}
		if(ptr->name.substr(0,prefix.length())<prefix){ptr=ptr->left;}
	}
	if(ptr==NULL){return false;}
	if(ptr->name.substr(0,prefix.length())==prefix){return true;}
					
	return false;
}
*/

// Contains: returns true if given node is in the BST, false if not
bool MovieBST::contains(MovieNode* n)const{
	
	MovieNode *ptr = root;

	while(ptr!=NULL){
		if(ptr->name==n->name)
			return true;
		if(ptr->name>n->name)
			ptr=ptr->right;
		else if(ptr->name<n->name)
			ptr=ptr->left;
	}
	if(ptr==NULL)
		return false;
	if(ptr->name==n->name)
		return true;

	return false;

}

int MovieBST::getDepth(MovieNode* root,MovieNode* n,int depth)const{
	if(root==NULL)
		return 0;
	if(root==n)
		return depth;

	int level = getDepth(root->left,n,depth+1);
	if(level!=0)
		return level;

	return getDepth(root->right,n,depth+1);
}

int MovieBST::nVisited(MovieNode* root,int depth){
	if(root==NULL)
		return depth;
	int level=nVisited(root->left,depth+1);
	if(level!=0)
		return level;
	return nVisited(root->right,depth+1);
}

void MovieBST::search(string prefix){
	MovieBST a;
	if(!root){return;}
	searchHelper(a,root,prefix);
	//a.printPreOrder();
	a.getHighestRated();
}

void MovieBST::searchHelper(MovieBST &a,MovieNode *n, string prefix){
	
	if(n){
	if(n->name.substr(0,prefix.length())==prefix){
		a.insertByRating(n->name,n->rating);
	}
	searchHelper(a,n->left,prefix);
	searchHelper(a,n->right,prefix);
	}
}


void MovieBST::getHighestRated(){
	
	MovieNode* tmp = root;
	
	while(tmp->right){
		tmp=tmp->right;
	}

	cout << "Best movie is " << tmp->name << " with rating " << tmp->rating << endl;

}

void MovieBST::inOrderSearch(MovieNode *n){

	if(!n){
		return;
	}

	inOrderSearch(n->left);
	inOrderSearch(n->right);
}


double MovieBST::searchTime(MovieBST &test,int w){

  MovieBST::MovieNode* tmp=root;
  
  ofstream myfile;
  myfile.open("timing_file.txt");


  double total=0.0;

  for(int i=0;i<w;i++){

  
    clock_t start=clock();
    test.inOrderSearch(tmp);
    clock_t end=clock();
    total+=difftime(end,start);
    myfile << (total*CLOCKS_PER_SEC)/w << "\n";
    cout << (total*CLOCKS_PER_SEC)/w << endl;

    }

    return 0.0;

}

/*
void MovieBST::search(MovieBST &a,string prefix)const{
	vector<string> movieTitles;
	MovieNode* n=a.root;

	if(a.contains(prefix)==true){
		movieTitles.push_back(n->name);		
	}
	
	
	cout << "Best movie is " << movieTitles[0] << " with rating " << n->rating << endl;


}

MovieBST::MovieNode* MovieBST::searchMovies(MovieNode* root, string prefix) const{
	MovieNode* tmp=nullptr;
	if(root->name.substr(0,prefix.length())==prefix){
		tmp->name=root->name;
		tmp->rating=root->rating;
		return tmp;	
	}
	
	else if(root->name.substr(0,prefix.length())<prefix){
		MovieNode* k = searchMovies(root->right,prefix);
		return k;
	}
	else{
		return searchMovies(root->left,prefix);
	}
	
	return tmp;
}
*/

/*
void MovieBST::search2(string prefix, MovieNode* n)const{
	vector<string> movieTitles;
	cout << "test " << endl;
	while(n){
		if(n->name.substr(0,prefix.length())==prefix){
			movieTitles.push_back(n->name);
		}
		else if(n->name.substr(0,prefix.length())<prefix){
			search2(prefix,n->left);
		}
		else{
			search2(prefix,n->right);
		}
	}
	cout << movieTitles[0] << endl;
}

void MovieBST::search2(string prefix)const{

	search2(prefix,root);
}


void MovieBST::search(string prefix)const{
	MovieNode *ptr = root;
	string highestMovieName=ptr->movieName;
	double highestMovieRating=ptr->movieRating;

	
	while(ptr->left!=NULL&&ptr->right!=NULL){
		if(ptr->left->movieName.find(prefix)==true){
			highestRating=ptr->left->movieRating;
			ptr=ptr->left;
		}
		if(ptr->right->movieName.find(prefix)==true&&ptr->right->movieRating > highestRating){
			highestRating=ptr->right->movieRating;
			ptr=ptr->right;
		}
	}

	
	while(ptr!=NULL){
		if(ptr->movieName.find(prefix)==true){
			highestRating=ptr->movieRating;
			ptr=ptr->left;
			if(ptr->movieName.find(prefix)==true && ptr->movieRating>highestRating){
				highestRating=ptr->movieRating;

			}
		}
		else{
			ptr=ptr->right;
		}

	}
*/	


	
	

