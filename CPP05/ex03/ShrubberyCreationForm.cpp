#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery creation", 145, 137) {
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : Form(copy) {
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &op) {
	if (this != &op) {
		this->_target = op._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!Form::getSigned())
		throw Form::FormNotSignedException();
	if (executor.getGrade() > Form::getGradeExec())
		throw Form::GradeTooLowException();
	std::ofstream file;
	std::string filename = this->_target + "_shrubbery";
	file.open(filename.c_str());
	if (file.is_open()) {
		file << "              _{\\ _{\\{\\/}/}/}__                           _{\\ _{\\{\\/}/}/}__" << std::endl;
		file << "             {/{/\\}{/{/\\}(\\}{/\\} _                       {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
		file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _                  {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
		file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}              {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
		file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}              {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
		file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}             _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
		file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}           {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
		file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}           _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
		file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}         {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
		file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}         {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
		file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)           {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
		file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}          {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
		file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}           {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
		file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}             {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
		file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)               (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
		file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}                     {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
		file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}                        {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
		file << "              {){/ {\\/}{\\/} \\}\\}                          {){/ {\\/}{\\/} \\}\\}" << std::endl;
		file << "              (_)  \\.-'.-/                                 (_)  \\.-'.-/" << std::endl;
		file << "          __...--- |'-.-'| --...__     Shrubberies     __...--- |'-.-'| --...__" << std::endl;
		file << "   _...--'   .-'   |'-.-'|  ' -.  ''--.._________...--'   .-'   |'-.-'|  ' -.  ''--..__" << std::endl;
		file << " -'    ' .  . '    |.'-._| '  . .  '   ''._- _-'    ' .  . '    |.'-._| '  . .  '   ''._" << std::endl;
		file << " .  '-  '    .--'  | '-.'|    .  '  . ' . . ' -' '-  '    .--'  | '-.'|    .  '     . '" << std::endl;
		file << "          ' ..     |'-_.-|                             ' ..     |'-_.-|               -" << std::endl;
		file << "  .  '  .       _.-|-._ -|-._  .  '  .    '  . .  '  .       _.-|-._ -|-._  .  '  .   '" << std::endl;
		file << "              .'   |'- .-|   '.                            .'   |'- .-|   '." << std::endl;
		file << "  ..-'   ' .  '.   `-._.--   .'  '  - .        ..-'   ' .  '.   `-._.--   .'  '  - ." << std::endl;
		file << "   .-' '        '-._______.-'     '  .   . .    .-' '        '-._______.-'     '  ." << std::endl;
		file << "    .       .    .   .    ' '-.                     .       .    .   .    ' '-. '" << std::endl;
		file.close();
		std::cout << filename << " created successfully!" << std::endl;
	} else {
		std::cout << "Error creating file '" <<  filename << "'" << std::endl;
	}
}
