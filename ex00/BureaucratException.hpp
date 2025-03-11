// BureaucratException.hpp
#ifndef BUREAUCRAT_EXCEPTION_HPP
#define BUREAUCRAT_EXCEPTION_HPP

#include <exception>

class GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too high";
        }
};

class GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too low";
        }
};
class GradeMax : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Max Grade";
        }
};
class GradeMin : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Min Grade";
        }
};

#endif