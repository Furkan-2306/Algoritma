#include <iostream>

using namespace std;


class Node {
public:
	int deger;
	Node* next;

	Node(int deger) {
		this->deger = deger;
		next = NULL;
	}
};


class LinkedList {
private:
	Node* head;
	Node* tail;
	int count;

public:
	LinkedList(int deger) {
		Node* node = new Node(deger);
		head = node;
		tail = node;
		count = 1;
	}

	~LinkedList() {
		Node* tmp = head;
		while (head) {
			head = head->next;
			delete tmp;
			tmp = head;
		}
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
			tail = node;
		}
		count++;
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


	void deleteLastNode()
	{
		if (count == 0)
			return;

		Node* temp1 = head;
		Node* temp2 = head;

		while (temp1->next)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}

		tail = temp2;
		tail->next = NULL;
		count--;
		if (count == 0)
		{
			head = NULL;
			tail = NULL;
		}

		delete temp1;
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
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp;
	}


	bool setValue(int index, int yeniDeger)
	{
		Node* temp = getNode(index);

		if (temp != NULL)
		{
			temp->deger = yeniDeger;
			return true;
		}
		return false;
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
			Node* temp = getNode(index - 1);
			yeniNode->next = temp->next;
			temp->next = yeniNode;
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
				Node* temp = getNode(index - 1);
				temp->next = del->next;
				delete del;
				count--;
			}
		}
	}


};


int main()
{
	LinkedList* linkedList1 = new LinkedList(12);
	linkedList1->appendList(5);
	linkedList1->appendList(24);
	linkedList1->appendList(8);
	linkedList1->appendList(7);

	linkedList1->getCount();
	linkedList1->printHead();
	linkedList1->printTail();
	linkedList1->printList();

	linkedList1->deleteNode(1);

	linkedList1->printList();

	delete linkedList1;
}