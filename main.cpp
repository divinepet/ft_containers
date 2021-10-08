#include "ft_containers_tests/general.hpp"
#include <stack>
#include "Stack.hpp"

struct node {
	int val;
	node* left;
	node* right;
};

node* createNewNode(int x)
{
	node* nn = new node;
	nn->val = x;
	nn->left  = nullptr;
	nn->right = nullptr;

	return nn;
}

void bstInsert(node* &root, int x)
{
	if(root == nullptr) {
		root = createNewNode(x);
		return;
	}

	if(x < root->val)
	{
		if(root->left == nullptr) {
			root->left = createNewNode(x);
			return;
		} else {
			bstInsert(root->left, x);
		}
	}

	if( x > root->val )
	{
		if(root->right == nullptr) {
			root->right = createNewNode(x);
			return;
		} else {
			bstInsert(root->right, x);
		}
	}
}

int main()
{
	node* root = nullptr;

	bstInsert(root, 3);
	bstInsert(root, 4);
	cout << root->right->val << endl;

	return 0;
}