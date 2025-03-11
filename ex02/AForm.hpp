#pragma once
#include <iostream>
#include <string>

class Bureaucrat;
class AForm
{
    protected:
        const std::string name;
        bool _signed;
        const int signedRequierementGrade;
        const int executionRequierementGrade;
    public:
        virtual ~AForm();
        AForm();
        AForm(std::string const& newName,bool isSigned, int newSignedRequirement, int newExecutaRequierement);
        AForm(AForm const& rhs);
        AForm& operator=(AForm const& rhs);
        std::string getName(void)const;
        bool isSigned(void)const;
        int getGradeToSign(void)const;
        int getGradeToExecute(void)const;
        void beSigned(Bureaucrat const& bob);
        virtual void execute(Bureaucrat const& executor) const;
        virtual void executeAction(Bureaucrat const& executor) const = 0;
    };
std::ostream &operator<<(std::ostream &os, const AForm &AForm);
