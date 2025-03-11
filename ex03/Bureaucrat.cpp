#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "BureaucratException.hpp"
#include "BureaucratValidator.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat():_name("Default"), _grade(0){
    std::cout << "Constructor default Bureaucrat" << std::endl;

}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructeur de la class Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade):_name(name),_grade(grade)
{
   try
   {
       BureaucratValidator::validate(grade);
       std::cout << "Bureaucrat " << _name << " created with grade " << _grade << std::endl;
   }
   catch (const GradeTooHighException& e)
   {
       std::cout << "Cannot create Bureaucrat: " << e.what() << std::endl;
       throw; 
   }
   catch (const GradeTooLowException& e)
   {
       std::cout << "Cannot create Bureaucrat: " << e.what() << std::endl;
       throw; 
   }
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs):_name(rhs._name), _grade(rhs._grade)
{
    std::cout << "Constructor copy" << std::endl;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    std::cout << "Constructor operator= " << std::endl;
    if(this != &rhs)
    {
        this->_grade = rhs._grade;
    }
    return *this;
}

int Bureaucrat::getGrade(void)const
{
    return(this->_grade);
}

std::string Bureaucrat::getName(void)const
{
    return(this->_name);
}

void Bureaucrat::setGrade(const int newGrade)
{
    this->_grade = newGrade;
}

void Bureaucrat::signAForm(AForm& AForm)
{
    try {
        AForm.beSigned(*this);
        std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->getName() << " couldn't sign " << AForm.getName() 
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
void Bureaucrat::executeAForm(AForm const & AForm)
{
    try {
        AForm.execute(*this);
        std::cout << this->getName() << " executed " << AForm.getName() << std::endl;
    } catch (std::exception & e) {
        std::cout << this->getName() << " couldn't execute " << AForm.getName() 
                  << " because: " << e.what() << std::endl;
    }
}


