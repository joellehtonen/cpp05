#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#define FORM_SIGN_ERROR "ERROR. Form signing exception occurred: "
#define FORM_EXEC_ERROR "ERROR. Form executing exception occurred: "

int main(void) {
    std::cout << "\nCONSTRUCTORS\n";

    Bureaucrat Alice("Alice", 50);
    Bureaucrat Bob("Bob", 10);
    Bureaucrat Charlie("Charlie", 1);
    PresidentialPardonForm P("Mommy");
    RobotomyRequestForm R("Daddy");
    ShrubberyCreationForm S("Home");

    std::cout << "\nSHRUBBERY\n";
    try {
        Alice.executeForm(S);
    }
    catch (AForm::FormNotSigned& e) {
        std::cout << FORM_SIGN_ERROR << e.what() << std::endl;
    }
    try {
        Alice.signForm(S);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << FORM_SIGN_ERROR << e.what() << std::endl;
    }
    try {
        Alice.executeForm(S);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << FORM_EXEC_ERROR << e.what() << std::endl;
    }
    std::cout << "\nROBOTOMY\n";
    try {
        Alice.signForm(R);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << FORM_SIGN_ERROR << e.what() << std::endl;
    }
    try {
        Alice.executeForm(R);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << FORM_EXEC_ERROR << e.what() << std::endl;
    }
    try {
        Bob.executeForm(R);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << FORM_EXEC_ERROR << e.what() << std::endl;
    }
    std::cout << "\nPARDON\n";
    try {
        Bob.signForm(P);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << FORM_SIGN_ERROR << e.what() << std::endl;
    }
    try {
        Bob.executeForm(P);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << FORM_EXEC_ERROR << e.what() << std::endl;
    }
    try {
        Charlie.executeForm(P);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << FORM_EXEC_ERROR << e.what() << std::endl;
    }
    std::cout << "\nDESTRUCTORS\n";
};