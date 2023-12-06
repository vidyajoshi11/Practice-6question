#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;
    int length;

public:
    // Constructor
    MyString(const char* s = "") {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Destructor
    ~MyString() {
        delete[] str;
    }

    // Equality (=) operator overloading
    void operator=(const MyString& s) {
        delete[] str;
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    // String Copy (==) operator overloading
    void operator==(const MyString& s) {
        delete[] str;
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    // Concatenation (+) operator overloading
    MyString operator+(const MyString& s) {
        MyString newString;
        newString.length = length + s.length;
        newString.str = new char[newString.length + 1];
        strcpy(newString.str, str);
        strcat(newString.str, s.str);
        return newString;
    }

    // Display a string (<< operator overloading)
    friend std::ostream& operator<<(std::ostream& os, const MyString& s) {
        os << s.str;
        return os;
    }

    // Reverse a string (>> operator overloading)
    friend std::istream& operator>>(std::istream& is, MyString& s) {
        char temp[1000];
        is >> temp;
        int len = strlen(temp);
        s.length = len;
        s.str = new char[len + 1];
        for (int i = 0; i < len; ++i) {
            s.str[i] = temp[len - i - 1];
        }
        s.str[len] = '\0';
        return is;
    }

    // Function to determine whether a string is a palindrome
    bool isPalindrome() {
        int start = 0;
        int end = length - 1;
        while (end > start) {
            if (str[start] != str[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }

    // Function to find the occurrence of a sub-string
    int findSubString(const char* sub) {
        int subLen = strlen(sub);
        for (int i = 0; i <= length - subLen; ++i) {
            bool found = true;
            for (int j = 0; j < subLen; ++j) {
                if (str[i + j] != sub[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1; // Substring not found
    }
};

int main() {
    MyString s1("Hello"), s2("World"), s3;

    // Equality
    s3 = s1;
    std::cout << "Equality (=): " << s3 << std::endl;

    // String Copy
    s3 == s2;
    std::cout << "String Copy (==): " << s3 << std::endl;

    // Concatenation
    MyString s4 = s1 + s2;
    std::cout << "Concatenation (+): " << s4 << std::endl;

    // Display a string
    std::cout << "Display a string (<<): " << s1 << std::endl;

    // Reverse a string
    std::cout << "Enter a string to reverse (>>): ";
    std::cin >> s1;
    std::cout << "Reversed string: " << s1 << std::endl;

    // Check for palindrome
    if (s1.isPalindrome()) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    // Find occurrence of a sub-string
    const char* sub = "llo";
    int index = s1.findSubString(sub);
    if (index != -1) {
        std::cout << "Substring '" << sub << "' found at index " << index << std::endl;
    } else {
        std::cout << "Substring '" << sub << "' not found." << std::endl;
    }

    return 0;
}
