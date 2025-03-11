#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "FormException.hpp"
class AFormValidator
{
    public:
    static void validateAForm(AForm const& rhs)
    {
        if(rhs.getGradeToSign() < 0)  
            throw GradeTooHighExceptionSignedRequierementsGrade();
        if(rhs.getGradeToSign() > 150)
            throw GradeToolowExceptionSignedRequierementsGrade();
        if(rhs.getGradeToExecute() < 0) 
            throw GradeTooHighExceptionExecutedRequierementGrade();
        if(rhs.getGradeToExecute() > 150)
            throw GradeTooLowExceptionRequierementGrade();
    }
        static void validateAAFormShrubberyCreationAForm(int signeAForm, int executeAForm)
        {
            if(signeAForm > 146 ||  signeAForm < 0)
                throw  GradeTooNoCorrespondSignedRequierementsGradeAAFormShrubber();
            if(executeAForm > 137 || signeAForm < 0)
                throw GradeTooNoCorrespondExeRequierementsGradeAAFormShrubber();
        }
        static void validateAAFormRobotomyRequestAForm(int signeAForm, int executeAForm)
        {
            if(signeAForm > 146 ||  signeAForm < 0)
                throw  GradeTooNoCorrespondSignedRequierementsGradeAAFormRobotomy();
            if(executeAForm > 137 || signeAForm < 0)
                throw GradeTooNoCorrespondExeRequierementsGradeAAFormRobotomy();
        }
        static void validateAAFormPresidentialPardonAForm(int signeAForm, int executeAForm)
        {
            if(signeAForm > 146 ||  signeAForm < 0)
                throw  GradeTooNoCorrespondSignedRequierementsGradeAAFormPresidentialPardon();
            if(executeAForm > 137 || signeAForm < 0)
                throw GradeTooNoCorrespondExeRequierementsGradeAAFormPresidentialPardon();
        }
};