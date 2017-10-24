#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void isPalindrome(string x, bool case_sens, bool dont_ignore_spaces) {
    //base case
    if(x.size() == 1 ){  
        cout << "true" << endl;
    } else {
        if(!case_sens && !dont_ignore_spaces){
            //remove spaces
            std::string::iterator end_pos = std::remove(x.begin(), x.end(), ' ');
            x.erase(end_pos, x.end());
            //toLower
            std::transform(x.begin(), x.end(), x.begin(), ::tolower);

            if (x.at(0) == x.at(x.size()-1)) {
                isPalindrome(x.substr(1,x.size()-2),false,false);
            } else {
                cout << "False" <<endl;
            }
        }
    }
}
void printUserInfo(string str) {
    /*
    Usage: ./palindrome [-c] [-s] string ...
    -c: case sensitivity turned on
    -s: ignoring spaces turned off
    */
    cout << "Usage: " << str << "[-c] [-s] string ..."<<  endl;
    cout << "-c: case sensitivity turned on" << endl;
    cout << "-s: ignoring spaces turned off" << endl;
    return;
}
int main(int argc, char *argv[]) { 
    if(argc == 1) {
        printUserInfo(argv[0]);
    } else {
        bool case_sensitive = false;
        bool ignores_spaces = true;
        for(int i=1;i<argv.size(); i++) {
            std::transform(x.begin(), x.end(), x.begin(), ::tolower);
            argv[i] = argv[i];
            if(argv[i].find("s"))
        }
    }
    
    //cout << str;
    if(argc > 1) {

    }
    return 0 ;
}