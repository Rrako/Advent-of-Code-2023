#include <stdio.h>

int CharToInt(char c) {
    int i = c - '0';
    return i;
}

int main() {
    // Open a file in read mode
    FILE *fptr = fopen("puzzle_input.txt", "r");

    // Print some text if the file does not exist
    if(fptr == NULL) {
    printf("Not able to open the file.");
    }

    // Defining the line string
    char fStr[100];
    // Counting integer
    int i = 0;
    // Calibration value, Total, first number bool
    int Calib, Total = 0, Firstnum;
    // First and Last integers from line string
    char First, Last;
    
    // Grabbing each line from the file
    while (fgets(fStr, 100, fptr)) {
        // resetting bool for each line
        Firstnum = 1;
        for (i=0;i<100;i++) {
            // if char is integer
            if (0<=CharToInt(fStr[i]) && CharToInt(fStr[i])<=9) {
                // if it is the first integer in the line
                if (Firstnum == 1) {
                    First = fStr[i];
                    Last = fStr[i];
                    Firstnum = 0;
                } else {
                    Last = fStr[i];
                }
            }
        }

        // Concatenating the first (f) and last (l) integers from the line
        char fl[2] = {First, Last};
        Calib = 0;
        // adding the first number
        Calib += CharToInt(fl[0]) * 10;
        // adding the second number
        Calib += CharToInt(fl[1]);
        Total += Calib;

        //resetting the string for next loop
        memset(fStr, 0, sizeof(fStr));
    }
    printf ("%i", Total);
    

}