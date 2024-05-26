#include <iostream>

using namespace std;

class Node {
public:
	int deger;
	Node* next;

	Node(int deger)
	{
		this->deger = deger;
		next = NULL;
	}
};

class Queue {
private:
	Node* head;
	Node* tail;
	int count;

public:
	Queue(int deger)
	{
		Node* node = new Node(deger);
		head = node;
		tail = node;
		count = 1;
	}

	~Queue()
	{
		Node* tmp = head;
		while (head)
		{
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}

	void printAll()
	{
		Node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->deger << ", ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	int getHeadValue()
	{
		if (count == 0)
			return INT_MIN;
		return head->deger;
	}

	int getTailValue()
	{
		if (count == 0)
			return INT_MIN;
		return tail->deger;
	}

	int getCount()
	{
		return count;
	}

	void enqueue(int deger)
	{
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


	int dequeue()
	{
		if (count == 0)
			return INT_MIN;  // veya -1 de donebilirsiniz, tasariminize gore bu degeri degistirebilirsiniz.

		Node* tmp = head;
		int deger = head->deger;
		if (count == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else {
			head = head->next;
		}
		delete tmp;
		count--;
		return deger;
	}

	bool isEmpty()
	{
		if (count == 0) return true;
		else
			return false;
	}
};

int main()
{
	Queue* queue = new Queue(12);
	queue->enqueue(24);
	queue->enqueue(7);
	queue->enqueue(15);

	cout << "Kuyruktan cikan node degeri: " << queue->dequeue() << endl;

	cout << "count: " << queue->getCount() << endl;
	cout << "head value: " << queue->getHeadValue() << endl;
	cout << "tail value: " << queue->getTailValue() << endl;
	queue->printAll();
}