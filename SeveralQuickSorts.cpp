// Serial Number : 32, 44
// Group Number:
// Author : Erik Pantoja, Huy Tran
// Due Date : 24 April 2019
// Programming Assignment Number 6
// Spring 2019 - CS 3358 - 253
// Instructor: Husain Gholoom

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>

//Function Prototypes
void welcomeMessage(); // Provides the sample output of the greeting
void inputFunction(); //Accepts user input of int, and creates a array of that size in chars
void displayArrIfGreaterThan20(char charArr[]); //displays first 20 elements if size is less
//then 20
int sequentialSearch(char charArr[], int l, int r, int value, int &compars); // searchs array
//using recurssion for char 80, and displays comparisons
void selectionSort(char charArr[], int arrSize, int &numOfSwaps); // Sorts array by selection
//sort and displays how many switches it makes
void insertionSort(char charArr[], int arrSize, int &compars); // Sorts array by insertion sort
// and displays how many comparisons it makes
void quickSort1(char arr[], int left, int right, int &numOfRecursions); // Sort using quick sort
// , use middle value as pivot, and display recurrison calls
void quickSort3(char arr[], int left, int right, int &numOfRecursions); // Sort using quick sort,
//use first value as pivot, and display recurrison calls
void quickSort2(char arr[], int left, int right, int &numOfRecursions); // Sort using quick sort
//, use last value as pivot, and display recurrison
int partition (char a[], int left, int right); //Splits up for quicksorts
void swap(char *xp, char *yp); //Swaps places for quicksorts
void printArr(char arr[], int arrSize); //Prints out the arrays

// Main Functionusing
using namespace std;
int main() {
    welcomeMessage();               // Function that Displays main Message
    int arrSize = 0;                // initialize arrSize
    cout << "Enter the size of the array: ";
    cin >> arrSize;                 // Accepts array size to build array off of
    while (arrSize < 0) {           // error checking
        cout << "Error: Invalid input, Size must be > 0: ";
        cin >> arrSize;             // Reaccepts the array size
    }
    char arr[arrSize];              // Creating a Char array
    srand(time(0));                 // Keeps the Array random

    cout << "Array elements are: ";
    for (int i = 0; i < arrSize; i++) {     // randomizing the character array
        arr[i] = rand()%(126-33+1) + 33;    // between 33 - 126 ASCII values
        cout << arr[i] << " ";              // Displays the random array
    }
    cout << endl<<endl<<endl;
    if (arrSize > 20)
        displayArrIfGreaterThan20(arr);   // Displays the array if more then 20
    int n = sizeof(arr) / sizeof(arr[0]); // accepts the size of total array
    // dividied by array at index 0
    char charValue = 80;        // character to search for
    int numOfComparisons = 0;   // counts comparisons
    cout << "\n\nSequential Search" << endl << endl;
    cout << "Searching for 80" << endl << endl;
    clock_t t;                  // clocking time for measurement
    t = clock();                // Creating a variable of clock time
    cout << "Start time: " << t << " s" << endl;
    sequentialSearch(arr, 0, n - 1, charValue, numOfComparisons); //Conducting search
    t = clock() - t;                                              //t holds clock time
    cout << "End time: " << t << " s" << endl;                    //Displaying ending time
    double time_taken = ((double)t)/CLOCKS_PER_SEC;               //Calculating clock time
    cout << "Actual CPU clock time: " << time_taken << " s" << endl;
    cout << "Total number of comparisons: " << numOfComparisons << endl <<endl;
    int numOfSwaps = 0;                         //number of selection sort swaps
    cout << "Selection Sort" << endl << endl;
    char selectionSortArr[arrSize];             //creating array for selectionsort
    for (int i = 0; i < arrSize; i++){
        selectionSortArr[i] = arr[i];
    }
    t = clock ();                                //holds clock time
    cout << "Start time: " << t << " s" <<endl;  //displays clock time
    selectionSort(selectionSortArr, arrSize, numOfSwaps);
    t = clock() - t;                             //calculating clock end time
    cout << "End time: " << t << " s" << endl;   //displaying clock end time
    time_taken = ((double)t)/CLOCKS_PER_SEC;     //calculating program time
    cout << "Actual CPU clock time: " << time_taken << " s" << endl;
    cout << "Total number of swaps: " << numOfSwaps << endl;
    cout << "Sorted elements: ";
    printArr(selectionSortArr, arrSize); //Printing array for selectionsort
    cout << endl << endl;
    numOfComparisons = 0;                //variable to hold comparisons
    cout << "Insertion Sort" << endl << endl;
    char insertionSortArr[arrSize];      //Creating array for insertionsort
    for (int i = 0; i < arrSize; i++){   //adding to insertion sort array
        insertionSortArr[i] = arr[i];
    }
    t = clock ();                         //holding clock time
    cout << "Start time: " << t << " s" <<endl;
    insertionSort(insertionSortArr, arrSize, numOfComparisons);
    t = clock() - t;                      //holding clock end time
    cout << "End time: " << t << " s" << endl;  //displaying clock end time
    time_taken = ((double)t)/CLOCKS_PER_SEC;    //calculating program time
    cout << "Actual CPU clock time: " << time_taken << " s" << endl;
    cout << "Total number of comparisons: " << numOfComparisons << endl;
    cout << "Sorted Elements: ";
    printArr(insertionSortArr, arrSize); // displaying sorted elements of array
    cout << endl << endl;
    cout << "Quick Sort - Next to middle element as pivot: " << endl << endl;
    int numOfRecursions = 0;            //holds each recursion number
    char quickSort1Arr[arrSize];        //creating quicksort array
    for (int i = 0; i < arrSize; i++){  //adding to quicksort array
        quickSort1Arr[i] = arr[i];
    }
    t = clock();                                //beginning clock time
    cout << "Start time " << t << " s" << endl; // displaying clock time
    quickSort1(quickSort1Arr, 0, arrSize - 1, numOfRecursions );
    t = clock() - t;                            //calculating end clock time
    cout << "End time: " << t << " s" << endl;  //displaying ending time
    time_taken = ((double)t)/CLOCKS_PER_SEC;    //calculating total time used
    cout << "Actual CPU clock time: " << time_taken << " s" << endl;
    cout << "Total number of recursive calls: " << numOfRecursions << endl;
    cout << "Sorted elements: ";
    printArr(quickSort1Arr, arrSize);           // printing out quicksort array
    cout << endl << endl;
    numOfRecursions = 0;                        //holds number of recursions
    cout << "Quick Sort - First as pivot: " << endl << endl;
    char quickSort2Arr[arrSize];                //creating quicksort array
    for (int i = 0; i < arrSize; i++){          //adding to quicksort array
        quickSort2Arr[i] = arr[i];
    }
    t = clock();                                //holds clock time
    cout << "Start time " << t << " s" << endl; //displays clock time
    quickSort2(quickSort2Arr, 0, arrSize - 1, numOfRecursions );
    t = clock() - t;                            //holds ending clock time
    cout << "End time: " << t << " s" << endl;  //displaying ending clock time
    time_taken = ((double)t)/CLOCKS_PER_SEC;    //calculating total time used
    cout << "Actual CPU clock time: " << time_taken << " s" << endl;
    cout << "Total number of recursive calls: " << numOfRecursions << endl;
    cout << "Sorted elements: ";
    printArr(quickSort2Arr, arrSize);         //printing out quicksort array 2
    cout << endl << endl;
    numOfRecursions = 0;                      //holds number of recursions
    cout << "Quick Sort - Last as pivot: " << endl << endl;
    char quickSort3Arr[arrSize];              //creating quicksort array 3
    for (int i = 0; i < arrSize; i++){        //adding info to quicksort array
        quickSort3Arr[i] = arr[i];
    }
    t = clock();                                  //holds current clock time
    cout << "Start time " << t << " s" << endl;   //displays current time
    quickSort3(quickSort3Arr, 0, arrSize - 1, numOfRecursions );
    t = clock() - t;                              //holds ending clock time
    cout << "End time: " << t << " s" << endl;    //displaying ending clock time
    time_taken = ((double)t)/CLOCKS_PER_SEC;      //calculating time used
    cout << "Actual CPU clock time: " << time_taken << " s" << endl;
    cout << "Total number of recursive calls: " << numOfRecursions << endl;
    cout << "Sorted elements: ";
    printArr(quickSort3Arr, arrSize);           //print quicksort array 3
    cout << endl << endl;
    cout << endl;
    cout << " Benchmark Algorithm Implemented by : Erik, Pantoja, Huy Tran" <<endl;
    cout << " 24 - 4 - 2019"<<endl<<endl;
    return 0;
}

// Function Definitions

void welcomeMessage(){
    cout << "Searching / Sorting Benchmark\n\n";
    cout << " Using a random number generator, we are creating an array of n\n ele
    cout <<  "ments of type integer then performing the following  : "<<endl<<endl;
    cout << "   1. Displaying the first 20 numbers."<<endl<<endl;
    cout << "   2. Using recursion, Searching for an element in the array using\n
    "sequential search and at the end displaying number of comparisons\n   it makes."<<endl<<endl;
    cout << "   3. Sort the original array using Selection Sort and at the end\n
    "display the number of swaps it makes."<<endl<<endl;
    cout << "   4. Sorting the array using insertion Sort and at the end\n   displaying the
    "number of comparisons it makes."<<endl<<endl;
    cout << "   5. Sorting the array using Quick Sort and at the end displaying\n   the number of
    "recursion calls it makes. Using the next to the \n   middle value as a pivot value."<<endl<<endl;
    cout << "   6. Sorting the same array using Quick Sort and at the end\n   displaying
    "the number of recursion calls it makes. Using the\n   first value as a pivot value."<<endl<<endl;
    cout << "   7. Sorting the same array using Quick Sort and at the end\n   displaying
    "the number of recursion calls it makes. Using the\n   last value as a pivot value."<<endl<<endl;
    cout << "   8. For each of the preceding steps ( 2 thru 5 ), calculating and\n
    "printing the CPU time before each step starts and after each\n   completed step then calculating
    " actual CPU time for the\n   completion of each step."<<endl<<endl<<endl;
}

int sequentialSearch(char charArr[], int l, int r, int value, int &compars) {
    compars++;
    if (r < 1)                      //holds r which is size of array minue 1
        return -1;                  //returns -1 if less then 1(no array size
    if (charArr[l] == value){       //comparing to passed value each element
        cout << "Found 80(P). Returning..." << endl;
        return l;                   //returns the index
    }
    if (charArr[r] == value){       // comparing index at r to the passed value
        cout << "Found 80(P). Returning..." << endl;
        return r;                   //if found return that value
    }
    if (l == r){                    //comparing to see if 2 returned values are same
        cout << "80(P) was not found." << endl;
        return 0;
    }
    return sequentialSearch(charArr, l + 1, r - 1, value, compars); //return values of search
}

void displayArrIfGreaterThan20(char charArr[]) {
    cout << "First 20 values of array: ";
    for (int i = 0; i < 20; i++ ) { //displaying the first 20 values od array
        cout << charArr[i] << " ";  //displays each value
    }
    cout << endl;
}

void swap(char *xp, char *yp){
    char temp = *xp;        //holds a char pointer to switch
    *xp = *yp;              //compares 2 pointers passed
    *yp = temp;             //then assigns pointer as previous pointer
}

void selectionSort(char charArr[], int arrSize, int &numOfSwaps){
    int i, j, min_idx;  //temp values for function

    for (int i = 0; i < arrSize - 1; i++){
        min_idx = i; //saving each value starting at front
        for (j = i + 1; j < arrSize; j++){
            if (charArr[j] < charArr[min_idx])
                min_idx = j;
        }
        swap(&charArr[min_idx], &charArr[i]); //Swaps values
        numOfSwaps++;                         //calculates sweeps
    }
}

void insertionSort(char charArr[], int arrSize, int &compars){
    int i, j, key;                  //temp values for function

    for (i = 0; i < arrSize; i++){
        key = charArr[i];
        j = i - 1;

        while (j >= 0 && charArr[j] > key) {
            charArr[j + 1] = charArr[j];
            j = j - 1;              //holds j with 1 less eah time
        }
        charArr[j + 1] = key;
        compars++;                  //displaying number of compares
    }
}

void quickSort1(char arr[], int left, int right, int &numOfRecursions) {
    int i = left, j = right;  // holds values for left and right
    int tmp;                  // holds temp value

    int pivot = arr[((left + right) / 2) + 1]; // creating pivot

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j){      //comparing left size
        quickSort1(arr, left, j, numOfRecursions);
        numOfRecursions++;
    }
    if (i < right){     //comparing right side
        quickSort1(arr, i, right, numOfRecursions);
        numOfRecursions++;
    }
}

void quickSort2(char arr[], int left, int right, int &numOfRecursions) {
    int i = left, j = right;  //temp values to hold each side
    int tmp; //temp values to hold each side

    int pivot = arr[left];  //creating a pivot element

    while (i <= j) {
        while (arr[i] < pivot) // comparing with sides, and pivot
            i++;
        while (arr[j] > pivot) // comparing with sides, and pivot
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j){
        quickSort2(arr, left, j, numOfRecursions);
        numOfRecursions++;
    }
    if (i < right){
        quickSort2(arr, i, right, numOfRecursions);
        numOfRecursions++;
    }
}

void quickSort3(char arr[], int left, int right, int &numOfRecursions) {
    int i = left, j = right;  //temp values to hold each side
    int tmp; //temp values to hold each side

    int pivot = arr[right]; //creating a pivot element

    while (i <= j) {
        while (arr[i] < pivot) // comparing with sides, and pivot
            i++;
        while (arr[j] > pivot) // comparing with sides, and pivot
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j){   //comparing left side
        quickSort3(arr, left, j, numOfRecursions);
        numOfRecursions++;
    }
    if (i < right){  //comparing right side
        quickSort3(arr, i, right, numOfRecursions);
        numOfRecursions++;
    }
}

void printArr(char arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){ //prints out the array
        cout << arr[i] << " ";
    }
}