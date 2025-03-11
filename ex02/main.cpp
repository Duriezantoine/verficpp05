#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>  
#include <ctime>  


int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    try {
        std::cout << "=== CRÉATION DES BUREAUCRATES ===" << std::endl;
        Bureaucrat president("President", 1);
        Bureaucrat minister("Minister", 20);
        Bureaucrat director("Director", 40);
        Bureaucrat manager("Manager", 70);
        Bureaucrat employee("Employee", 100);
        Bureaucrat intern("Intern", 145);
        
        std::cout << "\n=== AFFICHAGE DES BUREAUCRATES ===" << std::endl;
        std::cout << president << std::endl;
        std::cout << minister << std::endl;
        std::cout << director << std::endl;
        std::cout << manager << std::endl;
        std::cout << employee << std::endl;
        std::cout << intern << std::endl;
        
        std::cout << "\n=== CRÉATION DES AFormULAIRES ===" << std::endl;
        ShrubberyCreationAForm shrubbery("Garden");
        RobotomyRequestAForm robotomy("John");
        PresidentialPardonAForm pardon("Criminal");
        
        std::cout << "\n=== AFFICHAGE DES AFormULAIRES ===" << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
        
        std::cout << "\n=== TEST DE SIGNATURE PAR DIFFÉRENTS GRADES ===" << std::endl;
        
        std::cout << "\n-- Intern (grade 145) --" << std::endl;
        intern.signAForm(shrubbery);     // Devrait réussir (grade requis: 145)
        intern.signAForm(robotomy);      // Devrait échouer (grade requis: 72)
        intern.signAForm(pardon);        // Devrait échouer (grade requis: 25)
        
        std::cout << "\n-- Manager (grade 70) --" << std::endl;
        manager.signAForm(robotomy);     // Devrait réussir (grade requis: 72)
        
        std::cout << "\n-- Director (grade 40) --" << std::endl;
        director.signAForm(pardon);      // Devrait réussir (grade requis: 25)
        
        std::cout << "\n=== TEST D'EXÉCUTION PAR DIFFÉRENTS GRADES ===" << std::endl;
        
        std::cout << "\n-- Intern (grade 145) --" << std::endl;
        intern.executeAForm(shrubbery);  // Devrait échouer (grade requis: 137)
        
        std::cout << "\n-- Employee (grade 100) --" << std::endl;
        employee.executeAForm(shrubbery); // Devrait réussir (grade requis: 137)
        
        std::cout << "\n-- Manager (grade 70) --" << std::endl;
        manager.executeAForm(robotomy);   // Devrait échouer (grade requis: 45)
        
        std::cout << "\n-- Director (grade 40) --" << std::endl;
        director.executeAForm(robotomy);   // Devrait réussir (grade requis: 45)
        director.executeAForm(pardon);     // Devrait échouer (grade requis: 5)
        
        std::cout << "\n-- President (grade 1) --" << std::endl;
        president.executeAForm(shrubbery); // Devrait réussir
        president.executeAForm(robotomy);  // Devrait réussir
        president.executeAForm(pardon);    // Devrait réussir
        
        std::cout << "\n=== TEST AVEC AFormULAIRE NON SIGNÉ ===" << std::endl;
        ShrubberyCreationAForm unsignedAForm("UnsignedGarden");
        president.executeAForm(unsignedAForm);  // Devrait échouer car non signé
        
        std::cout << "\n=== TEST DE CRÉATION AVEC GRADES INVALIDES ===" << std::endl;
        std::cout << "-- Grade trop élevé (0) --" << std::endl;
        Bureaucrat tooHigh("TooHigh", 0);  // Devrait lancer GradeTooHighException
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TESTS SUPPLÉMENTAIRES ===" << std::endl;
    
    try {
        std::cout << "-- Grade trop bas (151) --" << std::endl;
        Bureaucrat tooLow("TooLow", 151);  // Devrait lancer GradeTooLowException
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n-- Test multiples exécutions robotomy --" << std::endl;
        Bureaucrat chief("Chief", 1);
        RobotomyRequestAForm multiRobot("TestSubject");
        chief.signAForm(multiRobot);
        
        // Exécuter plusieurs fois pour montrer la probabilité de 50%
        for (int i = 0; i < 5; i++) {
            chief.executeAForm(multiRobot);
        }
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}