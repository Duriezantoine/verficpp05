#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "FormValidator.hpp"
#include "FromException.hpp"
class FormValidator
{
    public:
    static void validateAForm(Form const& rhs)
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
};