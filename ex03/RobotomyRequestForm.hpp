#pragma once
#include <iostream>
#include "AForm.hpp"
#include "FormValidator.hpp"
#include "FormException.hpp"

class  RobotomyRequestAForm : public AForm
{
    public:
        ~RobotomyRequestAForm();
        RobotomyRequestAForm(RobotomyRequestAForm const& rhs);
        RobotomyRequestAForm const& operator=(RobotomyRequestAForm const& obj);
        RobotomyRequestAForm(std::string const& newName, bool newIsSigned, int newSignedGrade, int newExecutionGrade);
        RobotomyRequestAForm(std::string const& nameAForm);
        void execute(Bureaucrat const & executor)const;
        void executeAction(Bureaucrat const & executor)const ;

};