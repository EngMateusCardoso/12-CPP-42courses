#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer const &copy) {
	*this = copy;
}

Serializer &Serializer::operator=(Serializer const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
	std::cout << "Serializing data..." << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
	std::cout << "Deserializing data..." << std::endl;
	return (reinterpret_cast<Data *>(raw));
}
