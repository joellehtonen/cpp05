#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
    std::cout << "CONSTRUCTORS\n";
    Intern intern;
    AForm *form;
    Bureaucrat Alice("Alice", 1);

    std::cout << "\n---VALID ACTION---\n";
    try {
        form = intern.makeForm("robotomy request", "The President");
    }
    catch (std::exception& e) {
        std::cout << "Error." << e.what() << std::endl;
    }

    Alice.signForm(*form);
    Alice.executeForm(*form);

    std::cout << "\n---INVALID ACTION---\n";
    try {
        form = intern.makeForm("robot shrubbery", "The President");
    }
    catch (std::exception& e) {
        std::cout << "Error. " << e.what() << std::endl;
    }

    std::cout << "\nDESTRUCTORS\n";
    delete form;
};