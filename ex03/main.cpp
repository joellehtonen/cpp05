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

    form = intern.makeForm("robotomyrequest", "The President");
    Alice.signForm(*form);
    Alice.executeForm(*form);

    std::cout << "\nDESTRUCTORS\n";
};