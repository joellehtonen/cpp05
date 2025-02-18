#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "Default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(std::string paramName, int paramGrade) : _name(paramName) {
    if (paramGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (paramGrade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = paramGrade;
    std::cout << "Parametered constructor called for " << _name << ", grade: " << _grade << std::endl;
};

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called for " << _name << std::endl;;
};
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
    std::cout << "Copy constructor called" << std::endl;
};
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
    {
        this->_grade = copy._grade;
        std::cout << "Copy assignment constructor called" << std::endl;;
    }
    return *this;
};

const std::string& Bureaucrat::getName() {
    return _name;
};

const int& Bureaucrat::getGrade() {
    return _grade;
};

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    std::cout << "Incrementing grade of " << this->_name << " from "  << this->_grade;
    this->_grade--;
    std::cout << " to " << this->_grade << std::endl;
};

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    std::cout << "Decrementing grade of " << this->_name << " from " << this->_grade;
    this->_grade++;
    std::cout << " to " << this->_grade << std::endl;
};

void Bureaucrat::signForm(Form& form) {
    if (this->_grade > form.getMinGradeToSign())
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because their grade isn't high enough." << std::endl;
        throw GradeTooLowException();
    }
    else
    {
        std::cout << _name << " signed form " << form.getName() << std::endl;
        form.beSigned(*this);
    }
};

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return ("The grade is too high, please use a lower grade");
};
const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return ("The grade is too low, please use a higher grade");
};

std::ostream& operator<<(std::ostream& ostream, Bureaucrat& bureaucrat) {
    ostream << "Bureaucrat " << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade();
    return (ostream);
};