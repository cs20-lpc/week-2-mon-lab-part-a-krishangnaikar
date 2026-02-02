#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void populate(string*, const unsigned);
void printFoods(string*, const unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Creates a dynamic array of strings. User gets
 * to specify their desired size. Calls functions. Releases dynamic memory.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    string*  dynArr   = nullptr;                                                        // Intializes the dynamic array for the food items to go into
    unsigned userSize = 0;                                                              // Size of dynArry (Initialized by user)


    do {                                                                                // Do while to make sure it runs atleast once
        cout << "Enter your desired array size (Must be less than 10): ";               // Print the message to get the size of dynArrray
        cin >> userSize;                                                                // Get the inputted size
    } while (userSize > 10 || userSize <= 0);                                           // Make sure its < 10 and > 0 (If not, repeat the message and get another input)

    dynArr = new string[userSize];                                                      // Intialize the new memory and give the pointer to dynArray


    populate(dynArr, userSize);                                                         // Populate dynArrray
    printFoods(dynArr, userSize);                                                       // Print the inputted foods

    delete[] dynArr;                                                                    // Release memory to avoid memory leak

    return 0;                                                                           // End code
}

/*******************************************************************************
 * Description:
 * Gets data from the user to populate the array pointed to by `arrPtr`.
 * 
 * Input:
 * arrPtr   - a pointer to the beginning of a string array
 * ARR_SIZE - a constant unsigned integer containing the size of the array
 *            pointed to by `arrPtr` (the number of elements)
 *
 * Output:
 * N/A
*******************************************************************************/

void populate(string* arrPtr, const unsigned ARR_SIZE) {
    for (int i = 0; i < ARR_SIZE; i++) {                                                // For loop to fill the array
        cout << "Enter food order #" << i+1 << ": ";                                    // Prompt sent to user to input food
        getline(cin >> ws, arrPtr[i]);                                                  // Get input back and set the currenyt position of arrPtr to it (cin >> ws makes sure the new line from the last cin doesn't affect the input)
                                                                                        // (getline makes sure that multiple words are included)
    }
}

/*******************************************************************************
 * Description:
 * Displays the information stored in the array pointed to by `arrPtr`. Also
 * prints what memory address each element is stored in.
 * 
 * Input:
 * arrPtr   - a pointer to the beginning of a string array
 * ARR_SIZE - a constant unsigned integer containing the size of the array
 *            pointed to by `arrPtr` (the number of elements)
 *
 * Output:
 * N/A
*******************************************************************************/

void printFoods(string* arrPtr, const unsigned ARR_SIZE) {
    for (int i = 0; i < ARR_SIZE; i++) {                                                // For loop to iterate through the array and print the info
        cout << "****************************************" << endl;                     // Seperator
        cout << "Food Order #" << i+1 << endl;                                          // Food order number
        cout << arrPtr[i] << endl;                                                      // Food item attributed to order number
        cout << &arrPtr[i] << endl;                                                     // Pointer where food item is stored
        cout << "****************************************" << endl;                     // Seperator
        cout << endl;
    }
    
    
}
