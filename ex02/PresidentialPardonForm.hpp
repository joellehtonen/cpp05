#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string			_target;
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		const std::string&	getTarget();
		virtual void		beExecuted() const override;
};