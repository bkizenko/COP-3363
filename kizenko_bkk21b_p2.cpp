
/* ========================================================================== */
/* PROGRAM
   AUTHOR: Boris Kizenko
   FSU MAIL NAME: bkk21b
   RECITATION SECTION NUMBER: 7
   RECITATION INSTRUCTOR NAME: Supriya Palli
   COP 3363 - Fall 2022
   PROJECT NUMBER: 2
   DUE DATE: 9/22/2022
   PLATFORM: g++ / UNIX OS

SUMMARY

This program calculates the price per month of three different internet service subscription packages for customers depending on the amount of hours the customer uses and the package they choose. Furthermore, the program shows how much a customer could save if they switched to a different package.

INPUT
1. The user can selected from a choice of three packages: Package "A", "a", Package "B", "b", or Package "C", "c". 
2. If input is valid, the customer can progress to the next prompt which asks how many hours the user would like to purchase. The user can choose between 0 and 744 hours (the amount of hours in a month).
BAD DATA CHECKING: 
1. if user does not select: "A", "a", "B", "b", "C", or "c" the program will terminate.
2. if user does not choose within the range of hours permitted (0 and 744), the program will terminate. 

OUTPUT
The package and hours the user selected, and their corresponding price. Also, the output shows how much the customer would have saved by switching to different packages, but only if the savings were greater than zero dollars.

ASSUMPTIONS
1. When prompted for a character, the user types a single non-blank character and then hits enter. 
2. When asked for a whole number, the user types an integer value and then hits enter.

*/

#include <iostream> // <- Preprocessor directive, gives access to cout and cin
#include <iomanip> // <- Preprocessor directive

using namespace std; // <- Allows to use all identifiers like cout and cin

int main() // <- Main function
{
  // billing amount per month for PACKAGE_A
  double const PACKAGE_A = 9.95;  
        
  // billing amount per month for PACKAGE_B
  double const PACKAGE_B = 14.95; 

  // billing amount per month for PACKAGE_C
  double const PACKAGE_C = 19.95; 

  // cost for additional hours under PACKAGE_A
  double const ADDITIONAL_HOURS_COST_A  = 2.00; 

  // cost for additional hours under PACKAGE_B
  double const ADDITIONAL_HOURS_COST_B  = 1.00; 

  double billA; // price for bill A
  double billB; // price for bill B
  double billC; // price for bill C

  // variable for the choice in package
  char packChoice; 

  // variable that stores amount of hours used
  int hours;      

  // checks if response is valid or not
  bool validResponse = true; 

  // variable stores number of additional hours for Package A
  double additional_hours_a; 

  // variable stores number of additional hours for Package B
  double additional_hours_b; 

  // variable to store what customer would have saved 
  //switching from Package A to Package B
  double savings_packA_to_packB; 
  
  // variable to store what customer would 
  // have saved switching from Package A to Package C
  double savings_packA_to_packC;

  // variable to store what customer would 
  // have saved switching from Package B to Package A
  double savings_packB_to_packA;
  
  // variable to store what customer would 
  // have saved switching from Package A to Package C
  double savings_packB_to_packC;
  
  // calculates cost of savings of 
  // switching from Package C to Package A
  double savings_packC_to_packA; 
  
  // calculates cost of savings of 
  // switching from Package C to Package B
  double savings_packC_to_packB; 

  cout << fixed << showpoint << setprecision(2); 
  
  // prints out a welcome message to the user
  cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<< endl;
  cout << "Welcome to the ISP Billing Calculator" << endl;
  cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl << endl;
        
  //asking for user packChoice
  cout << "Which package does the customer use (A, B, or C)? ";

  //takes user input for packChoice
  cin >> packChoice;
  
  //checking for invalid inputs which 
  //are letters other than A, B, C, or a, b, or c
  if (packChoice != 'A' && packChoice != 'B' && packChoice != 'C' && 
  packChoice != 'a' && packChoice != 'b' && packChoice != 'c' )
  {
    cout << "Package choice input invalid." << endl << endl;
    validResponse = false; // terminates program if invalid input
  }
  else //checks for number of hours used
  {
  cout << "How many hours did the customer use last month? ";
                
  // takes input for number of hours the customer used
  cin >> hours; 
                
  // checking for hours range
  if (hours < 0 || hours > 744)
  { // handle bad input data
  cout << "Hours input invalid." << endl;
  cout << endl; 

  // uses a boolean to terminate 
  // the else statement and go to the next one
  validResponse = false; 
  }
  }
  /* 
  directs compiler to run the following code
  if the response is 'A', 'a', 'B', 'b', 'C', 
  'c', and hours are in between 0 and 744
  */
    if (validResponse) 
      { 
        cout << "Your charges are: $";

        // calculation for additional 
        // hours of each package cost
        additional_hours_a = hours - 10; 
        additional_hours_b = hours - 20; 

        // sets price for different packages
        billA = PACKAGE_A;
        billB = PACKAGE_B;

      if  (additional_hours_a > 0) 
      { // checks that data is relative to this if statement
        billA = PACKAGE_A + 
        (ADDITIONAL_HOURS_COST_A * additional_hours_a);
      }  
      if (additional_hours_b > 0)
      { // checks that data is relative to this if statement
        billB = PACKAGE_B + 
        (ADDITIONAL_HOURS_COST_B * additional_hours_b);
      }    
      // returns price for customer if they choose 
      // Package A and use less than or equal to 10 hours
      if ((packChoice == 'A' || packChoice == 'a') && hours <= 10)
      { // checks that data is relative to this if statement
        // outputs Package A price under given conditions
        cout << PACKAGE_A << endl << endl; 
      }
      // returns price for customer if they choose 
      // Package B and use less than or equal to 20 hours
      if ((packChoice == 'B' || packChoice == 'b') && hours <= 20)
      { // checks that data is relative to this if statement
        // outputs Package B price under given conditions
        cout << PACKAGE_B << endl << endl; 
      if (billB > billA)
      {
        cout << "By switching to Package A you would save: $"; 
        // subtract cost of package B from cost of package A
        savings_packB_to_packA = billB - PACKAGE_A; 
        cout << savings_packB_to_packA << endl << endl; 
      }  
      }
      // returns price of package C. Package C's 
      // price is unrelated to the hours used.
      else if (packChoice == 'C' || packChoice == 'c')
      {
        billC = PACKAGE_C;
        cout << billC << endl << endl;
        // checks if customer would save any 
        // money by swtiching to Package A
        if (billC > billA)
        { 
          cout << "By switching to Package A you would save: $";
          // calculates cost of savings of 
          // switching from Package C to Package A              
          savings_packC_to_packA = billC - billA; 
          cout << savings_packC_to_packA << endl << endl;
        }  
        if (billC > billB )
        {
          cout << "By switching to Package B you would save: $"; 
          // cout << billB << endl;
          // calculates cost of savings of 
          // switching from Package C to Package B
          savings_packC_to_packB = billC - billB; 
          cout << savings_packC_to_packB << endl << endl;  
        }          
      }
      if ((packChoice == 'A' || packChoice == 'a') 
      && ((hours > 10) && ((hours < 20))))
      { // checks that input data is in between 10 and 20 hours
        cout << billA << endl << endl;

      if (billA > billB)
      {
       cout << "By switching to Package B you would save: $"; 
    
        // subtract cost of package B from cost of package A
        savings_packA_to_packB = billA - PACKAGE_B; 
        cout << savings_packA_to_packB << endl << endl; 
         
      }
        
        // Stores value for the savings of 
        // switching from packA to packC 
        savings_packA_to_packC = billA - billC; 
        
        // only runs if switching from packA to packC 
        // is advantageous for the customer  
          if (savings_packA_to_packC > 0) 
          { // checks if savings are greater 
          // than 0 and worth mentioning
          cout << "By switching to Package C you would save: $";
          // subtract cost of package C from cost of package A
          cout << savings_packA_to_packC << endl << endl;
          }
      }
      if ((packChoice == 'A' || packChoice == 'a') 
      && (hours >= 20))
      { // checks if package A is selected and 
      // hours are greater than 20  
      billA = PACKAGE_A + (ADDITIONAL_HOURS_COST_A * additional_hours_a);
      cout << billA << endl << endl;
      cout << "By switching to Package B you would save: $"; 
        
      // subtract cost of package B from cost of package A
      savings_packA_to_packB = billA - billB; 
      cout << savings_packA_to_packB << endl << endl; 
      
      // stores value for the savings of switching from packA to packC
      savings_packA_to_packC = billA - billC; 
        
      // only runs if switching from 
      // packA to packC is advantageous for the customer
        if (savings_packA_to_packC > 0)  
        { // checks if savings from package A to C are significant
        cout << "By switching to Package C you would save: $";
          
        // subtract cost of package C from cost of package A
        cout << savings_packA_to_packC << endl << endl;
        }
      } 
      if ((packChoice == 'B' || packChoice == 'b') && hours > 20) 
      { // calculates bill for package B with hours greater than 20
      cout << billB << endl << endl;
      savings_packB_to_packC = billB - billC; 
        
        // only runs if switching from packA to 
        // packC is advantageous for the customer    
        if (savings_packB_to_packC > 0) 
        { // calculates savings of switching from package B to C
        cout << "By switching to Package C you would save: $";
          
        // subtract cost of package C from cost of package A
        cout << savings_packB_to_packC << endl << endl;
        }
      }
    }    
cout << "Execution Terminated Normally.";
return 0; // <- main return value
}
