#ifndef Form_EXCEPTION_HPP
#define Form_EXCEPTION_HPP

#include <exception>

class GradeTooHighExceptionSignedRequierementsGrade : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too high for signing requirement";
        }
};

class GradeToolowExceptionSignedRequierementsGrade : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too low for signing requirement";
        }
};

class GradeTooHighExceptionExecutedRequierementGrade : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too high for execution requirement";
        }
};

class GradeTooLowExceptionRequierementGrade : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too low for execution requirement";
        }
};

class GradeTooNoCorrespondSignedRequierementsGradeAAFormShrubber : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade doesn't meet ShrubberyCreationAForm signing requirements (145)";
        }
};

class GradeTooNoCorrespondExeRequierementsGradeAAFormShrubber : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade doesn't meet ShrubberyCreationAForm execution requirements (137)";
        }
};

class GradeTooNoCorrespondSignedRequierementsGradeAAFormRobotomy : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade doesn't meet RobotomyRequestAForm signing requirements (72)";
        }
};

class GradeTooNoCorrespondExeRequierementsGradeAAFormRobotomy : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade doesn't meet RobotomyRequestAForm execution requirements (45)";
        }
};

class GradeTooNoCorrespondSignedRequierementsGradeAAFormPresidentialPardon : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade doesn't meet PresidentialPardonAForm signing requirements (25)";
        }
};

class GradeTooNoCorrespondExeRequierementsGradeAAFormPresidentialPardon : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade doesn't meet PresidentialPardonAForm execution requirements (5)";
        }
};
class AFormNotSignedException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Not signed";
        }
};

#endif 