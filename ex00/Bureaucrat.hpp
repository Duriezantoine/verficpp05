//Mise en place de la class demander
#include <iostream>
#include <string>
#pragma once

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        virtual~Bureaucrat();
        Bureaucrat();
        Bureaucrat(const Bureaucrat& rhs);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        std::string getName(void)const;
        int         getGrade(void)const;
        void        setName(const std::string& newName);
        void        setGrade(const int newGrade);
        void incrementGrade();
        void decrementGrade();
    };
    std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);