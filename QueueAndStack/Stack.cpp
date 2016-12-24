#include "Node.cpp"

template <typename T>
class Stack
{
public:
	Stack()
	{
		head = NULL;
	}

	void Add(T value)
	{
		if (head == NULL)
		{
			head = new Node<T>(value, NULL);
		}
		else
		{
			Node<T>* temp = new Node<T>(value, NULL);
			temp->Next = head;
			head = temp;
		}
	}

	T Get()
	{
		if (head == NULL)
		{
			return NULL;
		}

		T result = head->Data;
		Node<T> *temp = head;

		head = head->Next;
		delete temp;

		return result;
	}

private:
	Node<T>* head;
};