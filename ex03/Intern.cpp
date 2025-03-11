#include "Intern.hpp"

AForm* Intern::makeForm(std::string const& nameAForm, std::string const& target)
{
    std::string AFormTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* AForm = NULL;

    for (int i = 0; i < 3; i++)
    {
        if (nameAForm == AFormTypes[i])
        {
            switch (i)
            {
                case 0:
                    AForm = new ShrubberyCreationAForm(target);
                    std::cout << "Intern creates " << nameAForm << std::endl;
                    return AForm;
                case 1:
                    AForm = new RobotomyRequestAForm(target);
                    std::cout << "Intern creates " << nameAForm << std::endl;
                    return AForm;
                case 2:
                    AForm = new PresidentialPardonAForm(target);
                    std::cout << "Intern creates " << nameAForm << std::endl;
                    return AForm;
            }
        }
    }
    std::cout << "Error: AForm type \"" << nameAForm << "\" doesn't exist" << std::endl;
    return NULL;
}