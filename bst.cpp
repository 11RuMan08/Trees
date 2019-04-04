#include "pch.h"
#include <iostream>
#include "bst.h"
#include <queue>
using namespace std;

bst::bst()
{
}

bst::~bst()
{
}

bool bst::isempty() {
	if (root) {
		return false;
	}
	else {
		return true;
	}
}

bool bst::search(int key) {
	searching_number = false;
	search_in_branch(key, get_root());
	return searching_number;
}

void bst::search_in_branch(int key, iterator itr) {
	if (itr) {
		if (key > get_data(itr)) {
			search_in_branch(key, itr->R);
		}
		else {
			if (key < get_data(itr)) {
				search_in_branch(key, itr->L);
			}
			else
			{
				searching_number = true;
			}
		}
	}
	else {
		searching_number = false;
	}
}

int bst::add(int key) {
	if (isempty()) {
		node *tmp = new node;
		tmp->data = key;
		tmp->L = nullptr;
		tmp->R = nullptr;
		root = tmp;
		return 0;
	}
	else
	{
		if (key < get_data(get_root()))
			return add_element(get_root(), get_L(get_root()), key);
		else
			return add_element(get_root(), get_R(get_root()), key);
	}
}

int bst::add_element(iterator prebranch, iterator branch, int key) {
	if (branch == nullptr) {
		node *tmp = new node;
		tmp->data = key;
		tmp->L = nullptr;
		tmp->R = nullptr;
		if (key < prebranch->data)
			prebranch->L = tmp;
		else
			prebranch->R = tmp;

		return 0;
	}
	else {
		if (key < branch->data)
			return add_element(branch, branch->L, key);
		else
			return add_element(branch, branch->R, key);
	}
}

int bst::get_data(iterator node) {
	return node->data;
}

bst::iterator bst::get_root() {
	return root;
}

bst::iterator bst::get_L(iterator node) {
	return node->L;
}

bst::iterator bst::get_R(iterator node) {
	return node->R;
}

int bst::dark_deep_tree(iterator node) {
	int h1 = 0;
	int h2 = 0;
	if (node == nullptr)
		return 0;
	if (node->L)
		h1 = dark_deep_tree(node->L);
	if (node->R)
		h2 = dark_deep_tree(node->R);
	return(max(h1, h2) + 1);
}

int bst::max(int x1, int x2) {
	if (x1 > x2)
		return x1;
	else
		return x2;
}

void bst::delete_elem(int value, iterator branch, iterator pre_branch) {

	if (branch == nullptr)
		return;


	if (value > branch->data)
		delete_elem(value, branch->R, branch);
	else
	{
		if (value < branch->data)
			delete_elem(value, branch->L, branch);
		else {

			if ((branch->R == nullptr) && (branch->L == nullptr))
			{
				if (pre_branch->L->data == branch->data) {
					pre_branch->L = nullptr;
					delete branch;
				}
				else {
					pre_branch->R = nullptr;
					delete branch;
				}
			}
			else {

				if ((branch->R == nullptr) && (branch->L))
				{
					if (pre_branch->L->data == branch->data) {
						pre_branch->L = branch->L;
						delete branch;
					}
					else {
						pre_branch->R = branch->L;
						delete branch;
					}
				}
				else
				{
					if ((branch->L == nullptr) && (branch->R))
					{
						if (pre_branch->L->data == branch->data) {
							pre_branch->L = branch->R;
							delete branch;
						}
						else {
							pre_branch->R = branch->R;
							delete branch;
						}
					}
					else
						RL_del(branch->L, branch, branch);
				}
			}
		}
	}
}

void bst::RL_del(iterator redirect, iterator redirect_prev, iterator del_elem) {
	if (redirect->R)
	{
		RL_del(redirect->R, redirect, del_elem);
	}
	else
	{
		del_elem->data = redirect->data;
		redirect_prev->R = redirect->L;
		delete redirect;
	}
}

void bst::delete_by_value(int del_elem) {
	delete_elem(del_elem, root, root);
}

void bst::destruct() {
	cut(root);
	root = nullptr;
}

void bst::cut(iterator itr) {
	if (itr->L)
		cut(itr->L);
	if (itr->R)
		cut(itr->R);
	delete itr;
}

void bst::symetric(node *branch, callback output) {
	if (!branch) {
		return;
	}
	symetric(branch->L, output);
	output(branch->data);
	symetric(branch->R, output);
}

void bst::LNR(callback output) {
	symetric(root, output);
}

void bst::reversive(node *branch, callback output) {
	if (!branch) {
		return;
	}
	reversive(branch->L, output);
	reversive(branch->R, output);
	output(branch->data);
}

void bst::LRN(callback output) {
	reversive(root, output);
}

void bst::pre_order(node *branch, callback output) {
	if (!branch) {
		return;
	}
	output(branch->data);
	pre_order(branch->L, output);
	pre_order(branch->R, output);
}

void bst::NLR(callback output) {
	pre_order(root, output);
}

void bst::width(callback output) {
	queue <node*>q;
	q.push(root);        // корень в очередь
	while (!q.empty()) {
		node* x = q.front();
		output(x->data);              // посетить x
		if (x->L)   // x.left - левое поддерево
			q.push(x->L);
		if (x->R)  // x.right - правое поддерево
			q.push(x->R);
		q.pop();
	}
}