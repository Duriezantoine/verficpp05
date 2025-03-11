#pragma once
#include <iostream>
#include "AForm.hpp"
#include "FormValidator.hpp"
#include "FormException.hpp"

class  ShrubberyCreationAForm : public AForm
{
    public:
        ~ShrubberyCreationAForm();
        ShrubberyCreationAForm(ShrubberyCreationAForm const& rhs);
        ShrubberyCreationAForm const& operator=(ShrubberyCreationAForm const& obj);
        ShrubberyCreationAForm(std::string const& newName, bool newIsSigned, int newSignedGrade, int newExecutionGrade);
        ShrubberyCreationAForm(std::string const& nameAForm);
        void execute(Bureaucrat const & executor)const ;
        void executeAction(Bureaucrat const & executor)const;


};