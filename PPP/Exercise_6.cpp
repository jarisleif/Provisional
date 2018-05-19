/*
Exercise 6, Chapter 11, from
Stroustrup, B. Programming: Principles and Practice Using C++, 2nd Ed.
Compiled on GCC 5.2.1 (Ubuntu 15.10)
Line 30 produces the "multi-character character constant" compiler
warning; without it, the code compiles seamlessly, but the task
assumes the removal of all punctuation symbols. The executable
functions OK.
*/

#include "../std_lib_facilities.h"

//enables and disables the switch(ch), line 21
bool no_punct(int count) {
    if (count == 1) return false;
    return true;
}

//reads characters, turns punctuation into spaces, and writes characters
void dump_punctuation(ifstream& ifs, ofstream& ofs) 
{
    char previous;
    char quote = '"';
    int qu_count = 0;
      
    for(char ch; ifs.get(ch);) { //read characters
        
        switch(ch) {
            case '.': case ',': case ':': case ';': case '!':
            case '?': case '(': case ')': case '–': case '—':
                if (no_punct(qu_count)) ch = ' ';
        }
        
        if(!(previous == ' ' && ch == ' ')) ofs << ch; //write characters
        
        //turns the 'no_punct' to 'false' or 'true'
        if (ch == quote && qu_count == 2) qu_count = 1;
        if (ch == quote && (qu_count == 0 || qu_count == 1)) ++qu_count;
        if(qu_count > 2) error("something happened to the quotation marks counter");
        
        previous = ch; //remembers the preceding character
    }  
}

int main()
try {
    //establish input and output streams
    string get_text;
    string write_text;
    
    //create input stream
    cout << "Hi, enter the name of punctuated file:\n"; 
    cin >> get_text;
    ifstream get {get_text};
    if(!get) error("input file didn't open");
    
    //create output stream
    cout << "Now create a non-punctuated file by entering its name:\n"; 
    cin >> write_text;
    ofstream write {write_text};
    if(!write) error("output file didn't open");
    
    //read, proccess, and write the text
    dump_punctuation(get, write);
}
catch(exception& e) {
    cerr << "Error: " << e.what() << ".\n";
}
catch(...) {
    cerr << "Oops, some unknown error occurred!\n";
}