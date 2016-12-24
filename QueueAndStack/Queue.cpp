#include "Node.cpp"

template <typename T>
class Queue
{
public:
	Queue()
	{
		head = tail = NULL;
	}
	~Queue()
	{

	}

	void Add(T value)
	{
		if (tail == NULL)
		{
			head = tail = new Node<T>(value, NULL);
		}
		else
		{
			tail->Next = new Node<T>(value, NULL);
			tail = tail->Next;
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
	Node<T>* tail;
};