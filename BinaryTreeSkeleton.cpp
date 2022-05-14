#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node() {
		val = 0;
		left = NULL;
		right = NULL;
	}

	Node(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

void preOrderTraversal(Node* root) {
	if(root == NULL) return;
	cout << root->val << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right); 
}

void inOrderTraversal(Node* root) {
	if(root == NULL) return;
	inOrderTraversal(root->left);
	cout << root->val << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	if(root == NULL) return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->val << " ";
}

vector<vector<int>> levelOrderTraversal(Node* root) {
	vector<vector<int>> ans;
	if(root == NULL) return ans;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		vector<int> level;
		for(int i=0;i<q.size();i++) {
			Node* node = q.front();
			q.pop();
			if(node->left != NULL) q.push(node->left);
			if(node->right != NULL) q.push(node->right);
			level.push_back(node->val);
		}
		ans.push_back(level);
	}
	return ans;
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	inOrderTraversal(root);
	cout << "\n";
	preOrderTraversal(root);
	cout << "\n";
	postOrderTraversal(root);
	cout << "\n";
	vector<vector<int>> ans = levelOrderTraversal(root);
	for(auto it: ans) {
		for(auto i:it){
			cout << i << " ";
		}
	}
}
