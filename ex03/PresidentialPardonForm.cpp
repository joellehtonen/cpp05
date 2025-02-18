#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Unknown") {
	std::cout << "A generic PresidentialPardonForm is written" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const std::string& paramTarget) : AForm("PresidentialPardonForm", 25, 5), _target(paramTarget) {
	std::cout << "PresidentialPardonForm is written" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	std::cout << "PresidentialPardonForm " << this->getName() << " is copied" << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	std::cout << "PresidentialPardonForm is assigned to be copied" << std::endl;
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm is burned in the fireplace" << std::endl;
};

void PresidentialPardonForm::beExecuted() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
};

const std::string& PresidentialPardonForm::getTarget()
{
	return this->_target;
};