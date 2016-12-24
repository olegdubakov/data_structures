#pragma once
#include "deque.cpp"

template<typename T>
void Print(Deque<T> deque, int size, char* title = NULL)
{
	if (title != NULL)
	{
		cout << title;
	}

	for (int i = 0; i < size; i++)
	{
		cout << deque[i] << " ";
	}

	cout << endl;
}

template <class Functor, typename T>
void cocktail_sort(Deque<T> &deque, Functor functor)
{
	bool swapped = true;
	int start = 0;
	int end = deque.size() - 1;

	while (swapped)
	{
		swapped = false;

		for (int i = 0; i < end; ++i)
		{
			if (functor(deque[i + 1], deque[i]))
			{
				swap(deque[i], deque[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}

		--end;

		for (int i = end - 1; i >= start; i--)
		{
			if (functor(deque[i + 1], deque[i]))
			{
				swap(deque[i], deque[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
}

template <class Functor, typename T>
T get_element_by_condishion (Deque<T> &deque, Functor functor)
{
	for (int i = 0; i < deque.size(); i++)
	{
		functor(deque[i]);
	}

	return functor.value;
}
