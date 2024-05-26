#include <iostream>

using namespace std;


class Node {
public:
	int deger;
	Node* next;
	Node* prev;

	Node(int deger) {
		this->deger = deger;
		next = NULL;
		prev = NULL;
	}
};
class doublyLinkedList {
private:
	Node* head;
	Node* tail;
	int count;

public:
	doublyLinkedList(int deger) {
		Node* node = new Node(deger);
		head = node;
		tail = node;
		count = 1;
	}
	~doublyLinkedList() {
		Node* tmp = head;
		while (head != NULL) {
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}
	void printList() {
		Node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->deger << " , ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	void printHead() {
		if (head != NULL)
			cout << "Head: " << head->deger << endl;
	}

	void printTail() {
		if (tail != NULL)
			cout << "Tail: " << tail->deger << endl;
	}

	void getCount() {
		cout << "List Count: " << this->count << endl;
	}
	void appendList(int deger) {
		Node* node = new Node(deger);

		if (count == 0)
		{
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		count++;
	}
	void deleteLastNode() {
		if (count == 0)
			return;
		Node* temp = tail;
		if(count!=1){
			tail = tail->prev;
			tail->next = NULL;
			
		}
		else if (count == 1) {
			head == NULL;
			tail == NULL;
		}
		delete temp;
		count--;
	}
	void addFirst(int deger)
	{
		Node* newNode = new Node(deger);
		if (count == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev =newNode,
			head = newNode;
		}
		count++;
	}
	void deleteFirst()
	{
		if (count == 0)
			return;

		Node* temp = head;

		if (count == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else {
			head = head->next;
			head->prev = NULL;
		}
		delete temp;
		count--;
	}

	Node* getNode(int index)
	{
		// Boundary condition check
		if (index < 0 || index >= count)
			return NULL;
		Node* temp = head;
		if (index < count / 2) {
			for (int i = 0; i < index; i++) {

				temp = temp->prev;
			}
		}
		else {
			temp = tail;
			for (int i = count - 1; i > index; i++) {
				temp = temp->prev;
			}
		}
		return temp;
	}
	bool setNode(int i, int deger) {
		Node* tmp = getNode(i);
		if (tmp != NULL) {
			tmp->deger;
			return true;
		}
		else {
			return false;
		}
	}
	bool insertNode(int index, int deger)
	{
		if (index >= 0 && index <= count)
		{
			if (index == 0) {
				addFirst(deger);
				return true;
			}

			if (index == count) {
				appendList(deger);
				return true;
			}

			Node* yeniNode = new Node(deger);
			Node* leftNode = getNode(index - 1);
			Node* rightNode = getNode(index);
			yeniNode->next = rightNode;
			yeniNode->prev = leftNode;
			leftNode->next = yeniNode;
			rightNode->prev = yeniNode;
			count++;
			return true;
		}
		else
			return false;
	}
	void deleteNode(int index)
	{
		if (index >= 0 && index < count)
		{
			if (index == 0)
			{
				deleteFirst();
			}
			else if (index == count - 1)
			{
				deleteLastNode();
			}
			else
			{
				Node* del = getNode(index);
				del->next->prev = del->prev;
				del->prev->next=del->next,
				delete del;
				count--;
			}
		}
	}
};
int main()
{
	doublyLinkedList* doublylinkedList1 = new doublyLinkedList(12);
	
	doublylinkedList1->getCount();
	doublylinkedList1->printHead();
	doublylinkedList1->printTail();
	doublylinkedList1->printList();
	

	delete doublylinkedList1;
}