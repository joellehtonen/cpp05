#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm  {
	private:
		std::string	_target;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

		const std::string&	getTarget();
		virtual void		beExecuted() const override;
};