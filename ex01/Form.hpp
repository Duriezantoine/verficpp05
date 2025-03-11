#pragma once
#include <iostream>
#include <string>

class Bureaucrat;
class Form
{
    private:
        const std::string name;
        bool _signed;
        const int signedRequierementGrade;
        const int executionRequierementGrade;
    public:
        virtual ~Form();
        Form();
        Form(std::string& newName,bool isSigned, int newSignedRequirement, int newExecutaRequierement);
        Form(Form const& rhs);
        Form& operator=(Form const& rhs);
        std::string getName(void)const;
        bool isSigned(void)const;
        int getGradeToSign(void)const;
        int getGradeToExecute(void)const;
        void beSigned(Bureaucrat const& bob);

};
std::ostream &operator<<(std::ostream &os, const Form &form);
