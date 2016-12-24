#include <iostream>
#include "Queue.cpp"
#include "Stack.cpp"

using namespace std;

void main()
{
	cout << "Begin" << endl;

	cout << "Queue:" << endl;
	Queue<int> queue;

	queue.Add(1);
	queue.Add(2);
	queue.Add(3);
	queue.Add(4);
	queue.Add(5);

	cout << queue.Get() << endl;
	cout << queue.Get() << endl;
	cout << queue.Get() << endl;

	cout << "Stack:" << endl;
	Stack<int> stack;

	stack.Add(1);
	stack.Add(2);
	stack.Add(3);
	stack.Add(4);
	stack.Add(5);

	cout << stack.Get() << endl;
	cout << stack.Get() << endl;
	cout << stack.Get() << endl;

}