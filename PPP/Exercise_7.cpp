/*
Exercise 7, Chapter 11, from
Stroustrup, B. Programming: Principles and Practice Using C++, 2nd Ed.
Compiled on GCC 5.2.1 (Ubuntu 15.10)
Line 31 produces the "multi-character character constant" compiler
warning; without it, the code compiles seamlessly, but the task
assumes the removal of all punctuation symbols. The executable
functions OK.
*/

#include "../std_lib_facilities.h"

//enables and disables the switch(ch), line 31
bool no_punct(int count) {
    if (count == 1) return false;
    return true;
}

//processes word letter by letter
string clean_word(string w, int& count)
{
    char quote = '"';
    string new_word; //word to be returned
    istringstream letters {w};
    if(!letters) error("the input string stream in the clear_word() didn't open");
    
    for(char ch; letters >> ch;) { //read letters
        switch(ch) {
            case '.': case ',': case ':': case ';': case '!':
            case '?': case '(': case ')': case '–': case '—':
                if (no_punct(count)) ch = ' '; //if not quoted, replace punctuation with spaces
        }
        
        if (ch == quote && count == 2) count = 1;
        if (ch == quote && (count == 0 || count == 1)) ++count;
        if (count > 2) error("something happened to the quotation marks counter");
        
        new_word += ch;
    }
    
    if(new_word == "don't") new_word = "do not";
    if(new_word == "doesn't") new_word = "does not";
    if(new_word == "can't") new_word = "cannot";
    if(new_word == "aren't") new_word = "are not";
    if(new_word == "isn't") new_word = "is not";
    if(new_word == "there's") new_word = "there is";
    if(new_word == "there're") new_word = "there're";
    if(new_word == "hasn't") new_word = "has not";
    if(new_word == "haven't") new_word = "have not";
    if(new_word == "shouldn't") new_word = "should not";
    if(new_word == "mustn't") new_word = "must not";
    if(new_word == "wouldn't") new_word = "would not";
    if(new_word == "won't") new_word = "will not";
    if(new_word == "didn't") new_word = "did not";   
    
    return new_word;
}

//reads line from a file, then word from the line
void ditch_punctuation(ifstream& ifs, ofstream& ofs)
{
    int qu_count = 0;//quotation marks counter
    for(string line; getline(ifs, line);) { //read lines
        string word;
        istringstream wrd {line};
        if(!wrd) error("the input string stream in the ditch_punctuation() didn't open");
        while(wrd >> word) { // read words
            
            word = clean_word(word, qu_count); //processes the word
            ofs << word; //
            if(word[word.length()-1] != ' ') ofs << ' ';
        }
        ofs << '\n';
    }
        
}

int main()
try {
    //establish input and output streams
    string get_text;
    string write_text;
    
    cout << "Hi, enter the name of punctuated file:\n"; //create input stream
    cin >> get_text;
    ifstream get {get_text};
    if(!get) error("input file didn't open");
    
    cout << "Now create a non-punctuated file by entering its name:\n"; //create output stream
    cin >> write_text;
    ofstream write {write_text};
    if(!write) error("output file didn't open");
    
    //read, proccess, and write the text
    ditch_punctuation(get, write);
}
catch(exception& e) {
    cerr << "Error: " << e.what() << ".\n";
}
catch(...) {
    cerr << "Oops, some unknown error occurred!\n";
}