#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		AForm* createPresidentialPardonForm(std::string target);
		AForm* createRobotomyRequestForm(std::string target);
		AForm* createShrubberyCreationForm(std::string target);

	public: 
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		~Intern();

		AForm*	makeForm(std::string form, std::string target);

		class FormDoesntExist: public std::exception {
			virtual const char* what() const noexcept override;
		};
}; 