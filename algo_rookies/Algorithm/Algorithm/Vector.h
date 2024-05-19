#pragma once
template <typename T>
class Vector
{
public:
	Vector();
	~Vector();

	void push_back(T val);
	void reserve(int capacity);
	void clear();

	T& operator[](const int pos) { return _data[pos];  }
	int size() { return _size; }
	int capacity() { return _capacity; }
private:
	T* _data = nullptr;
	int _size = 0;
	int _capacity = 0;
};

template <typename T>
void Vector<T>::clear()
{
	if (_data)
	{
		delete[] _data;
		_data = new T[_capacity];
	}
	_size = 0;
}

template <typename T>
void Vector<T>::reserve(int capacity)
{
	if (_capacity >= capacity) return;

	_capacity = capacity;

	T* newData = new T[_capacity];

	for (int i = 0; i < _size; i++)
	{
		newData[i] = _data[i];
	}

	if (_data) delete[] _data;

	_data = newData;

	return;
}

template <typename T>
void Vector<T>::push_back(T value)
{
	if (_size == _capacity)
	{
		int newCapacity = static_cast<int>(_capacity * 1.5);
		if (newCapacity == _capacity) newCapacity++;

		reserve(newCapacity);
	}

	// 데이터 저장
	_data[_size] = value;

	// 데이터 개수 증가
	_size++;
}

template <typename T>
Vector<T>::~Vector()
{
	if (_data) delete[] _data;
}

template <typename T>
Vector<T>::Vector()
{
}
