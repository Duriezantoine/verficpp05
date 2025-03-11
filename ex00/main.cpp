#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include "BureaucratException.hpp"
#include "BureaucratValidator.hpp"

int main()
{
   std::cout << "\n=== Test 1: Constructeur Normal ===" << std::endl;
   try {
       Bureaucrat normal("Bob", 151); 
       std::cout << normal << std::endl; 
   }
   catch (std::exception& e) {
       std::cout << "Exception: " << e.what() << std::endl;
   }

   std::cout << "\n=== Test 2: Grade Trop Haut ===" << std::endl;
   try {
       Bureaucrat tooHigh("Alice", 0); 
   }
   catch (std::exception& e) {
       std::cout << "Exception: " << e.what() << std::endl;
   }

   std::cout << "\n=== Test 3: Grade Trop Bas ===" << std::endl;
   try {
       Bureaucrat tooLow("Charlie", 151);  
   }
   catch (std::exception& e) {
       std::cout << "Exception: " << e.what() << std::endl;
   }

   std::cout << "\n=== Test 4: Increment/Decrement ===" << std::endl;
   try {
       Bureaucrat worker("Dave", 2);
       std::cout << "Initial: " << worker << std::endl;
       
       worker.incrementGrade(); 
       std::cout << "After increment: " << worker << std::endl;
       
       worker.incrementGrade();  
   }
   catch (std::exception& e) {
       std::cout << "Exception: " << e.what() << std::endl;
   }

   std::cout << "\n=== Test 5: Limite Basse ===" << std::endl;
   try {
       Bureaucrat lowRank("Eve", 150);
       std::cout << "Initial: " << lowRank << std::endl;
       
       lowRank.decrementGrade(); 
   }
   catch (std::exception& e) {
       std::cout << "Exception: " << e.what() << std::endl;
   }

   return 0;
}