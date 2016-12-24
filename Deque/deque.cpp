#include <iostream>

using namespace std;

template <typename T>
class Deque
{
public:
	Deque<T>();
	Deque<T>(int _count);
	Deque<T>(const Deque<T> &_obj);

	~Deque<T>();

	// The assignment operator
	Deque<T>& operator=(const Deque<T>& deque);
	// Returns the n'th element.
	T& operator[](int value);

	// Access 'index' element
	T& at(int index);

	// Returns the first element. 
	T& front();
	// Returns the last element.
	T& back();

	// true if the deque's size is 0. 
	bool empty();
	// Returns the size of the deque.
	int size();

	// Erases all of the elements
	void clear();

	// Inserts 'value' before 'position'. 
	void insert(int position, T value);
	// Erases the element at 'position'.
	void erase(int position);

	// Inserts a new element at the end
	void push_back(T value);
	// Inserts a new element at the beginning
	void push_front(T value);

	// Removes the last element.
	T pop_back();
	// Removes the first element.
	T pop_front();


private:
	T* elements;
	int count;
	int maxSize;

	void CheckIndexOutOfRange(int index);
};

template <typename T>
Deque<T>::Deque<T>()
{
	count = 0;
	maxSize = 100;
	elements = new T[100];
}

template <typename T>
Deque<T>::Deque<T>(int _count)
{
	count = 0;
	maxSize = _count;
	elements = new T[maxSize];
}

template <typename T>
Deque<T>::Deque<T>(const Deque<T> &_obj)
{
	count = _obj.count;
	maxSize = _obj.maxSize;
	elements = new T[_obj.maxSize];

	for (int i = 0; i < count; i++)
	{
		elements[i] = _obj.elements[i];
	}

}

template <typename T>
Deque<T>::~Deque<T>()
{
	delete[] elements;
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& deque)
{
	this->count = deque.count;
	this->maxSize = deque.maxSize;
	this->elements = new T[deque.maxSize];

	for (int i = 0; i < count; i++)
	{
		elements[i] = deque.elements[i];
	}

	return *this;
}

template <typename T>
T& Deque<T>::operator[](int index)
{
	CheckIndexOutOfRange(index);
	return elements[index];
}

template<typename T>
T& Deque<T>::at(int index)
{
	CheckIndexOutOfRange(index);
	return elements[index];
}

template<typename T>
T & Deque<T>::front()
{
	return at(0);
}

template<typename T>
T & Deque<T>::back()
{
	return at(count - 1);
}

template<typename T>
bool Deque<T>::empty()
{
	return (count == 0);
}

template<typename T>
int Deque<T>::size()
{
	return count;
}

template<typename T>
void Deque<T>::clear()
{
	count = 0;
}

template<typename T>
void Deque<T>::insert(int position, T value)
{
	if (position == count)
	{
		push_back(value);
	}
	else if (position == 0)
	{
		push_front(value);
	}
	else
	{
		CheckIndexOutOfRange(position);

		if (count + 1 <= maxSize)
		{
			for (int i = count; i >= position; i--)
			{
				elements[i] = elements[i - 1];
			}
			elements[position] = value;
			count++;
		}
	}
}

template<typename T>
void Deque<T>::erase(int position)
{
	CheckIndexOutOfRange(position);

	for (int i = position; i < count; i++)
	{
		elements[i] = elements[i + 1];
	}
	count--;
}

template <typename T>
void Deque<T>::push_back(T value)
{
	if (count + 1 <= maxSize)
	{
		elements[count] = value;
		count++;
	}
}

template <typename T>
void Deque<T>::push_front(T value)
{
	if (count + 1 <= maxSize)
	{
		for (int i = count; i >= 1; i--)
		{
			elements[i] = elements[i - 1];
		}
		elements[0] = value;
		count++;
	}
}

template <typename T>
T Deque<T>::pop_back()
{
	if (count > 0)
	{
		T element = elements[count - 1];
		count--;
		return element;
	}
}

template <typename T>
T Deque<T>::pop_front()
{
	if (count > 0)
	{
		T element = elements[0];

		for (int i = 0; i < count; i++)
		{
			elements[i] = elements[i + 1];
		}

		count--;

		return element;
	}
}

template<typename T>
void Deque<T>::CheckIndexOutOfRange(int index)
{
	if (index >= count || 
		index < 0)
	{
		throw "IndexOutOfRangeException";
	}
}

