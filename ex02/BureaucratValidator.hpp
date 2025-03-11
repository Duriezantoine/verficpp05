#include <iostream>
#include <string>
#include "BureaucratException.hpp"
class BureaucratValidator {
public:
static void validate(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}
};