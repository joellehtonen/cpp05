#pragma once
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat 
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);

        const std::string&  getName();
        const int&          getGrade();
        void                incrementGrade();
        void                decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
        class GradeTooLowException : public std::exception {
           public:
                virtual const char* what() const noexcept override;
        };
}

std::ostream& operator<<(std::ostream& ostream, Bureaucrat const& bureaucrat);
