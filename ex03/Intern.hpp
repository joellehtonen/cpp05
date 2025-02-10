#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		AForm* createPresidentialPardonForm(const std::string& target);
		AForm* createRobotomyRequestForm(const std::string& target);
		AForm* createShrubberyCreationForm(const std::string& target);

	public: 
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);

		AForm*	makeForm(std::string form, std::string target);

		class FormDoesntExist: public std::exception {
			virtual const char* what() const noexcept override;
		};
}; 