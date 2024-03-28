#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void encrypt(string&, int);
void decrypt(string&, int);
int charCheck(char);

int main(int argc, char* argv[]){

    if(argc == 2){
        string temp = argv[1];

        if(temp == "--help"){
            cout << "-e               Encrypt mode" << endl;
            cout << "-d               Decrypt mode" << endl;
            cout << "-i <filename>    The file to encrpty/decrypt" << endl;
            cout << "-o <filename>    Where to store the encrypted/decrypted data" << endl;
            cout << "-k <key>     The key to the incryption" << endl;
            cout << "--help           Brings up this menu" << endl;
            cout << endl;
            cout << "Example: \"./main -e -k <key> -i <input_filename> -o <output_filename>\"" << endl;
            return 0;
        }

    }

    if(argc != 8){
        cout << "Invaild Syntax." << endl;
        cout << "Try \"./main --help\"" << endl;
        return 1;
    }

    int encryptFlag = 2;
    int cypherKey = 0;
    string iName, oName;
    ifstream input;
    ofstream output;

    for(unsigned int i = 1; i < argc; i++){ // flag logic

        string currArg = argv[i];

        if(currArg == "-e"){
            encryptFlag = 1;
            continue;
        }

        if(currArg == "-d"){
            encryptFlag = 0;
            continue;
        }

        if(currArg == "-k"){
            if(i == argc - 1){
                cout << "Invalid Flag Use." << endl;
                return 1;
            }

            i++;
            currArg = argv[i];

            cypherKey = atoi(currArg.c_str());

            continue;
        }

        if(currArg == "-i"){

            if(i == argc - 1){
                cout << "Invalid Flag Use." << endl;
                return 1;
            }

            i++;
            currArg = argv[i];

            iName = currArg;

            continue;
        }

        if(currArg == "-o"){
            if(i == argc - 1){
                cout << "Invalid Flag Use." << endl;
                return 1;
            }

            i++;
            currArg = argv[i];

            oName = currArg;

            continue;
        }

    }

    if(encryptFlag == 2){
        cout << "Encrypt/Decrypt Flag not found." << endl;
        return 1;
    }

    if(iName == ""){
        cout << "No Input File Passed." << endl;
        return 1;
    }

    if(oName == ""){
        cout << "No Output File Passed." << endl;
        return 1;
    }

    input.open(iName);

    if(!input.is_open()){
        cout << "Input File Failed to Open." << endl;
        return 1;
    }

    output.open(oName);

    if(!output.is_open()){
        cout << "Output File Failled to be Created." << endl;
        return 1;
    }

    
    if(cypherKey == 0){
        cypherKey = 5;
    }

    if(encryptFlag){ // encrypting;

        while(!input.eof()){

            string currLine;
            getline(input, currLine);

            encrypt(currLine, cypherKey);

            output << currLine << "\n";

        }

    } else { // decrypting

        while(!input.eof()){

            string currLine;
            getline(input, currLine);

            decrypt(currLine, cypherKey);

            output << currLine << "\n";

        }

    }

    if(input.is_open()){
        input.close();
    }

    if(output.is_open()){
        output.close();
    }

    return 0;
}

void encrypt(string& s, int key){

    string encStr;

    for(unsigned int i = 0; i < s.size(); i++){

        char c = s.at(i);

        switch(charCheck(c)){
            case 1:
                c -= 65;
                c += key;
                c %= 26;
                c += 65;
                break;
            case 2:
                c -= 97;
                c += key;
                c %= 26;
                c += 97;
                break;
        }

        encStr.push_back(c);

    }

    s = encStr;

}

void decrypt(string& s, int key){

    int newKey = key % 26;
    string decStr;

    for(unsigned int i = 0; i < s.size(); i++){

        char c = s.at(i);

        switch(charCheck(c)){
            case 1:
                c -= 65;
                c -= newKey;
                if(c < 0){
                    c += 26;
                } else {
                    c %= 26;    
                }
                c += 65;
                break;
            case 2:
                c -= 97;
                c -= newKey;
                if(c < 0){
                    c += 26;
                } else {
                    c %= 26;    
                }
                c += 97;
                break;
        }

        decStr.push_back(c);
    
    }

    s = decStr;

}

/**
 * Custom character checker
 * @param c the character to check
 * @return 1 for uppercase, 2 for lowercase, and 0 for everything else
*/
int charCheck(char c){

    if(c >= 65 && c <= 90){
        return 1;
    }

    if(c >= 97 && c <= 122){
        return 2;
    }

    return 0;

}