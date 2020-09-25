using namespace std;
#include <iostream>

class String
{
    char*    data;    /*!< The ASCII characters that comprise the String */
    unsigned length;  /*!< The number of characters allocated in data */

public:

    /*! 
     *  @brief Empty String Constructor.
     *  @post String length is set equal to 0.
     */
    String ( ); // constructor overloading

    /*! 
     *  @brief Single-character String Constructor.
     *  @param[in] c A char literal.
     *  @post String data equals @a c and String length equals 1.
     */
    String (char c);

    /*! 
     *  @brief char* String Constructor
     *  @param[in] c A char* null-terminated string.
     *  @post String length equals @code{.cpp}strlen(c)@endcode.
     *  @post String data equals @a c allocated values, except the null-terminator.
     */
    String (const char* c);

    /*! 
     *  @brief Copy String Constructor
     *  @param[in] s A String instance.
     *  @post This String will be identical to String @a s.
     */
    String (const String& s);

    /*! 
     *  @brief Default String Destructor
     *  @post String data is deleted.
     */
    ~String ( );

    /*! 
     *  @brief String length.
     *  @return Value in String @c length.
     */
    unsigned len ( ) const;

    /*! 
     *  @brief String index of @a c.
     *  @param[in] c A char literal.
     *  @return The index of @a c in String, if exists; -1 otherwise.
     */
    int index (char c) const;
    
    char get(unsigned j) const;
    
    String& append(char c);
    //@{
    /*! 
     *  @brief Stream operators.
     *  @param so A stream object.
     *  @param s  A String object.
     *  @return Stream object containing String content.
     */
    // friend std::ostream& operator<< (std::ostream& so, const String& s);
    // friend std::istream& operator>> (std::istream& so,       String& s);
    //@}

    //@{
    /*! 
     *  @brief Access String character.
     *  @param j Index value in String.
     *  @pre @a j is less than String length.
     *  @return character at @a j index of String data.
     *  @throw int
     */
    // char  operator[] (unsigned j) const;
    // char& operator[] (unsigned j);
    //@}

    /*! 
     *  @brief Sets String value.
     *  @param[in] s A String object.
     *  @return A String reference to *this.
     *  @post String will be equivalent to @a s.
     */
    // String& operator= (const String& s);   
    
    // String& operator+= (const String& s);
    
    
};

//===================================================================================string.cpp=====================================================================

String::String (){
    length = 0;
    data   = new char[0];
}
String::String (char c){
    length = 1;
    data   = new char(c);
}
String::String (const char* c){
    if (c){
        unsigned n = 0;
        while (c[n] != '\0') n++;
        length = n;
        data   = new char[n];
        for (unsigned j=0; j < n; j++)
            data[j] = c[j];
    } 
    else{
        length = 0;
        data   = new char[0];
    }
}

String::String (const String& s){
    length = s.len();
    data   = new char[length];
    for (unsigned j=0; j < length; j++)
        data[j] = s.data[j];
}
String::~String (){
    delete[] data;
}

unsigned String::len () const{
    return length;
}

int String::index (char c) const{
    for (unsigned j=0; j < length; j++)
        if (data[j] == c) return (int)j;
    return -1;
}
char String::get(unsigned j) const{
    if (j >= length) throw 1;
    return data[j];
}
String& String::append(char c){
    char* str = new char[length + 1];
    for (unsigned j=0; j < length; j++)
        str[j] = data[j];
    str[length] = c;
    delete data;
    length += 1;
    data   = str;
    return *this; 
    

}
    

// std::ostream& operator<< (std::ostream& os, const String& s){
//     if (s.len() > 0){
//         for (unsigned j=0; j < s.len(); j++)
//             os << s[j];
//     } 
//     else os << "";
//     return os;
// }

// std::istream& operator>> (std::istream& is, String& s){
//     char* c = new char[1000];
//     is >> c;
//     s = String(c);
//     delete[] c;    
//     return is;
// }

// char String::operator[] (unsigned j) const{
//     if (j >= length) throw 1;
//     return data[j];
// }

// char& String::operator[] (unsigned j){
//     if (j >= length) throw 1;
//     return data[j];
// }
// String& String::operator= (const String& s){
//     if(this == &s) return *this;

//     delete data;
//     length = s.len();
//     data   = new char[length];
//     for (unsigned j=0; j < length; j++)
//         data[j] = s[j];
//     return *this;
// }
// String& String::operator+= (const String& s){
//     unsigned len = length + s.len();
//     char*    str = new char[len];

//     for (unsigned j=0; j < length; j++)
//         str[j] = data[j];

//     for (unsigned i=0; i < s.len(); i++)
//         str[length+i] = s[i];

//     delete data;
//     length = len;
//     data   = str;
//     return *this;    
// }



int main(){
    
    char* c = "abcd";    
    String s1(c),s2('e'),s3;
    // s1 += s2;
    // cout<<s1<<endl;
    cout<<s1.len()<<endl;
    // cout<<s1[1]<<endl;
    cout<<s1.get(0)<<endl;
    s1.append('x');
    cout<<s1.get(s1.len()-1)<<endl;
    // try{
    //     cout<<s1[5]<<endl;
    // }
    // catch (int e){
    //     cout << "Error " << e << ": Index out of bounds" << endl;
    // }
    
    return 0;
    
}
    





