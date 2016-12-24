#include <limits>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

template<typename T>
class sorter
{
public:
	bool operator()(const T& elemen1, const T& elemen2) const
	{
		return elemen1 < elemen2;
	}
};

template<typename T>
class stringSorter
{
public:
	bool operator()(const T& elemen1, const T& elemen2) const
	{
		return strlen(elemen1) < strlen(elemen2);
	}
};

class getMinInt
{
public:
	int value = INT_MAX;

	void operator()(const int& elemen)
	{
		if (elemen < value)
		{
			value = elemen;
		}
	}
};