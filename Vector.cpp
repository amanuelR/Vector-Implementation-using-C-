#include <iostream>
#include "Vector.h"
#include "Container.h"
namespace CS52
{
    // default constructor
	Vector::Vector(){}
	// overloaded constructor
	Vector::Vector(int sz, int init_val)
	{
        this->_capacity = sz;
        this->_size = sz;
        _data = new int[_capacity];
        for(int i = 0; i < _size; i++)
        {
            this->_data[i] = init_val;
        }
	}
	// copy constructor
	Vector::Vector(const Vector& v)
	{
	    this->_capacity = v._capacity;
	    this->_size = v._size;
        this->_data = v._data;
	}
	// Destructor
	Vector::~Vector()
	{
        _size = 0;
		_capacity = 0;
		delete[] _data;
	}
	// Resize Vector
	void Vector::resize(int new_size, int init_val)
	{
	    if (_capacity < new_size)
			_capacity = new_size;

		if (_size > new_size)
			_size = new_size;

		int *temp = new int[new_size];
		for (int i = 0; i < _size; i++)
			temp[i] = _data[i];
		delete[] _data;
		_data = temp;

		for (; _size < new_size; _size++)
			_data[_size] = init_val;
	}
	// Increase capacity of Vector
	void Vector::reserve(int cap)
	{
	    if (Vector::_capacity >= cap);
		else
			_capacity = cap;
	}
	// Returns a reference to the element at location i in Vector .
	int& Vector::at(int i) const throw (std::string)
	{
	   std::string msg = "Index " + std::to_string(i) + " out of bound";
		if (i < _size)
			return _data[i];
		else
			throw msg;
	}
	// Returns the allocated storage for the Vector .
	int Vector::capacity() const
	{
	    return _capacity;
	}
	// Erases the elements of the Vector but does not change capacity .
	void Vector::clear()
	{
		int v_size = _size;
		for (int i = 0; i < v_size; i++)
			_size--;
	}
    // Returns pointer to the first element in the Vector .
	int* Vector::data() const
	{
		int *first_element = &_data[0];
		return first_element;
	}
	// If Vector is empty return true , else false .
	bool Vector::empty() const
	{
		if (_size == 0)
			return true;
		return false;
	}
	// Deletes the element at the end of the vector .
	void Vector::pop_back()
	{
		_size = _size - 1;
	}
	// Add an element to the end of the vector .
    void Vector::push_back(int element)
    {

        if (_size >= _capacity)
        {
            if (_capacity == 0)
                _capacity = 1;
            else
                _capacity = _size * 2;

            int *temp = new int[_capacity];
            for (int i = 0; i < _size; i++)
                temp[i] = _data[i];
            delete[] _data;
            _data = temp;
        }
        _data[_size] = element;
        _size++;
    }
	// Returns a reference to the first element in the Vector .
	int& Vector::front() const throw (std::out_of_range)
	{
		if (this->_size == 0)
			throw std::out_of_range("Error to Access 0 Element Vector");
		else
			return _data[0];
	} // std :: out_of_range
// Returns a reference to the last element in Vector v.
	int& Vector::back() const throw (std::out_of_range)
	{

		return _data[_size - 1];
	}
	// Returns the number of elements in the vector .
	int Vector::size() const
	{
		return _size;
	}
	// Search for a key in Vector , return index of key or -1 if not found
	int Vector::find(int key)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_data[i] == key)
				return i;
		}

		return -1;
	}
	// Overloaded operators
    int& Vector::operator [] (int i)
    {
        return _data[i];
    }
    Vector& Vector::operator =(const Vector& v)
    {
        if(this != &v)
        {
            this->_capacity = v._capacity;
            this->_size = v._size;
            delete[] _data;
            _data = new int[_size];
            this->_data = v._data;
        }
        return *this;
    }
    // Overloaded stream insertion operator
	std::ostream& operator <<(std::ostream & output, Vector & v)
	{
        for(int i=0;i<v._size;i++)
            output << v._data[i]<<" ";
	    return output;
	}
    std::string  Vector::type() const{
        return "CS53::Vector";
    }
}
