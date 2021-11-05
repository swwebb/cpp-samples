#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Returns a string with all occurrences of char c removed.
string removeLetter(string s, char c) {
    //If the string’s length is 0, we have reached the end of the string,
    //so we must return an empty string to concatenate.
    if(s.length() == 0) {
        return "";
    }
    //If the first character is a character we want to remove, then simply
    //skip this character and keep looking through the rest of the
    //string by recursively calling removeLetter.
    else if(toupper(s[0]) == toupper(c)) {
        return removeLetter(s.substr(1), c);
    }
    //If we don’t want to remove the first character, then concatenate it
    //onto the returned value, and recursively call removeLetter again on
    //the rest of the string.
    else {
        return s[0] + removeLetter(s.substr(1), c);
    }
}

int main() {
	//Declare the string
	string myString = "myString contains several characters! Some are uppercase, and some are lowercase.";
	//Print the original string
	cout << "Original: " << endl << myString << endl;
	//Print the string with all 's' characters removed
	cout << "With all occurrences of 's' removed" << endl << removeLetter(myString, 's');
}