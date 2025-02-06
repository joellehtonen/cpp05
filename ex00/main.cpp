#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat Alice("Alice", 2);
        Bureaucrat Bob("Bob", 200); //will throw exception
        // Bureaucrat Charlie("Charlie", 0; //will throw exception
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Creation exception occured: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Creation exception occured: " << e.what() << std::endl;
    }
    Bureaucrat Charlie("Charlie", 2);
    Bureaucrat David("David", 1);
    try {
        Charlie.incrementGrade();
        David.incrementGrade(); //will throw exception
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Incrementing exception occured: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Incrementing exception occured: " << e.what() << std::endl;
    }
    try {
        for (int i = 0; i < 10; i++)
            Charlie.decrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Decrementing exception occured: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Decrementing exception occured: " << e.what() << std::endl;
    }
    std::cout << "Here is " << Charlie << " and " << David << std::endl;
};