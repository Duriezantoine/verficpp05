#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>


int main() {
    try {
        // Test de création des bureaucrates
        std::cout << "=== Création des bureaucrates ===" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat intern("Intern", 150);
        
        // std::cout << boss << std::endl;
        // std::cout << manager << std::endl;
        // std::cout << intern << std::endl;
        
        // Test de création des formulaires
        std::cout << "\n=== Création des formulaires ===" << std::endl;
        std::string topSecretName = "Top Secret";
        std::string standardName = "Standard";
        std::string basicName = "Basic";
        
        Form topSecret(topSecretName, false, 5, 3);
        Form standard(standardName, false, 75, 60);
        Form basic(basicName, false, 130, 120);
        
        std::cout << topSecret << std::endl;
        std::cout << standard << std::endl;
        std::cout << basic << std::endl;
        
        // Test de signature des formulaires
        std::cout << "\n=== Test de signature des formulaires ===" << std::endl;
        
        // Le patron peut signer tous les formulaires
        boss.signForm(topSecret);
        boss.signForm(standard);
        boss.signForm(basic);
        
        // Le manager ne peut pas signer le formulaire top secret
        manager.signForm(topSecret);  // Devrait échouer
        manager.signForm(standard);
        manager.signForm(basic);
        
        // Le stagiaire ne peut signer que le formulaire basic
        intern.signForm(topSecret);   // Devrait échouer
        intern.signForm(standard);    // Devrait échouer
        intern.signForm(basic);
        
        // Affichage de l'état des formulaires après signature
        std::cout << "\n=== État des formulaires après signature ===" << std::endl;
        std::cout << topSecret << std::endl;
        std::cout << standard << std::endl;
        std::cout << basic << std::endl;
        
        // Test des exceptions de grade lors de la création
        std::cout << "\n=== Test des exceptions de grade ===" << std::endl;
        try {
            std::string impossibleName = "Impossible";
            Form impossible(impossibleName, false, 0, 1);  // Grade trop élevé
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        try {
            std::string tooLowName = "Too Low"; 
            Form tooLow(tooLowName, false, 151, 1);  // Grade trop bas
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
    } catch (std::exception &e) {
        std::cerr << "Exception non gérée: " << e.what() << std::endl;
    }
    
    return 0;
}