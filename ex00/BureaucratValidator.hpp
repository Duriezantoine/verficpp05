//Class permettant de valider un Bureaucrat
#include <iostream>
#include <string>

class BureaucratValidator {
public:
    static void validate(int grade) {
        if (grade > 150)
            throw GradeTooHighException();
        if (grade < 1)
            throw GradeTooLowException();
    }
    static void validatesup(int grade){
        if(grade == 1){
            throw GradeMax();
        }
    }
    static void validateinf(int grade){
        if(grade == 150){
            throw GradeMin();
        }
    }
};