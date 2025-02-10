#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
    std::cout << "\nCONSTRUCTORS\n";
    Intern intern;
    AForm *form;
    Bureaucrat Alice("Alice", 1);

    std::cout << "\nVALID ACTION\n";
    try {
        form = intern.makeForm("robotomy_request", "The President");
    }
    catch (Intern::FormDoesntExist& e) {
        std::cout << "Error." << e.what() << std::endl;
    }

    Alice.signForm(*form);
    Alice.executeForm(*form);

    std::cout << "\nINVALID ACTION\n";
    try {
        form = intern.makeForm("robot_shrubbery", "The President");
    }
    catch (Intern::FormDoesntExist& e) {
        std::cout << "Error. " << e.what() << std::endl;
    }

    std::cout << "\nDESTRUCTORS\n";
};