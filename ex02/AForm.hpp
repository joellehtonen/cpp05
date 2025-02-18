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

		const std::string&	getName() const;
		const bool&			getSignature() const;
		const int&			getMinGradeToSign() const;
		const int&			getMinGradeToExecute() const;
		
		void				beSigned(Bureaucrat& signer);
		void				execute(const Bureaucrat& executor) const;
		virtual void		beExecuted() const = 0;



	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};
	class FormAlreadySigned : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};
	class FormNotSigned : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& ostream, AForm& form);