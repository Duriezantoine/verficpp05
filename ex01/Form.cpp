#include <iostream>
#include <string>
#include "Form.hpp"
#include "FormValidator.hpp"
#include "FromException.hpp"
#include "Bureaucrat.hpp"

Form::~Form(){}
Form::Form():name("defaut"), _signed(false), signedRequierementGrade(150),executionRequierementGrade(150)
{}
Form::Form(std::string& newName,bool newisSigned, int newSignedRequirement, int newExecutaRequierement):name(newName), _signed(newisSigned), signedRequierementGrade(newSignedRequirement),executionRequierementGrade(newExecutaRequierement) 
{
    FormValidator::validateAForm(*this);
}
Form::Form(Form const& rhs):name(rhs.name), _signed(rhs._signed), signedRequierementGrade(rhs.signedRequierementGrade),executionRequierementGrade(rhs.executionRequierementGrade) 
{
    *this = rhs;
}
Form& Form::operator=(Form const& rhs)
{
    if(this != &rhs)
    {
        try{

            FormValidator::validateAForm(rhs);//Mise en place pour le formulaire normal 

        }
        catch (const GradeTooHighExceptionSignedRequierementsGrade& e)
        {
            std::cout << "Test1" << std::endl;
                throw;  
        }
        catch (const GradeToolowExceptionSignedRequierementsGrade& e)
        {
            std::cout << "Test2" << std::endl;
                throw;               
        }
        catch (const GradeTooHighExceptionExecutedRequierementGrade& e)
        {
            std::cout << "Test3" << std::endl;
                throw; 
        }
        catch (const GradeTooLowExceptionRequierementGrade& e)
        {
            std::cout << "Test4" << std::endl;
                throw; 
        }
    }
    return(*this);
}

std::string Form::getName(void)const
{
    std::cout <<this->name<< std::endl;
    return(this->name);
}
bool Form::isSigned(void)const
{
    return(this->_signed);
}
int Form::getGradeToSign(void)const
{
    return(this->signedRequierementGrade);
}
int Form::getGradeToExecute(void)const
{
    return(this->executionRequierementGrade);
}

void Form::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->signedRequierementGrade) {
        this->_signed = true;
    } else {
        throw GradeToolowExceptionSignedRequierementsGrade();
    }
}
std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form.getName() << ", ";
    os << "Status: " << (form.isSigned() ? "signed" : "not signed") << ", ";
    os << "Grade required to sign: " << form.getGradeToSign() << ", ";
    os << "Grade required to execute: " << form.getGradeToExecute();
    return os;
}