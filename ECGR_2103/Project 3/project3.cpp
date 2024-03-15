#include <iostream>
#include <string>

using namespace std;

int main(){

    /*
        MAD LIB:

        It was a [ADJECTIVE], cold November day.
        I woke up to the [ADJECTIVE] smell of [TYPE OF BIRD] 
        roasting in the [ROOM IN HOUSE] downstairs.
        I [VERB (PAST TENSE)] down the stairs to see if I could
        help [VERB] the dinner. My Mom said, "See if [RELATIVE'S NAME]
        needs a fresh [NOUN]." So I carried a tray of glasses
        full of [LIQUID] into the [VERB (ENDING WITH "-ING")] room.
        When I got there, I couldn't beleive my [PART OF THE BODY (PLURAL)]!
        There were [NOUN (PLURAL)] [VERB (ENDING WITH "-ING")] on the [NOUN]!
    
    */

    string story = "", temp;

    story += "It was a ";

    cout << "Please enter a Adjective: ";
    getline(cin, temp);

    story += temp + ", cold November day.\nI woke up to the ";

    cout << "Please enter another Adjective: ";
    getline(cin, temp);

    story += temp + " smell of ";

    cout << "Please enter a Type of Bird: ";
    getline(cin, temp);

    story += temp + "\nroasting in the ";

    cout << "Please enter a Room in a House: ";
    getline(cin, temp);

    story += temp + " downstairs.\nI ";

    cout << "Please enter a Verb (Past Tense): ";
    getline(cin, temp);

    story += temp + " down the stairs to see if I could\nhelp ";

    cout << "Please enter a Verb: ";
    getline(cin, temp);

    story += temp + " the dinner. My Mom said, \"See if ";

    cout << "Please enter a Relative's Name: ";
    getline(cin, temp);

    story += temp + "\nneeds a fresh ";

    cout << "Please enter a Noun: ";
    getline(cin, temp);

    story += temp + ".\" So I carried a tray of glasses\nfull of ";

    cout << "Please enter a Liquid: ";
    getline(cin, temp);

    story += temp + " into the ";

    cout << "Please enter a Verb (Ending with \"-ing\"): ";
    getline(cin, temp);

    story += temp + " room.\nWhen I got there, I couldn't beleive my ";

    cout << "Please enter a Part of the Body (Plural): ";
    getline(cin, temp);

    story += temp + "!\nThere were ";

    cout << "Please enter a Noun (Plural): ";
    getline(cin, temp);

    story += temp + " ";

    cout << "Please enter a Verb (Ending with \"-ing\"): ";
    getline(cin, temp);

    story += temp + " on the ";

    cout << "Please enter a Noun: ";
    getline(cin, temp);

    story += temp + "!";

    cout << endl;

    //Printing the story.

    cout << "Your final Mad Lib was: " << endl << endl;
    cout << story << endl;

    cout << endl << "Tristan Kirksey - ECGR 2103 - ID: 801286738" << endl;

    return 0;
}