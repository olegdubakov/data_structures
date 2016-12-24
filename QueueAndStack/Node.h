#pragma once
using namespace std;

template <typename T>
class Node
{
protected:
	Node *Next;
	T Data;
public:
	Node(T data, Node *next);

	~Node();

	T GetData();
};

template <typename T>
Node<T>::Node(T data, Node *next)
{
	Data = data;
	Next = next;
}

template <typename T>
Node<T>::~Node()
{

}
