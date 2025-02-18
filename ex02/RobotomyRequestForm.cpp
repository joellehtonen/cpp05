#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Unknown") {
	std::cout << "A generic RobotomyRequestForm is typed out." << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const std::string& paramTarget) : AForm("RobotomyRequestForm", 72, 45), _target(paramTarget) {
	std::cout << "A RobotomyRequestForm is typed out." << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is copied." << std::endl;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	std::cout << "RobotomyRequestForm is assigned to be copied." << std::endl;
	return *this;
};

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "A RobotomyRequestForm is shredded in the shredder." << std::endl;
};

void RobotomyRequestForm::beExecuted() const
{
	std::cout << "\n*DRILLING NOISES*\n";
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully! Congratulations!\n\n";
	else
		std::cout << "Robotomy unfortunately failed. Our condolences.\n\n";
};

const std::string& RobotomyRequestForm::getTarget()
{
	return this->_target;
};
