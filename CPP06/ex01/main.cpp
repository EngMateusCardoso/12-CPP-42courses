#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {

	std::cout << "------------------- REINTERPRET CAST TEST --------------------" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;

    Data *data = new Data("I'm a data", 42);
    std::cout << "Data is in pointer: \t\t" << data << std::endl;
    std::cout << "Private string is: \t\t" << data->getDataString() << std::endl;
    std::cout << "Private number is: \t\t" << data->getDataNumber() << std::endl;

    uintptr_t newData = Serializer::serialize(data);
    std::cout << "Raw pointer is: \t\t" << newData << std::endl;

    Data *ptr = Serializer::deserialize(newData);
    std::cout << "Data is in pointer: \t\t" << ptr << std::endl;
    std::cout << "Private string is: \t\t" << ptr->getDataString() << std::endl;
    std::cout << "Private number is: \t\t" << ptr->getDataNumber() << std::endl;
    delete data;

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "----------------------- END OF TEST --------------------------" << std::endl;

    return (0);
}
