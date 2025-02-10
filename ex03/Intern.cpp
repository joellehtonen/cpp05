#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
};

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
};

Intern::Intern(const Intern& copy) {
	(void)copy;
	std::cout << "Intern copy constructor called" << std::endl;
};

Intern& Intern::operator=(const Intern& copy) {
	std::cout << "Intern copy assigment constructor called" << std::endl;
	(void)copy;
	return *this;
};

AForm* Intern::makeForm(std::string form, std::string target) {
	AForm* (Intern::*formPointers[])(const std::string&) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};
	std::string forms[] = {"PresidentialPardon", "Presidential Pardon", "presidential pardon", "presidential_pardon", "presidentialpardon", \
		"RobotomyRequest", "Robotomy Request", "robotomy request", "robotomy_request", "robotomyrequest", \
		"ShrubberyCreation", "Shrubbery Creation", "shrubbery creation", "shrubbery_creation", "shrubberycreation"};
	for (int i = 0; i < 15; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << form << " for " << target << i << std::endl;
			if (i < 5)
				return (this->*formPointers[0])(target);
			if (i < 10)
				return (this->*formPointers[1])(target);
			if (i < 15)
				return (this->*formPointers[2])(target);
		}
	}
	throw FormDoesntExist();
};

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}
AForm* Intern::createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
};
AForm* Intern::createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
};

const char* Intern::FormDoesntExist::what() const noexcept {
	return "The form does not exist";
};