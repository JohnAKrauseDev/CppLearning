// Review
// 
// implicit type conversion (also automatic or coercion) done by engine when one data type expected but other provided
// 
// Standard Conversions- built in conversion between fundamental tyes and some sdvanced types, 
//		includes:numeric promotions, numeric conversions, and arithmatic conversions
// 
// Numeric promotion- conversion of certain smaller numeric tyoes to larger types (ie int to double) so the
//		cpu can run on its most efficient data  type
//		NP are value preserving
// 
// Numeric conversion- conversion between fundamental types that arent promotion. 
//		can be narrowing which is not value preserving
// 
// if binary operator requires both types be same then uses usual arithmatic conversion
// 
// Explicit type conversion performed by programmer explicitly requesting the conversion
//		6 types of casts: c-style, static, constm dynamic, and reinterpret casts.
//		Generally we avoid using any cast but static.
// 
// Typedefs and type aliases allow programer to create alias for data type, to the compiler however there are no
//		differences between an alias and its underlying type
// 
// Auto keyword can be used for type deduction (aka type inference), which deduces a variables type from its initializer, 
//		auto drops const and constexpr so must re add it if desired
// 
// auto can be used as a function return type  to infer fom return statement but is generally used for
//		trialing return syntax
// 





// What type of conversion happens in each of the following cases? Valid answers are: No conversion needed,
// numeric promotion, numeric conversion, won’t compile due to narrowing conversion. Assume int and long 
// are both 4 bytes.
// 
/*
int main()
{
    int a{ 5 }; // 1a
    int b{ 'a' }; // 1b
    int c{ 5.4 }; // 1c
    int d{ true }; // 1d
    int e{ static_cast<int>(5.4) }; // 1e

    double f{ 5.0f }; // 1f
    double g{ 5 }; // 1g

    // Extra credit section
    long h{ 5 }; // 1h

    float i{ f }; // 1i (uses previously defined variable f)
    float j{ 5.0 }; // 1j

}
*/
// 1a: No conversion
// 1b: numeric promotion
// 1c: Narrowing Conversion
// 1d: Numeric Promotion
// 1e: No conversion (other than the explicit numeric conversion)
// 
// 1f: Numeric promotion
// 1g: Numeric Conversion
// 
// 1h: * numeric conversion into to long (is trivial but still conversion)
// 1i: Narrowing
// 1j: *Numeric conversion double to float (allowed as 5.0 is const expr and in range



// Update the following program to use type aliases for degrees and radians values:
#include <iostream>

namespace constants
{
    constexpr double pi{ 3.14159 };
}

using Degrees = double;
using Radians = double;

Radians convertToRadians(Degrees d)
{
    return d * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    Degrees d{};
    std::cin >> d;

    Radians r{ convertToRadians(d) };
    std::cout << d << " degrees is " << r << " radians.\n";

    return 0;
}
// Given the definitions for degrees and radians in the previous quiz solution, explain 
// why the following statement will or won’t compile:
// 
//radians = degrees;
// 
// will compiler because the compiler does not distinguish aliases as a unique type and treats them the same as
// their underlying type
// 
// 
// 
// 
// 
// 
//