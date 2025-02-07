#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
        S.beSigned(Alice);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }
    try {
        S.executeForm(Alice);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "Form execution exception occurred: " << e.what() << std::endl;
    }
    std::cout << "\nROBOTOMY\n";
    try {
        R.beSigned(Alice);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }
    try {
        R.executeForm(Alice);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "Form execution exception occurred: " << e.what() << std::endl;
    }
    try {
        R.executeForm(Bob);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "Form execution exception occurred: " << e.what() << std::endl;
    }
    std::cout << "\nPARDON\n";
    try {
        P.beSigned(Bob);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }
    try {
        P.executeForm(Bob);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "Form execution exception occurred: " << e.what() << std::endl;
    }
    try {
        P.executeForm(Charlie);
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "Form execution exception occurred: " << e.what() << std::endl;
    }
    std::cout << "\nDESTRUCTORS:\n";
};