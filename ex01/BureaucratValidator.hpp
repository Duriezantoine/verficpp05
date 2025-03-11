#include <iostream>
#include <string>

class BureaucratValidator {
public:
    static void validate(int grade) {
        if (grade > 150)
            throw GradeTooHighException();
        if (grade < 0)
            throw GradeTooLowException();
    }
};