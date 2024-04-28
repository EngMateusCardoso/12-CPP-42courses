#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array() : _array(NULL), _size(0) {};
		Array(unsigned int n) : _array(new T[n]), _size(n) {};
		Array(Array const &copy) {
			this->_array = new T[copy._size];
			for (unsigned int i = 0; i < copy._size; i++)
				this->_array[i] = copy._array[i];
			this->_size = copy._size;
		}
		Array &operator=(Array const &array) {
			if (this != &array) {
				if (this->_array)
					delete [] this->_array;
				this->_array = new T[array._size];
				for (unsigned int i = 0; i < array._size; i++)
					this->_array[i] = array._array[i];
				this->_size = array._size;
			}
			return (*this);
		};
		~Array() { delete [] this->_array; };

		T &operator[](unsigned int index) const {
			if (index >= this->_size)
				throw OutOfBoundsException();
			return (this->_array[index]);
		};
		unsigned int size() const { return (this->_size); };

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw() 
				{ return ("Error: Index out of bounds"); };
		};
};

#endif
