#include "AForm.hpp"
#include "FormValidator.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonAForm::~PresidentialPardonAForm()
{
    std::cout << "Destuct to class PresidentialPardonAForm" << std::endl;
}
PresidentialPardonAForm::PresidentialPardonAForm(PresidentialPardonAForm const& rhs):AForm(rhs)
{
    *this = rhs;
}
PresidentialPardonAForm & PresidentialPardonAForm::operator=(PresidentialPardonAForm const& obj)
{
    if(this != &obj)
    {
        AForm::operator=(obj);
    }   
    return(*this);
}
PresidentialPardonAForm::PresidentialPardonAForm(std::string const& newName, bool newIsSigned, int newSignedGrade, int newExecutionGrade)
: AForm(const_cast<std::string&>(newName), newIsSigned, newSignedGrade, newExecutionGrade)
{
try {
    AFormValidator::validateAAFormPresidentialPardonAForm(newSignedGrade, newExecutionGrade);
}
catch (...) {
    throw;
}
}
PresidentialPardonAForm::PresidentialPardonAForm(std::string const& nameAForm) : AForm(nameAForm, false, 25, 5)
{
}
void PresidentialPardonAForm::execute(Bureaucrat const& executor) const
{
    AForm::execute(executor);
}
void PresidentialPardonAForm::executeAction(Bureaucrat const& ) const
{

    std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}