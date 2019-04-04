#pragma once
class bst
{
	struct node {
		int data;
		node* L = nullptr;
		node* R = nullptr;
	};
	node* root = nullptr;
	bool searching_number = false;
public:
	typedef node* iterator;
	typedef void(*callback)(int);
	int get_data(iterator node);
	iterator get_L(iterator node);
	iterator get_R(iterator node);
	iterator get_root();
	bool isempty();
	bool search(int key);
	void search_in_branch(int key, iterator itr);
	int add(int key);
	int add_element(iterator prebranch, iterator branch, int key);
	int dark_deep_tree(iterator node);
	void delete_elem(int value, iterator branch, iterator pre_branch);
	int max(int x1, int x2);
	void RL_del(iterator redirect, iterator prev, iterator del_elem);
	void delete_by_value(int del_elem);
	void destruct();
	void cut(iterator itr);
	void symetric(node *branch, callback output);
	void LNR(callback output);
	void reversive(node *branch, callback output);
	void LRN(callback output);
	void pre_order(node *branch, callback output);
	void NLR(callback output);
	void width(callback output);
	bst();
	~bst();
};