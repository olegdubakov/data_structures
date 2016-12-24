#pragma once

template <typename T>
class Node
{
public:
	T Data;
	Node *Next;

	Node(T data, Node *next)
	{
		Data = data;
		Next = next;
	}

	T GetData()
	{
		return Data;
	}
};