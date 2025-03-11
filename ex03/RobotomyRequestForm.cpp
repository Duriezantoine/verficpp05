#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "FormValidator.hpp"
#include "FormException.hpp"
#include <cstdlib>  
#include <ctime>   

RobotomyRequestAForm::~RobotomyRequestAForm()
{
    std::cout << "Destuct to class RobotomyRequestAForm" << std::endl;
}
RobotomyRequestAForm::RobotomyRequestAForm(RobotomyRequestAForm const& rhs):AForm(rhs)
{
    *this = rhs;
}
RobotomyRequestAForm const & RobotomyRequestAForm::operator=(RobotomyRequestAForm const& obj)
{
    if(this != &obj)
    {
        AForm::operator=(obj);
    }   
    return(*this);
}
RobotomyRequestAForm::RobotomyRequestAForm(std::string const& newName, bool newIsSigned, int newSignedGrade, int newExecutionGrade):AForm(const_cast<std::string&>(newName), newIsSigned, newSignedGrade, newExecutionGrade)
{
    try{
        AFormValidator::validateAAFormRobotomyRequestAForm(newSignedGrade, newExecutionGrade);
    }
    catch (const GradeTooNoCorrespondSignedRequierementsGradeAAFormRobotomy& e)
    {
            throw; 
    }
    catch (const GradeTooNoCorrespondExeRequierementsGradeAAFormRobotomy& e)
    {
            throw; 
        }

}
RobotomyRequestAForm::RobotomyRequestAForm(std::string  const & nameAForm):AForm(nameAForm,false, 72, 45)
{

}
void RobotomyRequestAForm::execute(Bureaucrat const& executor) const
{
    AForm::execute(executor);

}
void RobotomyRequestAForm::executeAction(Bureaucrat const&) const
{
    std::cout << "* DRILLING NOISES *" << std::endl;
    if (rand() % 2 == 0) {
        std::cout << this->getName() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << this->getName() << " failed." << std::endl;
    }
}
