#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat 
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        const std::string&  getName();
        const int&          getGrade();
        void                incrementGrade();
        void                decrementGrade();
        void                signForm(Form& form);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
        class GradeTooLowException : public std::exception {
           public:
                virtual const char* what() const noexcept override;
        };
};

std::ostream& operator<<(std::ostream& ostream, Bureaucrat& bureaucrat);
