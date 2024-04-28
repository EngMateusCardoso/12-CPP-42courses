#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data;

class Serializer {
	private:
		Serializer();
		Serializer(Serializer const &copy);
		~Serializer();
		Serializer &operator=(Serializer const &rhs);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
