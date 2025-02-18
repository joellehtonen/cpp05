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
        Alice.executeForm(S);
    } catch (std::exception& e) {
        std::cout << "ERROR. " << e.what() << std::endl;
    }
    try {
        Alice.signForm(S);
        Alice.executeForm(S);
    } catch (std::exception& e) {
        std::cout << "ERROR. " << e.what() << std::endl;
    }



    std::cout << "\nROBOTOMY\n";
    try {
        Alice.signForm(R);
        Alice.executeForm(R);
    } catch (std::exception& e) {
        std::cout << "ERROR. " << e.what() << std::endl;
    }
    try {
        Bob.executeForm(R);
    } catch (std::exception& e) {
        std::cout << "ERROR. " << e.what() << std::endl;
    }



    std::cout << "\nPARDON\n";
    try {
        Bob.signForm(P);
    } catch (std::exception& e) {
        std::cout << "ERROR. " << e.what() << std::endl;
    }
    try {
        Bob.executeForm(P);
    } catch (std::exception& e) {
        std::cout << "ERROR. " << e.what() << std::endl;
    }
    try {
        Charlie.executeForm(P);
    } catch (std::exception& e) {
        std::cout << "ERROR. " << e.what() << std::endl;
    }

    std::cout << "\nDESTRUCTORS\n";
};