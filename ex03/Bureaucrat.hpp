#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

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

        const std::string&  getName() const;
        const int&          getGrade() const;
        void                incrementGrade();
        void                decrementGrade();

        void                signForm(AForm& form);
        void                executeForm(const AForm& form);

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
