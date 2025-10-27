

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
// this of course can lead to problems such as in the case of
// 
// void print(int x);                  // signature print(int)
// void print(int x, int y = 10);      // signature print(int, int)
// void print(int x, double y = 20.5); // signature print(int, double)
// 
//	
// Default Arguments Dont Work For Functions Called Through Function Pointers
// covers fully in Fuinction Pointers 20.1
// Default arguments care not considered when using this method, thjis also provides a workaroound 
// to call a function that would otherwise be ambiguous due to default arguments
// 




// Function Templates
// 
// function templates are meant to solve teh problem of havingt a function that is identical for
// many inpout types that you dont want to create independant overloads for each possible type
// such as a compare function that we want to use for all floating and integer types
// 
// 
// Introduction to C++ templates
// 
// just like normal defenition, templates definition describes what a fuinction or class looks like
// but, rather than needing each type to be specified, in a template you can use one or more placeholder
// types. a placeholder type is one who is not yet known at definiton but will be provided later when
// template is used.
// once a template is defined the compiler generates as many overloaded functions or classes as needed,
// each using different actuall types
// 
// [in essence templates is a short hand for multiple identical overloaded functions]
// a template is used by compiler to create a family of relatede functions or classes 
// 
// the original function template that generates all the overloads is called the Primary Template
// and fucntions generated from it are called Instantiated Functions
// When we create a Primary Funcition Template we use Placeholder Types (aka Type Template Parameters)
// (informally Template Types) for any parameter types, return types, or types used in the function body
// that we want to be specified later by the template user
// 
// C++ supports 3 types of template parameters:
// Type Template Parameters (Template Param represents a type)
// Non-Type Template Parameters (Template Param represents constexpr value)
// template Template Parameters (template Param representsa temlate
// 
// 
// Converting function to template:
// Original
// int max(int x, int y)
// {
//	return (x<y) ? x:y;
// };
// 
// Step 1
// T max(T x, T y)
// {
//	return (x < y) ? y:x
// };
// 
// though without defining T this will result in cpmpile error, and teh fiunction is not seen as a template
// 
// Step 2
// template <typename T> //this is teh declaration for template Parameter
// 
// NOTE: a template parameter declaration is strictly limited to the function or class template that follows
// so every template requires its own template parameter declaration
// 
// teh syntax for Template Paramater Defenition:
// template <typename Name>
// First template to tell compiler what we are doing, then inside angled brackets, typename (or class) before
// teh name of teh template, can do this multiple times in one set ofr brackets i believe
// 
// either calss or typename keywords work in this context, though many use class because it was introduced
// to the language earlier
// 
// 
// Naming Tmeplate Parameters
// much like single letter variables used for trivial situations, its conventional to use a single capital
//  letter as the name for template parameters (Starting with T) atleast when they are used in trivial or
// obviou ways such as the above max() function
// 
// When teh template Parameter has a non-opbvoius usage or specific requierments that must be met, there are
// two common naming conventions:
// Start with capital letter EG Allcator
// Prefix with T then start with capital EG TAllocator
// 
// whether a template function compiles or not is dependant on if the template arguments mach the use in the
// template defenition
// 



// Function Template Instantiation
// 
// as functio ntemplates are not actually functions, to use them we dont make a normal function call
// 
//what we do is similar but we use slightly different syntax
// for example with our max functionabove:
// max<int>(1,2);
// in teh angled brackets we tell the template what type to use when generating a functoin from the template
// 
// the process of creating functions with specified typw from function templates is called
// Function Template Instantiation, or just Instantiation for short
// 
// a functiuon instantiated from a function call is called an Implicit INstantialization
// 
// A function instantiated from a template is Techincally called a Specialization, but is commonly
// refered to as a Function Instance. 
// 
// The template from which a specialization is produced is  caled a Primary Template, 
// 
// Specialization is normally used to rtefer to Explicit Specialization (function Template Specialization 26.3)
// 
// a function template is only instantiated the first time a function ca;; is made (per translation unit)
// further calls just route through the existing function instance (Specialization)
// 
// 
/*
#include <iostream>

template <typename T>
T max(T x, T y) // function template for max(T, T)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n';    // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n';    // calls already instantiated function max<int>(int, int)
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double)

    return 0;
}
*/
// Pre instantiation^
// Post instantiation?
/*
#include <iostream>

// a declaration for our function template (we don't need the definition any more)
template <typename T>
T max(T x, T y);

template<>
int max<int>(int x, int y) // the generated function max<int>(int, int)
{
    return (x < y) ? y : x;
}

template<>
double max<double>(double x, double y) // the generated function max<double>(double, double)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n';    // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n';    // calls already instantiated function max<int>(int, int)
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double)
                                            // the int values provided will be converted to double

    return 0;
}
*/
// 
// 
// Template Argument Deduction
//  
// usually when we use a function call to a templates, the actual type we use is the same as the function
// argumetns we use
// 
// in these cases we can dedutce teh actual type rather then explicitly stating it
// that would look like going from this:
// std::cout<< max<int>(1,2);
// to this:
// std::cout<< max<>(1,2);
// OR
// std::cout<< max(1,2);
// 
// this is called Template Argument Deduction
// regaurdless of which form we use teh compiler notices teh missing actual type so it attempts to deduce
// actual type from teh function aruments
// 
// -the case without the angled brackets, the compiler witll search both template overloads and non-template
//       overloads of max() for a match, if multiple matches found, the non template version prefered
// -the andgled bracket case only looks for template overloads 
// 
// Generally we use normal function syntax to call function templates because of these reasons:
// The syntax is more concise.
// It’s rare that we’ll have both a matching non - template function and a function template.
// If we do have a matching non - template function and a matching function template, we will usually prefer the 
// non - template function to be called.
// 
// 
// 
// 
// 
// 
// 
//