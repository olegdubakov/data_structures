#pragma once
#include <iostream>
#include "functors.cpp"
#include "algorithms.cpp"

using namespace std;

void main()
{
	Deque<int> a;

	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}

	Print(a, a.size(), "Deque<int> a: ");

	Deque<int> c = a;
	Print(c, c.size(), "Deque<int> c, copy constructor: ");

	Deque<int> b(250);
	b = a;
	Print(b, b.size(), "Deque<int> b, operator=: ");

	cout << "a[5] = " << a[5] << endl;
	a[5] = 456;
	cout << "a[5] = " << a[5] << endl;

	cout << "a.at(3) - " << a.at(3) << endl;
	a.at(3) = 789;
	cout << "a.at(3) - " << a.at(3) << endl;

	Print(a, a.size(), "Deque<int> a: ");

	cout << "a.front() - " << a.front() << endl;
	cout << "a.back() - " << a.back() << endl;
	cout << "a.empty() - " << (a.empty() ? "true" : "false") << endl;
	cout << "a.size() - " << a.size() << endl;

	a.clear();
	Print(a, a.size(), "Deque<int> a, after a.clear();: ");

	b.insert(4, 100);
	Print(b, b.size(), "Deque<int> b, b.insert(4, 100): ");

	b.erase(6);
	Print(b, b.size(), "Deque<int> b, b.erase(6): ");
	
	cout << "-------------------" << endl;
	Print(b, b.size(), "Deque<int> b befor sort: ");

	sorter<int> sorter;
	cocktail_sort(b, sorter);

	Print(b, b.size(), "Deque<int> b after sort: ");

	cout << "-------------------" << endl;


	Deque<char*> stringDeque;

	stringDeque.push_back("aa");
	stringDeque.push_back("aaaaa");
	stringDeque.push_back("a");
	stringDeque.push_back("abababab");
	stringDeque.push_back("aaa");
	stringDeque.push_back("avavcvava");
	stringDeque.push_back("aaaaaa");

	Print(stringDeque, stringDeque.size(), "Deque<char*> stringDeque befor sort: ");

	stringSorter<char*> stringSorter;
	cocktail_sort(stringDeque, stringSorter);

	Print(stringDeque, stringDeque.size(), "Deque<char*> stringDeque after sort: ");

	cout << "-------------------" << endl;

	getMinInt gmi;
	int minInt = get_element_by_condishion(b, gmi);

	cout << "minInt in Deque<int> b - " << minInt << endl;
}

