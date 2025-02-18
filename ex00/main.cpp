#include "Bureaucrat.hpp"

int main(void) {

    std::cout << "\n---TEST #1: CREATING BUREAUCRATS--\n";
    try {
        std::cout << "Creating Alice\n";
        Bureaucrat Alice("Alice", 2);
    }
    catch (std::exception& e) {
        std::cout << "Creation exception occured: " << e.what() << std::endl;
    }
    try {
        std::cout << "Creating Bob\n";
        Bureaucrat Bob("Bob", 200); //will throw exception
    }
    catch (std::exception& e) {
        std::cout << "Creation exception occured: " << e.what() << std::endl;
    }
    try {
        std::cout << "Creating Charlie\n";
        Bureaucrat Charlie("Charlie", 0); //will throw exception
    }
    catch (std::exception& e) {
        std::cout << "Creation exception occured: " << e.what() << std::endl;
    }

    std::cout << "\n---TEST #2: INCREMENTING AND DECREMENTING--\n";
    Bureaucrat Charlie("Charlie", 2);
    Bureaucrat David("David", 1);
    try {
        Charlie.incrementGrade();
        David.incrementGrade(); //will throw exception
    }
    catch (std::exception& e) {
        std::cout << "Incrementing exception occured: " << e.what() << std::endl;
    }
    try {
        for (int i = 0; i < 10; i++)
            Charlie.decrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Decrementing exception occured: " << e.what() << std::endl;
    }

    std::cout << "\n---TEST #3: << OPERATOR---\n"; 
    std::cout << Charlie << std::endl;
    std::cout << David << std::endl;

    std::cout << "\nDECONSTRUCTORS\n";
};