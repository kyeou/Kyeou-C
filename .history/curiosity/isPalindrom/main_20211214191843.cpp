#include <iostream>

bool isPalindrome(std::string word);

int main() {
std::string tw = "hannah";
if (isPalindrome(tw) == true) {
std:: cout << "true" << std::endl; 
} else {
    std::cout << "false" << std::endl;
}
return 0; 
}

bool isPalindrome(std::string word) {
int length = word.length();
//std::cout << length << std::endl;
for (int i = 0; i < (length/2); i++) {
   // std::cout << i << std::endl;
if (word.at(i) != word.at(length - i -1)) {return false; }

} //end for

return true;
}