#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Unknown") {
	std::cout << "A generic PresidentialPardonForm is written." << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const std::string& paramTarget) : AForm("PresidentialPardonForm", 25, 5), _target(paramTarget) {
	std::cout << "A PresidentialPardonForm is written." << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	std::cout << "PresidentialPardonForm " << this->getName() << " is copied." << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	std::cout << "PresidentialPardonForm is assigned to be copied." << std::endl;
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "A PresidentialPardonForm is burned in the fireplace." << std::endl;
};

void PresidentialPardonForm::executeForm(Bureaucrat& executor)
{
	if (this->getMinGradeToExecute() >= executor.getGrade())
	{
		std::cout << "Bureaucrat " << executor.getName() << " has executed the form " << this->getName() << std::endl;
		std::cout << "\n" << _target << " has been pardoned by Zaphod Beeblebrox!\n" << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << executor.getName() << " (grade: " << executor.getGrade() << ") cannot execute the form " << this->getName() << " as it requires the grade of " << this->getMinGradeToExecute() << std::endl;
		throw PresidentialPardonForm::GradeTooLowException();
	}
};

const std::string& PresidentialPardonForm::getTarget()
{
	return this->_target;
};