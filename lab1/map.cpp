#include "red_black_tree.h"
#include <iomanip>
#include <iostream>

using namespace std;

red_black_tree_node* root = nullptr;

void right_turn(red_black_tree_node* turn_y)
{
	red_black_tree_node* x = turn_y->left_side;
	turn_y->left_side = x->right_side;
	if (x->right_side != NULL) x->right_side->parent = turn_y;
	x->parent = turn_y->parent;
	if (turn_y->parent == NULL) root = x;
	else 
	{
		if (turn_y == turn_y->parent->right_side) turn_y->parent->right_side = x;
		else turn_y->parent->left_side = x;
	}
	x->right_side = turn_y;
	turn_y->parent = x;
}

void left_turn(red_black_tree_node* turn_x)
{
	red_black_tree_node* x = turn_x->right_side;
	turn_x->right_side = x->left_side;
	if (x->left_side != NULL) x->left_side->parent = turn_x;
	x->parent = turn_x->parent;
	if (turn_x->parent == NULL) root = x;
	else
	{
		if (turn_x == turn_x->parent->left_side) turn_x->parent->left_side = x;
		else turn_x->parent->right_side = x;
	}
	x->left_side = turn_x;
	turn_x->parent = x;
}

void red_black_tree::insert(int key, int value)
{
	red_black_tree_node* x = root;
	red_black_tree_node* y = nullptr;
	red_black_tree_node* node = new red_black_tree_node(key, value, red, nullptr, NULL, NULL);
		while (x != NULL)
		{
			y = x;
			if (node->key < x->key) x = x->left_side;
			else x = x->right_side;
		}
		node->parent = y;
		if (y == nullptr) root = node;
		else if (node->key < y->key) y->left_side = node;
		else y->right_side = node;
		if (node->parent == nullptr)
		{
			node->color = black;
			return;
		}
		if (node->parent->parent == nullptr) return;

	red_black_tree_node* p = node->parent;
	red_black_tree_node* uncle = p->parent;
	while (node->parent != nullptr && node->parent->color == colorEnum::red)
	{
		/*if (node->parent == node->parent->parent->right_side)
		{
			uncle = node->parent->parent->left_side;
			if (uncle->color == red)
			{
				uncle->color = black;
				node->parent->color = black;
				node->parent->parent->color = red;
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->left_side) {
					node = node->parent;
					right_turn(node);
				}
				node->parent->color = black;
				node->parent->parent->color = red;
				left_turn(node->parent->parent);
			}
		}*/
		if (p == uncle->left_side)
		{
			if (uncle->right_side->color == colorEnum::red)
			{
				uncle->right_side->color = black;
				uncle->left_side->color = black;
				uncle->color = red;
				node = uncle;
			}
			else if (p->right_side == node)
			{
				node = p;
				left_turn(node);
			}
			else
			{
				p->color = black;
				uncle->color = red;
				right_turn(uncle);
			}
		}
		else
		{
			if (uncle->left_side->color == colorEnum::red)
			{
				uncle->right_side->color = black;
				uncle->left_side->color = black;
				uncle->color = red;
				node = uncle;
			}
			else
			{
				node = p;
				right_turn(node);
				p->color = black;
				uncle->color = red;
				left_turn(uncle);
			}
		}
	}
	root->color = black;
}
void red_black_tree::print(red_black_tree_node* node)
{
	if (node == NULL)
		return;
	if (node->parent == NULL)
		cout << node->key << "(" << node->color << ") is root" << endl;
	else if (node->parent->left_side == node)
	{
		cout << node->key << "(" << node->color << ") is " << node->parent->key << "'s " << "left child" << endl;
	}
	else
	{
		cout << node->key << "(" << node->color << ") is " << node->parent->key << "'s " << "right child" << endl;
	}
	print(node->left_side);
	print(node->right_side);
}

int main()
{
	int value = 50, key[] = { 55,40,65,60,75,57 };
	red_black_tree map;
	ListOfNum maplist;
	for (int i = 0; i < 6; i++) {
		map.insert(key[i], key[i]);
	}
	//red_black_tree_node* node;
	map.print(root);
}