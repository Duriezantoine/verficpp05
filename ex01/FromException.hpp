#ifndef AForm_EXCEPTION_HPP
#define AForm_EXCEPTION_HPP

#include "exception"

class GradeTooHighExceptionSignedRequierementsGrade : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too high";
        }
};
class GradeToolowExceptionSignedRequierementsGrade : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too low";
        }
};
class GradeTooHighExceptionExecutedRequierementGrade : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too high";
        }
};
class GradeTooLowExceptionRequierementGrade : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too low";
        }
};
#endif