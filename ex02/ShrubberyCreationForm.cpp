#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Unknown") {
	std::cout << "A generic ShrubberyCreationForm is transcribed." << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& paramTarget) : AForm("ShrubberyCreationForm", 145, 137), _target(paramTarget) {
	std::cout << "A ShrubberyCreationForm is transcribed." << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " is copied." << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	std::cout << "ShrubberyCreationForm is assigned to be copied." << std::endl;
	return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "A ShrubberyCreationForm is cut to pieces by the secretary." << std::endl;
};

void ShrubberyCreationForm::executeForm(Bureaucrat& executor)
{
	if (this->getMinGradeToExecute() >= executor.getGrade())
	{
		std::cout << "Bureaucrat " << executor.getName() << " has executed the form " << this->getName() << std::endl;
		std::ofstream shrubbery(this->_target + "_shrubbery");
		if (shrubbery.is_open())
		{
			shrubbery << "        *         " << std::endl;
			shrubbery << "       ***        " << std::endl;
			shrubbery << "      *o*o*       " << std::endl;
			shrubbery << "     *******      " << std::endl;
			shrubbery << "    **o***o**     " << std::endl;
			shrubbery << "   ***********    " << std::endl;
			shrubbery << "  *o*********o*   " << std::endl;
			shrubbery << " ***************  " << std::endl;
			shrubbery << "**********o****** " << std::endl;
			shrubbery << "       |||        " << std::endl;
			shrubbery << "       |||        " << std::endl;
			shrubbery << "     =======      " << std::endl;
			shrubbery.close();
		}
		else
			std::cout << "Unable to create a tree...\n";
	}
	else
	{
		std::cout << "Bureaucrat " << executor.getName() << " (grade: " << executor.getGrade() << ") cannot execute the form " << this->getName() << " as it requires the grade of " << this->getMinGradeToExecute() << std::endl;
		throw ShrubberyCreationForm::GradeTooLowException();
	}
};

const std::string& ShrubberyCreationForm::getTarget()
{
	return this->_target;
};
