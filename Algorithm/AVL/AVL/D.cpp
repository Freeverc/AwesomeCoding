// BST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct  TreeNode {
	int val;
	int parent;
	TreeNode* left, * right;
	TreeNode(int x, int p) {
		val = x;
		parent = p;
		left = NULL;
		right = NULL;
	}
};


TreeNode * insert(TreeNode * root, int x, int parent) {
	if (!root)
		root = new TreeNode(x, parent);
	else {
		int num = root->val;
		if (x < num)
			root->left = insert(root->left, x, num);
		else if (x >= num)
			root->right = insert(root->right, x, num);
	}
	return root;
}

void printTree(TreeNode * root)
{
	if (!root)
		return;
	if (root->left)
		printTree(root->left);
	cout << root->parent<< " ";
	if (root->right)
		printTree(root->right);
	return;
}

int main0()
{
	int n, num;
	cin >> n;
	vector<int> parent(n, 0);
	TreeNode * root = NULL;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		root = insert(root, num, 0);
	}
	printTree(root);
	return 0;
}