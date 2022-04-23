#pragma once
#include "MethodsDeclaration.h"

enum colorEnum
{
	red = 0,
	black = 1
};

struct red_black_tree_node
{
	int key;
	int value;
	colorEnum color;
	red_black_tree_node* left_side;
	red_black_tree_node* right_side;
	red_black_tree_node* parent;
	red_black_tree_node(int k, int v, colorEnum c, red_black_tree_node* par, red_black_tree_node* left, red_black_tree_node* right) :
		key(k), color(c), parent(par), left_side(left), right_side(right) { };
};

class red_black_tree
{
public:
	void insert(int key, int value);
	void remove(int key);
	int find(int key);
	ListOfNum get_keys();
	ListOfNum get_values();
	void clear();
	void print(red_black_tree_node* node);
	//red_black_tree_node* root;
};