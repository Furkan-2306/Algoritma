#include <iostream>
using namespace std;
class Node {
public: 
	int deger;
	Node* next;
	Node(int deger){
		this->deger = deger;
		next = NULL;
	}
};
class stack {
private:
	Node* top;
	int count;
public:
	stack(int deger) {
		Node* node = new Node(deger);
		top = node;
		count = 1;
	}
	~stack() {
		Node *tmp = top ;
		while (top != NULL) {
			top = top->next;
			delete tmp;
			tmp = top;
		}
	}
	void printAll() {
		Node* tmp = top;
		while (tmp != NULL) {
			cout << tmp->deger << endl;
			tmp = tmp->next;
		}
	}
	void printTop(){
		if (top != NULL) {
			cout << "Top deger : " << top->deger << endl;
		}
		else
			cout << "stack bos " << endl;
	}
	int getCount() {
		return count;
	}
	void push(int deger) {
		Node* node = new Node(deger);
		node->next = top;
		top = node;
		count++;
	}
	int pop() {
		//boþ popta hata vermeme
		if (top == NULL) {
			cout << "bos pop islemi yapilmaya calisiyor";
			exit(1);
		}

		/*if (count == 0) {
			return INT_MIN; -1 de yazýlabilir  
		}*/

		Node* tmp = top;
		int deger = top->deger;
		top = top->next;
		delete tmp;
		count--;
		return deger;
	}
	bool isEmty() {
		if (count == 0)
			return true;
		return false;
	}
};
int main()
{
	stack* stack1 = new stack(24);
	stack1->push(8);
	stack1->push(40);
	cout << " node sayisi : " << stack1->getCount() << endl;
	stack1->printAll();

	if (stack1->getCount() != 0)
		cout << "edilen deger:"<< stack1->pop()<< endl;
	stack1->printTop();
}