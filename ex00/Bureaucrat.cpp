#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "BureaucratException.hpp"
#include "BureaucratValidator.hpp"


Bureaucrat::Bureaucrat():_name("Default"), _grade(150){
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

void Bureaucrat::incrementGrade()
{
   try
    { 
        BureaucratValidator::validatesup(this->_grade);
        this->_grade = this ->_grade -1;
    }
    catch  (const GradeMax& e)
    {
        throw;
    }
}
void Bureaucrat::decrementGrade()
{
    try
    {
        BureaucratValidator::validateinf(this->_grade); 
        this->_grade = this->_grade +1;
    }
    catch(const GradeMin& e){
        throw;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
