#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    Bureaucrat Alice("Alice", 1);
    Bureaucrat Bob("Bob", 10);

    try {
        Form a("A", 0, 0);
        Form b("B", 15, 151);
        Form c("C", 3, 1);
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "Form creation exception occurred: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Form creation exception occurred: " << e.what() << std::endl;
    }
    try {
        Form b("B", 15, 151);
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "Form creation exception occurred: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Form creation exception occurred: " << e.what() << std::endl;
    }
    try {
        Form c("C", 3, 1);
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "Form creation exception occurred: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Form creation exception occurred: " << e.what() << std::endl;
    }
    Form d("D", 4, 2);
    try {
        d.beSigned(Bob);
        d.beSigned(Alice);
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }
    try {
        d.beSigned(Alice);
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }
    d.beSigned(Bob);
    std::cout << d << std::endl;
};