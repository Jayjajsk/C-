#include "boxcontainer.h"

char encrypt(const char& param){ // Callback function
    return static_cast<char> (param + 3);
}

char decrypt(const char& param){ // Callback function
    return static_cast<char> (param - 3);
}


std::string & modify(std::string& str_param,
                                        char(* modifier)(const char&))
{
     for(size_t i{} ; i < str_param.size() ; ++i){
        str_param[i] = modifier(str_param[i]); // Calling the callback
     }
     return str_param;
}

//Modifying a BoxContainer of strings
BoxContainer<std::string>& modify(BoxContainer<std::string>& sentence,
                                        char(*modifier) (const char&)){
    for(size_t i{}; i < sentence.size() ; ++i){
            
        //Code below relies on get_item() to return a reference
        //Loop through the word modifying each character 
        for(size_t j{} ; j < sentence.get_item(i).size(); ++j){
            sentence.get_item(i)[j] = modifier(sentence.get_item(i)[j]);
        }
    }
    return sentence;
}


//Using syntax
using str_comparator = 
    bool(*)(const std::string& str1, const std::string& str2);

//With typedefs
//typedef bool(*str_comparator) (const std::string& str1, const std::string& str2);

std::string get_best (const BoxContainer<std::string>& sentence,
                        str_comparator comparator){

    std::string best = sentence.get_item(0);
    for(size_t i{}; i < sentence.size() ; ++i){
            
        if(comparator(sentence.get_item(i),best)){
            best = sentence.get_item(i);
        }
            
    }
         
    return best;
}


bool larger_in_size (const std::string& str1, const std::string& str2){
    if(str1.size() > str2.size())
        return true;
    else 
        return false;
}

bool greater_lexicographically(const std::string& str1, const std::string& str2){
    return (str1>str2);
}


int main(){

    std::string msg{"Hello"};
    modify(msg,encrypt);
    fmt::println( "outcome : {}" , msg );

    fmt::println( "------" );

    BoxContainer<std::string> quote;
    quote.add("The");
    quote.add("sky");
    quote.add("is");
    quote.add("blue");
    quote.add("my");
    quote.add("friend");
    fmt::println( "Initial : {}" ,  quote );
    fmt::println( "Encrypted : {}" , modify(quote,encrypt) );
    fmt::println( "Decrypted : {}" , modify(quote,decrypt) );


    fmt::println( "-------" );

    str_comparator callback{larger_in_size};

    fmt::println( "larger in size : {}" , get_best(quote,callback) );
    fmt::println( "greater lexicographicaly : {}" , get_best(quote,greater_lexicographically) );


   
    return 0;
}