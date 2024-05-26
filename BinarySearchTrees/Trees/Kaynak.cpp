#include <iostream>
#include <queue>
using namespace std;
class Node {
public: 
	int deger;
	Node* left;
	Node* right;
	Node(int deger) {
		this->deger = deger;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree {
public:
	Node* root;
	BinarySearchTree() {
		root = NULL;
	}
	~BinarySearchTree() {
		deleteAllNode(root);
	}
	void deleteAllNode(Node* node) {
		if (node == NULL)
			return;
		if (node->left != NULL) {
			deleteAllNode(node->left);
		}
		if (node->right != NULL) {
			deleteAllNode(node->right);
		}
		delete node;
	}
	bool insertNode(int deger)
	{
		Node* node = new Node(deger);

		if (root == NULL)
		{
			root = node;
			return true;
		}

		Node* tmp = root;
		while (true)
		{
			if (node->deger == tmp->deger)
			{
				cout << "node eklenmeye calisiliyor!\n";
				return false;
			}

			if (node->deger < tmp->deger)
			{
				if (tmp->left == NULL)
				{
					tmp->left = node;
					return true;
				}
				tmp = tmp->left;
			}
			else {
				if (tmp->right == NULL)
				{
					tmp->right = node;
					return true;
				}
				tmp = tmp->right;
			}

		}
	}


	void DFSPreOrderSearchPrintAllNodes(Node* node)
	{
		cout << node->deger << " , ";
		if (node->left != NULL)
		{
			DFSPreOrderSearchPrintAllNodes(node->left);
		}
		if (node->right != NULL)
		{
			DFSPreOrderSearchPrintAllNodes(node->right);
		}
	}
	void DFSPostOrderSearchPrintAllNodes(Node* node)
	{
		if (node->left != NULL)
		{
			DFSPostOrderSearchPrintAllNodes(node->left);
		}
		if (node->right != NULL)
		{
			DFSPostOrderSearchPrintAllNodes(node->right);
		}
		cout << node->deger << " , ";
	}
	void DFSInOrderSearchPrintAllNodes(Node* node)
	{
		if (node->left != NULL)
		{
			DFSInOrderSearchPrintAllNodes(node->left);
		}
		cout << node->deger << " , ";
		if (node->right != NULL)
		{
			DFSInOrderSearchPrintAllNodes(node->right);
		}
	}
	void BreadthFirstSearch() {
		queue<Node*>queue1;
		queue1.push(root);
		while (queue1.size()>0)
		{
			Node* node = queue1.front();
			queue1.pop();
			cout << node->deger << " , ";
			if (node->left != NULL) {
				queue1.push(node->left);
			}
			if (node->right != NULL) {
				queue1.push(node->right);
			}
		}
	}

	Node* DFSPreOrderSearchAra(Node* node, int arananDeger)
	{
		if (node == NULL || node->deger == arananDeger)
		{
			return node;
		}

		if (arananDeger < node->deger)
		{
			return DFSPreOrderSearchAra(node->left, arananDeger);
		}
		else {
			return DFSPreOrderSearchAra(node->right, arananDeger);
		}
	}
};


int main()
{
	BinarySearchTree* bst = new BinarySearchTree();
	bst->insertNode(52);
	bst->insertNode(27);
	bst->insertNode(15);
	bst->insertNode(30);
	bst->insertNode(78);
	bst->insertNode(65);
	bst->insertNode(53);


	bst->DFSPreOrderSearchPrintAllNodes(bst->root);
	Node* ptr = bst->DFSPreOrderSearchAra(bst->root, 42);
	if (ptr != NULL)
	{
		cout << "\nAradiginiz sonuc bulundu: " << ptr->deger << endl;
	}
	else {
		cout << "\nAradiginiz deger mevcut degil!\n";
	}

	delete bst;
}
