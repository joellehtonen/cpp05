#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat Alice("Alice", 1);
    Bureaucrat Bob("Bob", 2);
    Alice.incrementGrade();
    Bob.incrementGrade();
    std::cout << Alice << Bob << std::endl;
    
}