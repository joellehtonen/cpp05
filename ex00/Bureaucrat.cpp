#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "Default constructor called." << std::endl;
};
Bureaucrat::Bureaucrat(std::string paramName, int paramGrade) : _name(paramName) {
    try
    {
        if (paramGrade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (paramGrade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->_grade = paramGrade;
    }
};
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called.\n" << std::endl;;
};
Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
    *this = copy;
    std::cout << "Copy constructor called." << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
    {
        //this->_name = copy._name;
        this->_grade = copy._grade;
        std::cout << "Copy assignment constructor called." << std::endl;;
    }
    return *this;
}

const std::string& Bureaucrat::getName() {
    return _name;
}

const int& Bureaucrat::getGrade() {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade >= 1)
        throw GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade <= 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return ("The grade is too high, please use a lower grade.");
};
const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return ("The grade is too low, please use a higher grade.");
};

std::ostream & operator<<(std::ostream& ostream, Bureaucrat& bureaucrat) {
    ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (ostream);
};