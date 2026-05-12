/* 

This program is intended to simulate a packing process, where truck loading is updated 
as user inputs fixed item weights that are indivisible. The program ends when the user 
has no more items or when truck capacity is reached. The final representation of the 
trucks are outputted to the user as 1's and 0's, where 1 signals 10lbs of truck capacity 
used and 0 as empty space.
Date: August 2025

*/

#include <iostream>
using namespace std;

int main(){
    // declaring and initializing variables 
    int weight;
    int amount_trucks = 2;
    int truck_index = 0;
    int capacity = 30;
    int sum = 0;
    int trucks[amount_trucks][capacity] = {};
    bool valid = true;
    
    // giving context to user and displaying the menu of choices to click
    cout << "I will ask the weight of your items one by one. Please only select the following options...\n";
    cout << "1. 10 lbs\n2. 20 lbs\n3. 30 lbs\n0. no more items\n";
    cout << "----------------------------------------------------------------------------------------------------------\n";
    
    // while loop to continue until user decides to end it or when truck capacity would be exceeded
    while (valid){
        
        // prompting user to input weight of item, one by one
        cout << "How much does the item weigh? ";
        cin >> weight; 
        
        // testing if user wants to end while loop
        if (weight == 0){
            valid = false;
        }
        
        // testing if weight input is indeed a menu option
        else if (weight > 0 && weight <= 3){
            
            // testing if this additional weight would exceed capacity
            if ((sum + weight) > capacity){
                
                // if so, move on to next truck and restart total weight sum
                truck_index += 1;
                sum = 0;
                
                // if truck index tries go beyond how many trucks are actually available
                if (truck_index == amount_trucks){
                    cout << "\nThere are no more trucks left. Last item did not fit and was disregarded.\n";
                    valid = false;
                }
                
                // continue packing, flipping 0's into 1's
                else {
                    for (int i = sum; i < (sum + weight); i++){
                    trucks[truck_index][i] = 1;
                    }
                    sum += weight;  // keeping track of total weight of current truck
                }
            }
            
            // weight still fits in current truck. continue packing as normal, flipping 0's into 1's
            else{
                for (int i = sum; i < (sum + weight); i++){
                    trucks[truck_index][i] = 1;
                }
                sum += weight;  // keeping track of total weight of current truck
            }
        }
        
        // incorrect input, giving user another chance
        else{
            cout << "Error. try again\n";
        }
    }
    
    // exiting while loop
    
    // for loop to display packed trucks to user
    for (int i = 0; i < amount_trucks; i++){
        cout << "\nTruck " << i + 1 << ": [ ";
        for (int j = 0; j < capacity; j++){
            cout << trucks[i][j] << " ";
        }            
        cout << "]";
    }
    
    return 0;
}
