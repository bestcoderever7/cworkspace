#pragma once

struct String{
    static const unsigned char INITIAL_BUFFER_SIZE = 255;
private:
    // 1.
    // Three (3) private member variables are needed.
    // -a char pointer that will point to the first character in the string.
    // -an unsigned int to keep count of how many characters are in the string.
    // -an unsigned long to keep the size of the allotted space for the string in memory (known as the buffer). 
    char* firstChar;
    unsigned int chars;
    unsigned long buffer;

    // 2.
    // the getLengthOfCharString function is a private helper function that 
    // returns the number of chars (bytes) before v points to the
    // null termination character '\0';
    unsigned int getLengthOfCharString(const char* v) {
        //printf("%s", "getLength");
        int num = 0;
        while(*v != '\0'){
            v++;
            num++;
        }
        return num;
    }

public:
    // 3.
    // the default constructor initializes the member variables
    // the buffer size should be initialized to the INITIAL_BUFFER_SIZE
    // the char pointer should point to a new char array that is the size of the buffer
    // the character count is 0
    String() {
        //printf("%s", "const1");
        buffer = INITIAL_BUFFER_SIZE;
        firstChar = new char[buffer];
        chars = 0;
    }

    // 4.
    // this constructor initializes this string object with the data 
    // referenced by the char pointer
    String(const char* v){
        
        //printf("%s", "const2");
        // 4a: get the length of v
        int length = getLengthOfCharString(v);
        // 4b: if that length is less than the initial buffer size,
        //     initialize the char pointer member variable to point at 
        //     a new char array that is the size of the initial buffer size.
        //     Also, initialize the buffer size variable.
        if(length < INITIAL_BUFFER_SIZE) {
            firstChar = new char[INITIAL_BUFFER_SIZE];
            buffer = INITIAL_BUFFER_SIZE;
        }
        // 4c: otherwise, initialize the char pointer to point at a new
        //     char array that is the size of v's length * 2.
        //     This is to give our string room to grow without having to 
        //     reallocate memory as often.
        else {
            firstChar = new char[length * 2];
        }
        // 4d: initialize the char count variable to equal the length of v.
        chars = length;
        // 4e: copy the characters from v into the char array pointed to by the 
        // member variable (for loop)
        for(int i = 0; i < length; i++) {
            firstChar[i] = v[i];
        }
    }

    // 5.
    // This constructor copies the passed in string to this string. Since it is
    // being passed by reference, we have access to its private member variables.
    String(const String& s){
        //printf("%s", "const3");
        // 5a: Initialize the char count and buffer size variables to match those of s.
        this->chars = s.chars;
        this->buffer = s.buffer;
        // 5b: initialize the char pointer member variable to point at 
        //     a new char array that is the size of the buffer size variable
        firstChar = new char[buffer];
        // 5c: copy the contents from s into the char array
        for(int i = 0; i < getLengthOfCharString(s.firstChar); i++) {
            this->firstChar[i] = s.firstChar[i];
        }
    }

    // 6.
    // The destructor should check if the char pointer is null.
    // If not, delete the array it points to.
    ~String(){
        if(firstChar == 0) {
            delete[] firstChar;
        }
    }

    // 7. 
    // This function appends the contents of v to this string.
    void append(const char* v){
        //printf("%s", "append1");
        // 7a:
        // First, check to make sure that adding the characters
        // to this string won't overflow the buffer.
        // If it will, then we need to reallocate new memory for the string.
        // Don't forget to clean up the old memory and to update the character count.
        int length = getLengthOfCharString(firstChar);
        int lengthV = getLengthOfCharString(v);
        if((length + lengthV) > buffer) {
            char* newArr = new char[length * 10];
            for(int i = 0; i < length; i++) {
                newArr[i] = firstChar[i];
            }
            delete[] firstChar;
            firstChar = newArr;
        }
        for(int i = 0; i < lengthV; i++) {
            firstChar[length + i] = v[i];
        }
        //printf("%s", firstChar);
        //printf("%s", "\n");
    }

    // 8. 
    // This function appends the contents of str to this string.
    void append(const String& str){
        int length = getLengthOfCharString(firstChar);
        int lengthS = getLengthOfCharString(str.firstChar);
        //printf("%s", "append2");
        if((length + lengthS) > buffer) {
            char* newArr = new char[length * 10];
            for(int i = 0; i < length; i++) {
                newArr[i] = firstChar[i];
            }
            delete[] firstChar;
            firstChar = newArr;
        }
        for(int i = 0; i < lengthS; i++) {
            firstChar[length + i] = str.firstChar[i];
        }
    }

    //9. getter function for the length of the string (total chars).
    unsigned int length(){
        //printf("%s", "length");
        return chars;
    }

    //10. getter function that returns the location of the char array
    const char* getCharArray(){
        //printf("%s", "charArray");
        return firstChar;
    }

    //11. function that returns true if v contains all the same characters
    //    as this string
    bool equals(const char* v){
        //printf("%s", "\nequals1\n");
        int lengthV = getLengthOfCharString(v);
        if(lengthV != getLengthOfCharString(firstChar))
        {
            return false;
        }
        else { 
            for(int i = 0; i < lengthV; i++) {
                if(firstChar[i] != v[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    //12. function that returns true if s contains all the same characters
    //    as this string
    bool equals(const String& s){
        //printf("%s", "\nequals2\n");
        int lengthS = getLengthOfCharString(s.firstChar);
        if(lengthS != getLengthOfCharString(firstChar))
        {
            return false;
        }
        else { 
            for(int i = 0; i < lengthS; i++) {
                if(firstChar[i] != s.firstChar[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    String operator+ (String v) {
        String n(*this);
        n.append(v);
        return n;
    }

    void operator+= (String v) {
        this.append(v);
    }
};