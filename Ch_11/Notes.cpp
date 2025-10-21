

//	CH 11
// Intro to function overloading.
// take trival function:
// 
// int add(int x, int y)
// {
// return x+y;
// }
// 
// this works fine for integers but if we want to have an add function for floating point numbers we
// either have to create a new slightly different named function doing same thing, or use function overloading.
// 
// Function overloading allows us to make multiple functions with teh same name so long as each function has
// different parameter types (or function can otherwise be differentiated) 
// 
// Within the same scope, each function sharing a name is called an IVERLOADED FUNCTION or OVERLOAD for short
// 
// so looking back at ouradd function this is how we could create overloaded functions to add() ints or doubles:
// int add(int x, int y)
// {
// return x+y;
// }
// double add(double x, double y)
// {
// return x+y;
// }
// 
// no naming conflict occurs as the compiler treats the functions as distinct due to difference in parameters
// 
// errors will occur of the overloaded functions are not able to be differentiated OR any function call is unable
// to resolve which overloaded function to use (actually might just mean any suitable overloaded function must exist,
// not sure how ambiuguous calls work yet)
// 
// BEST PRACTICE: use function overloading to make programs simpler (and use alot when it makes sense)
// 
// 


// Function Overloading DIfferentation 
//  the ways in which overloadied functions can be differentiated (be validly distinct from other overloaded functions)
// YES Number of parameters
// YES Type of parameters:
//		Does NOT include type defs,type aliases, or const qualifier on value parameters
//		DOES include; elipses (ch20.5 elipsis and why to avoid)
// NO Return type
// YES const or volitile qualifiers on function
// YES Ref-Qualifiers (not sure what they mean by this yet)
// 
// Overloading by number of parameters
// nothing really to say, compiler has no issue differentiating between add(int x,int y,int z) and add(int x, int y)
// 
// Overloading by type of parameters
// so long as the list of paramaters is different between functions, lthey are diferentiated EG.
// int add(int, int)
// double add(double, double)
// double add(int, double)
// double add(double, int)
// 
// all 4 are distinct overloads
// 
// however	int foo(int)
// and		int foo(const int)
// are NOT differentiated
// 
// BECAUSE Return type is not used to differentiate, 
// somethinglike 
// int getrandvalue()
// double getrandvalue()
// does not work ane we qwould need 
// int getrandint()
// double getranddouble()
// 
// this weakness is intentional so that humans reading can always tell with minimal anaysis which overload is being called
// 
// 
// TYPE SIGNATURE
// a functions type signature or just SIGNATURE, is defined as teh parts of the funct header that are used for
// differentiation of the funct. (function name, #of paramaters, paramater type, function level qualifiers)
// 
// 
// Name Mangling
// compiler litteraly mangles names when compiling to ensure each has a unique name for example:
// int fcn() could be mangled to __fcn_v where int fcn(int) might be __fcn_i, but each compiler mangles names in its
// own method as there is no enforeced standard
// 



//  Function Overload Resolution and Ambiguous Matches
// 
// Overload Reselution is the process of matching a function call to the overload of best match
// 
// the steps for resolving a function call which calls to one of several overloaded functions are done in order
// and after each step teh compiler checks for matches with one of 3 ourcomes
// 1 no matching functions were found, move onto next step
// 2 single matching function found, now cinsidered best matchm no more steps
// 3 More than one matching function found, ambigous match -> compile error 
// 
// If the compiler reaches the end of the conversion steps without a match it also throw an error for no 
// matching function
// 
// 
// The Argument Matching Sequence
// 
// 1) check for exact match
//		1.check if is exact match
//		2.make trivial conversons such as lvalue to rvalue, const to non-const, non-reference to reference
//	(Trivial conversions are considered exact matches which means there is an ambiguous match when diferentiating
//	 between int and const int for example)
// 
// 2) If no exact match, try to find one by applying numeric promotions
// 
// 3) If no match, attempt numeric conversions
//		
// 4) if still no match, attempt user defined conversions
//			(after applying user defined conversions, implicit conversions will be attempted asawell 
//			such as char to int)
// 
// 5) if no match after user defined, compiler looks for matching functions with elipsis
// 
// 6) If no matches, throw a compile error
// 
// 
// Ambigous Matches
// unlike non ovberloaded functions, overloads have three posible outcomes of compiling each call.
// Non-Overload has match found or no match error, but overloads can also have ambiguous matches
// 
// An ambiguous match occurs when there are multiple functions that can be made to match within the same
// step of the matching sequence, when this happens the compiler will issue a compile error
// 
// this can happen if say a function call matches two distinct overloads during the  numeric conversion stage
// (A call with a Long cant promote but can convert to Int or Double)
// [This is why its important to know what fundamental types convert to what and if its promotion or conversion]
// 
// 
// Resolving Ambiguous Matches
// 1) Just define a new overloaded function that takes the exact parameters you are calling with 
// 2) alternativly make the call explicit such as with static cast to match the call param with the intended function
// 3) If argument is litteral, can use a litteral suffix to same effect
// 
// 
// Matcing For Functions With Multiple Arguments
// the compiler will execute matching sequence for each argument in turn, teh chosn function is the one where 
// every argument matches atleast aswell asa every other function and has atleast one argument that matches better 
// than the others
// if no such function is found teh match is ambiguous
// (for example if a call has an int and a float and teh options are int int ot float float its abmiguous
// because each otption has one argument that matches better than the other and one argument that does not
// match atleast aswell as all other functions)
//
// 



// Deleting Functions
// it is possible to write functions that dont work as desired with certain value types
// for example printInt is probably not intended to take 'a' as an argument and ouput 97 to screen
// 
// to prevent misuses of a function you can use the delete specifier. 
// 
// void printInt(char) = delete ;
// void printInt(bool) = delete ;
// void printInt(int x)
// {stufs};
// 
// this causes the compiler to treat the functions as if they had been deleted and throw an error when a call
// matches a deleted function.
// (= delete means forbidden, not non existant)
// 
// this can cause issues though where function calls may be treated as ambiguous because they could match with a 
// = delete function or the intended function
// EG printInt(5.0) would match to int or either of the deleted functions, so compile error thrown
// 
//
// Delete All Non-Matching Overloads
// deleting one at a time is verbose, so instead we can use function templates (11.6 (two sections from now))
// 
// Sneak peak:
// void printInt(int x) //takes precedence for int argument calls
// template <typename T>;
// void printInt(T x) = delete; // takes precedence for all other argument types.
// 
// 



// Default Arguments
// a default argument is the default value for a function if an argument is not given by the caller
// syntax: 
// void foo(int x, int y=10);
// 
// foo(7,11); //default vaue for y overwritten with user-suppllied argument 11 
// 
// foo(5); // x is 5 but due to no argument being given, y defaults to 10
// 
// Default values are handled by the compiler at the call site. 
// so in the above, compiler re-wrote the second call as 
// foo(5, 10);
// 
// default arguments have tons of uses such as adding a new parameter to a function without
// breaking all previous calls
// 
// 
// Multiple Default Arguments
// multiple arguments can have default values in c++
// however the left most values are checks for first and
// as on c++23 there is no syntax for defaulting a value then being explicit for a value to its right
// EG 
// foo(int x=1, inty=2, int z=3);
// foo(4); //valid, just uses default for x and y
// foo(,,4) // invalid, there is no way to have x be default value while giving exp;licit value to y or z
// 
// as such here are 3 Major consequences:
// 
// 1) an explicitly called arguments must be the left most arguments
// 
// 2) if an argument is given a default value, all values to the right must also have default values
// 
// 3) if more than one argument has a default value, the leftmost should be the one most likely to be
// given an explicit value by user
// 
// 
// Default Arguments Cannot Be Redeclared and Must be Declared Before Use
// 
// error thrown if function call relying on defualt value used before default value listed
// error thrown if default value is ever redefined (even as same value)
// 
// 
// Best Practice: is to put default values in the forward declaration and not the definition, 
// unless the unction has no forward declaration
// 
// (added benifit of making sure other files see the default value esp if its in a header file)
// 
// 
// Default Arguments and Function Overloading
// functions with default arguments are allowed to be overloaded
// EG
//#include <iostream>
//#include <string_view>
//
//void print(std::string_view s)
//{
//    std::cout << s << '\n';
//}
//
//void print(char c = ' ')
//{
//    std::cout << c << '\n';
//}
//
//int main()
//{
//    print("Hello, world"); // resolves to print(std::string_view)
//    print('a');            // resolves to print(char)
//    print();               // resolves to print(char)
//
//    return 0;
//}
// Default values are NOT a part of a functions signature.
// 
// this ofcourse can lead to problems such as in teh case of
// 
// void print(int x);                  // signature print(int)
// void print(int x, int y = 10);      // signature print(int, int)
// void print(int x, double y = 20.5); // signature print(int, double)
// 
// 
// 
// 
// 
//