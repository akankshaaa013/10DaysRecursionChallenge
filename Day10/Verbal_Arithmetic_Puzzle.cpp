#include<bits/stdc++.h>
using namespace std;

bool isAnyMapping(vector<string>& words,unsigned int row,unsigned int col,unsigned int bal,
                  unordered_map<char, int>& letToDig, char digToLet[],
                  unsigned int totalRows, unsigned int totalCols){

    /*If the banace of the sum of the words is equal to 0 and all the columns in the matrix is filled with digits then the fucntion 
    returns true indicating there exists a mapping of letters to digit that makes the sum of words equal to 0.*/
    if (col == totalCols) {
        if (bal == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    /*The condition checks if the function has traversed all rows of the current column. If "yes" then it checks if the balance of sum is divisible 
    by 10. If it is then isAnyMapping() function is called recusrively for the next column.*/
    if (row == totalRows) {
        return (bal % 10 == 0 && isAnyMapping(words, 0, col + 1, bal / 10, letToDig, digToLet, totalRows, totalCols));
    }

    //w contains the current word that is been mapped to the digit.
    string w = words[row];

    // the condition checks if the current word has any character in the current column. If it doesn't, then it recusrively calls 
    // isAnyMapping() for the next row of the same column.
    if (col >= w.length()) {
        return isAnyMapping(words, row + 1, col, bal, letToDig, digToLet, totalRows, totalCols);
    }

    // Take the current character in letter that is being mapped to digit.
    char letter = w[w.length() - 1 - col];

    // Create a variable 'SIGN' to check whether we have to add it or subtract it.
    int sign;

// if the current row is the last row in the matrix then the sin variable is set to -1 denoting that digit must be subracted from the balance.
// else the sign variable is set to 1 indicating digit must be added.
    if (row < totalRows - 1) {
        sign = 1;
    }
    else {
        sign = -1;
    }

    /*
    It checks whether the current letter is already mapped to a digit and whether the mapping is valid or not. If it is then it
    recursively calls the "isAnyMapping()" for next row of the same column with the current mapping. 
    */
    if (letToDig.find(letter) != letToDig.end() &&
        (letToDig[letter] != 0 || (letToDig[letter] == 0 && w.length() == 1) || col != w.length() - 1)) {
        return isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter], letToDig, digToLet, totalRows, totalCols);
    }

    //If the mapping is not valid then it tries to map the letter to a new digit. 
    else {
        for (int i = 0; i < 10; i++) {

            // If the current digit is not mapped to a letter and the mapping is valid, then it maps a letter to the digit and recursively calls
            // isAnyMapping() function for the next row of the same column with the new paiing. 
            if (digToLet[i] == '-' && (i != 0 || (i == 0 && w.length() == 1) || col != w.length() - 1)) {
                digToLet[i] = letter;
                letToDig[letter] = i;

                // Call the function again with the new mapping.
                bool x = isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter], letToDig, digToLet, totalRows, totalCols);

                // If the function returns true then the mapping is correct else it tries for the next digit not before unmapping the last letter.

                if (x == true) {
                    return true;
                }

                digToLet[i] = '-';
                if (letToDig.find(letter) != letToDig.end()) {
                    letToDig.erase(letter);
                }
            }
        }
    }

    // If nothing is correct then just return false.
    return false;
}

bool isSolvable(int m, vector<string>& words, string result) {

    // Add the string 'RESULT' in the vector 'WORDS'.
    words.push_back(result);

    // Calculating the total no. of rows and columns required to store all the strings in the words vector.
    unsigned int totalRows;
    unsigned int totalCols = 0;

    // Initialize 'TOTALROWS' with the size of the vector.
    totalRows = words.size();

    // Find the longest string in the vector and set 'TOTALCOLS' with the size of that string.
    for (unsigned int i = 0; i < words.size(); i++) {

        // If the current string is the longest then update 'TOTALCOLS' with its length.
        if (totalCols < words[i].length()) {
            totalCols = words[i].length();
        }
    }

    // Create a HashMap for the letter to digit mapping.
    unordered_map<char, int> letToDig;

    // Create an array for the digit to letter mapping.
    char digToLet[10];
    for (int i = 0; i < 10; i++) {
        digToLet[i] = '-';
    }

/*the function returns true if there exists any valid mapping of letters to digits that satisfies the arithmetic equation formed by the words and result
Else it returns false.*/
    return isAnyMapping(words, 0, 0, 0, letToDig, digToLet, totalRows, totalCols);
}



int main(){

    int n;
    cout<<"Enter the size of words : ";
    cin>>n;

    vector<string> words;
    cout<<"Enter the words of length n : ";
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        words.push_back(s);
    }

    string ress;
    cout<<"Enter the result string : ";
    cin>>ress;

    if(isSolvable(n,words,ress)){
        cout<<"Strings can be mapped :)";
    }
    else{
        cout<<"Strings cannot be mapped :)";
    }




}