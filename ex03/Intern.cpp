#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
};

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
};

Intern::Intern(const Intern& copy) : Intern(copy) {
	std::cout << "Intern copy constructor called" << std::endl;
};

Intern& Intern::operator=(const Intern& copy) {
	std::cout << "Intern copy assigment constructor called" << std::endl;
	return *this;
};

AForm* Intern::makeForm(std::string form, std::string target) {
	AForm* (Intern::*formPointers[])(std::string) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};
	std::string forms[] = {"PresidentialPardon", "Presidential Pardon", "presidential pardon", "presidential_pardon", \
		"RobotomyRequest", "Robotomy Request", "robotomy request", "robotomy_request",\
		"ShrubberyCreation", "Shrubbery Creation", "shrubbery creation", "shrubbery_creation"};
	for (int i = 0; i < 12; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << form << " for " << target << std::endl;
			if (i < 4)
				return (this->*formPointers[0])(target);
			if (i < 8)
				return (this->*formPointers[1])(target);
			if (i < 12)
				return (this->*formPointers[2])(target);
		}
	}
	throw FormDoesntExist();
};

AForm* Intern::createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}
AForm* Intern::createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
};
AForm* Intern::createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
};

const char* Intern::FormDoesntExist::what() const noexcept {
	return "The form does not exist";
};