#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp" 

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool 				_signature;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;
	public:
		AForm();
		AForm(std::string paramName, int gradeToSign, int gradeToExecute);
		AForm(const AForm& copy); 
		AForm& operator=(const AForm& copy);
		virtual ~AForm();

		const std::string&	getName();
		const bool&			getSignature();
		const int&			getMinGradeToSign();
		const int&			getMinGradeToExecute();
		
		void				beSigned(Bureaucrat& signer);
		virtual void		executeForm(Bureaucrat& executor) = 0;


	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& ostream, AForm& form);