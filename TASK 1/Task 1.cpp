#include <iostream>
using namespace std;

struct node {
	node* leftchild;
	node* rightchild;
	int data;
};

class tree {
protected:
	node* root;
public:
	tree() : root(nullptr) {};
	virtual void insert(int val) = 0;
};

class BST : public tree {
private:

	node* findinordersuccessor(node* root) {
		while (root != nullptr && root->leftchild != nullptr) {
			root = root->leftchild;
		}
		return root;
	}

	void inorder(node* root) {
		if (root == nullptr) return;
		inorder(root->leftchild);
		cout << root->data << " ";
		inorder(root->rightchild);
	}

	node* deleteNode(node* root, int id) {
		if (!root) return nullptr;

		if (id < root->data) {
			root->leftchild = deleteNode(root->leftchild, id);
		}
		else if (id > root->data) {
			root->rightchild = deleteNode(root->rightchild, id);
		}
		else {
			if (!root->leftchild) {
				node* temp = root->rightchild;
				delete root;
				return temp;
			}
			if (!root->rightchild) {
				node* temp = root->leftchild;
				delete root;
				return temp;
			}
			node* succ = findinordersuccessor(root->rightchild);
			root->data = succ->data;
			root->rightchild = deleteNode(root->rightchild, succ->data);
		}
		return root;
	}

public:
	void insert(int val) {
		node* nn = new node;
		nn->data = val;
		nn->leftchild = nullptr;
		nn->rightchild = nullptr;

		if (root == nullptr) {
			root = nn;
		}
		else {
			node* temp = root;
			while (true) {
				if (val < temp->data) {
					if (temp->leftchild == nullptr) {
						temp->leftchild = nn;
						break;
					}
					else {
						temp = temp->leftchild;
					}
				}
				else {
					if (temp->rightchild == nullptr) {
						temp->rightchild = nn;
						break;
					}
					else {
						temp = temp->rightchild;
					}
				}
			}
		}
	}

	void inorderwrapper() {
		inorder(root);
		cout << endl;
	}

	void deletenodewrapper(int id) {
		root = deleteNode(root, id);
	}
};


int main() {
	  BST bst;
	  bst.insert(20);
	  bst.insert(19);
	  bst.insert(40);
	  bst.inorderwrapper();
	  bst.deletenodewrapper(19);
	  bst.inorderwrapper();

	return 0;
}