#pragma once
#include <iostream>
#include "AForm.hpp"
#include "FormValidator.hpp"
#include "FormException.hpp"

class  PresidentialPardonAForm : public AForm
{
    public:
        ~PresidentialPardonAForm();
        PresidentialPardonAForm(PresidentialPardonAForm const& rhs);
        PresidentialPardonAForm & operator=(PresidentialPardonAForm const& obj);
        PresidentialPardonAForm(std::string const& newName, bool newIsSigned, int newSignedGrade, int newExecutionGrade);
        PresidentialPardonAForm(std::string const & nameAForm);
        void execute(Bureaucrat const & executor)const  ;
        void executeAction(Bureaucrat const& executor) const ;
};