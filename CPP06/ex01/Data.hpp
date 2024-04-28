#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data {
	private:
		std::string	_dataString;
		int			_dataNumber;

	public:
		Data();
		Data(std::string dataString, int dataNumber);
		Data(Data const &copy);
		~Data();

		Data &operator=(Data const &data);

		std::string	getDataString(void) const;
		int			getDataNumber(void) const;

		void	setDataString(std::string private_data);
		void	setDataNumber(int private_number);
};

#endif
