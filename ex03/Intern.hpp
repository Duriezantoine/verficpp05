#pragma once 
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern
{
    public:
        AForm* makeForm(std::string const& nameAForm, std::string const&  target);
    };