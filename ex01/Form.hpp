#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp" 

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool 				_signature;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;
	public:
		Form();
		~Form();
		Form(const Form& copy); 
		Form& operator=(const Form& copy);
		Form(std::string paramName, int gradeToSign, int gradeToExecute);

		const std::string&	getName();
		const bool&			getSignature();
		const int&			getMinGradeToSign();
		const int&			getMinGradeToExecute();
		
		void				beSigned(Bureaucrat& signer);


	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& ostream, Form& form);