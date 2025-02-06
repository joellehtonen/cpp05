#pragma once
#include <string>
#include <iostream>

class Form
{
	private:
		const std::string	_name;
		bool 				_signature;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		Form();
		~Form();
		Form(const Form& copy); 
		Form& operator=(const Form& copy);

	class GradeTooHighException{
		public:
			
	}
};