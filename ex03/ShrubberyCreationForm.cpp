#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "FormValidator.hpp"
#include "FormException.hpp"
#include <fstream>

ShrubberyCreationAForm::~ShrubberyCreationAForm()
{
    std::cout << "Destuct to class ShrubberyCreationAForm" << std::endl;
}
ShrubberyCreationAForm::ShrubberyCreationAForm(ShrubberyCreationAForm const& rhs):AForm(rhs)
{
    *this = rhs;
}
ShrubberyCreationAForm const& ShrubberyCreationAForm::operator=(ShrubberyCreationAForm const& obj)
{
    if(this != &obj)
    {
        AForm::operator=(obj);
    }   
    return(*this);
}
ShrubberyCreationAForm::ShrubberyCreationAForm(std::string const& newName, bool newIsSigned, int newSignedGrade, int newExecutionGrade):AForm(const_cast<std::string&>(newName), newIsSigned, newSignedGrade, newExecutionGrade)
{
    try{
        AFormValidator::validateAAFormShrubberyCreationAForm(newSignedGrade, newExecutionGrade);
    }
    catch (const GradeTooNoCorrespondSignedRequierementsGradeAAFormShrubber& e)
    {
            throw; 
    }
    catch (const GradeTooNoCorrespondExeRequierementsGradeAAFormShrubber& e)
    {
            throw; 
        }

}
ShrubberyCreationAForm::ShrubberyCreationAForm(std::string const& nameAForm):AForm(nameAForm, false, 145,137)
{

}
void ShrubberyCreationAForm::execute(Bureaucrat const& executor) const
{
    AForm::execute(executor);
}
void ShrubberyCreationAForm::executeAction(Bureaucrat const& ) const
{
    std::string filename = this->getName() + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        file << "    *    " << std::endl;
        file << "   ***   " << std::endl;
        file << "  *****  " << std::endl;
        file << " ******* " << std::endl;
        file << "*********" << std::endl;
        file << "    |    " << std::endl;
        file.close();
        std::cout << "A shrubbery has been created at " << filename << std::endl;
    } else {
        std::cout << "Error: Could not create shrubbery file." << std::endl;
    }
}