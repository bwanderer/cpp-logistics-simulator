/* 

This program is intended to calculate how many minimum trips are required to transport 
all items without exceeding the fixed truck capacity or splitting packages. 
Date: August 2025

*/

#include <iostream>
#include <iomanip>

using namespace std;

// function to display results
int showvalues(int trips){
    
    // outputting to user how many total trips needed without exceeding capacity
    cout << showpos;
    cout << "----------------------------------------------------------------------------------------------------------\n";
    cout << "Without exceeding capacity, the minimum number of truck trips is:\n";
    cout << setw(4) << setfill('0') << trips << endl;
    cout << "----------------------------------------------------------------------------------------------------------\n";


    return 0;
}

int main() {
    int num_one, num_two, num_three;

    int trips = 0;  // total trip counter
    
    // prompting user to input the quantity they have of each package, then initializing
    cout << "How many 100 lbs packages do you have: ";
    cin >> num_one;
    cout << "How many 200 lbs packages do you have: ";
    cin >> num_two;
    cout << "How many 300 lbs packages do you have: ";
    cin >> num_three;

    // if loop to catch input errors i.e. negative numbers 
    if ((num_one >= 0) && (num_two >= 0) && (num_three >= 0)){
        
        // 300 lb packages instantly fills the truck
        trips += num_three;  
        
        // using int division (disregards decimals), we know how many trucks can carry 100 lb packages (3 at a time)
        trips += (num_one / 3);
        // replacing num_one variable with the remainder after filling as many trucks as it can
        num_one %= 3;
        
        // while loop to pair 100 and 200 lb packages together, each pairing fills one truck, and subtracting packages each loop
        while (num_one > 0 && num_two > 0){
            num_one -= 1;
            num_two -= 1;
            trips += 1;
        }
        // loop ends only if num_one or num_two run out
        
        
        // if num_two packages remain, they go in truck separately
        if (num_two > 0){
            trips += num_two;
        }
        // if num_one packages remain, they fit together in truck
        if (num_one > 0){
            trips += 1;
        }
            
        // calling function to display the results to user
        showvalues(trips);
    }
    
    // catching else, catching possible errors
    else{
        cout << "Input error, please try again. Using non-negative numbers.";
    }
    
    return 0;
}
