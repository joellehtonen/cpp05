#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    Bureaucrat Alice("Alice", 1);
    Bureaucrat Bob("Bob", 10);

    std::cout << "\n---TEST #1: CREATING FORMS---\n";
    try {
        std::cout << "Creating Form A\n";
        Form a("A", 0, 0);
    }
    catch (std::exception& e) {
        std::cout << "Form creation exception occurred: " << e.what() << std::endl;
    }
    try {
        std::cout << "Creating Form B\n";
        Form b("B", 15, 151);
    }
    catch (std::exception& e) {
        std::cout << "Form creation exception occurred: " << e.what() << std::endl;
    }
    try {
        std::cout << "Creating Form C\n";
        Form c("C", 3, 1);
    }
    catch (std::exception& e) {
        std::cout << "Form creation exception occurred: " << e.what() << std::endl;
    }

    std::cout << "\n---TEST #2: SIGNING FORMS---\n";
    Form d("D", 4, 2);
    try {
        std::cout << "Bob tries to sign\n";
        Bob.signForm(d);
    }
    catch (std::exception& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }
    try {
        std::cout << "Alice tries to sign\n";
        Alice.signForm(d);
    }
    catch (std::exception& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }
    try {
        std::cout << "Alice tries to sign again\n";
        Alice.signForm(d);
    }
    catch (std::exception& e) {
        std::cout << "Form signing exception occurred: " << e.what() << std::endl;
    }

    std::cout << "\n---TEST #3: << OPERATOR---\n"; 
    std::cout << d << std::endl;

    std::cout << "\nDECONSTRUCTORS\n";
};