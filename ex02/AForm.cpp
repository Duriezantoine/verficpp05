#include <iostream>
#include <string>
#include "AForm.hpp"
#include "FormValidator.hpp"
#include "FormException.hpp"
#include "Bureaucrat.hpp"

        AForm::~AForm(){}
        AForm::AForm():name("defaut"), _signed(false), signedRequierementGrade(150),executionRequierementGrade(150)
        {}
        AForm::AForm(std::string const& newName,bool newisSigned, int newSignedRequirement, int newExecutaRequierement):name(newName), _signed(newisSigned), signedRequierementGrade(newSignedRequirement),executionRequierementGrade(newExecutaRequierement) 
        {
            AFormValidator::validateAForm(*this);
        }
        AForm::AForm(AForm const& rhs):name(rhs.name), _signed(rhs._signed), signedRequierementGrade(rhs.signedRequierementGrade),executionRequierementGrade(rhs.executionRequierementGrade) 
        {
            *this = rhs;
        }
        AForm& AForm::operator=(AForm const& rhs)
        {
            if(this != &rhs)
            {
                try{

                    AFormValidator::validateAForm(rhs);
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
        std::string AForm::getName(void)const
        {
            return(this->name);
        }
        bool AForm::isSigned(void)const
        {
            return(this->_signed);
        }
        int AForm::getGradeToSign(void)const
        {
            return(this->signedRequierementGrade);
        }
        int AForm::getGradeToExecute(void)const
        {
            return(this->executionRequierementGrade);
        }
        void AForm::beSigned(Bureaucrat const& bureaucrat)
        {
            if (bureaucrat.getGrade() <= this->signedRequierementGrade) {
                this->_signed = true;
            } else {
                throw GradeToolowExceptionSignedRequierementsGrade();
            }
        }
        std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
            os << "AForm: " << AForm.getName() << ", ";
            os << "Status: " << (AForm.isSigned() ? "signed" : "not signed") << ", ";
            os << "Grade required to sign: " << AForm.getGradeToSign() << ", ";
            os << "Grade required to execute: " << AForm.getGradeToExecute();
            return os;
        }
        void AForm::execute(Bureaucrat const& executor) const
        {
            if (!this->isSigned())
            {
                throw AFormNotSignedException();
            }
            
            if (executor.getGrade() > this->getGradeToExecute())
            {
                throw GradeTooLowExceptionRequierementGrade();
            }
            
            this->executeAction(executor);
        }
