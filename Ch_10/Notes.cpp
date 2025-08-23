



// Type Conversion
// 
// implicit type conversion is done by the compiler without being explicitly requested by programmer
// 
// explicit type conversion AKA CASTING is requwested by programmer,
// 
// IMPLICIT TYPE CONVERSION
// also known as automatic type conversion and coercion
// performed automaatically by compiler whe one data type is required but another is supplied
// most often from initiallizing/assigning a variable from a different type of data ie int to float/double
// or when return value is different from functions declared return type
// or certian binary opperations with different types ie 4.0/3
// or using a non bool in an if statement
// or function passed a different type than its parameter
// 
// when type conversoin id invoked the compiler determines if it can convert between the types
// if it cant it will cause a compiler error
// conversions can fail for many resons, for example: 
// compiler doesnt know how to convert between the types
// statment dissalows the conversion (for example int x {3.5} would fail because braces disallow data loss in converion)
// there ar also csaes where the compiler cant decide what type of several possible types to use when it is ambigous
// 
// Standard Conversions - the rules of how types can convert to eachother
// 
// Numeric promotions
// Numeric conversion
// Artithmatic conversions
// Other Conversions
// 
// when a type conversion is needed the compiler looks to standard conversions and can apply 0, 1, or in certain
// cases 2 standard conversions in the process
// (zero is for int to long for example, both have same range and size and bit structure so just copy)



// Floating Point and INtegral Promotion
// 
// Numeric promotion - conversion from a narrower (fewer bits) to a wider type (more bits)
//		often for converting variables to the type most efficient of a given architecture
//		all numeric conversions are value preserving conversions
// 
// Value preserving conversion - aka safe conversion is where every possoble source value can be converted'
//		into an equal value of destination type (think int to  double or int to long)
// 
// bevause promotions are safe conversions, the compiler does not warn and uses them freely
// 
// whith automatic promotion from the compiler we are able togive a function with a paramater, inputs
// with a variable type that can be promoted to the paramaters expected type ie give an int param a short value
// 
// Numeric Promotion comes in two catagorise: integral promotions and floating point promotions
// 
// Floating Point Promotions: floats can be converted into doubles
// this means a function with a double paramater can be called with a float or a double
// 
// Integral Promotion: 
//		signed char or short CAN be converted to int
//		unsigned char, char8_t and unsigned short CAN be converted to int IF int can hold the entire range of 
//			the entire type, or otherwise into unsigned int
//		by default char follows signed or unsigned rule depending on which it is by default
//		Bool can be converted to int with false = 0 and true = 1
// 
// asumming a 8 bit byte and and int size of 4 bytes or larger both signed and unsigned char and short can 
// promote to int (this is the typical size on modern architecture)
// 
// for uncommon types of integral promotion https://en.cppreference.com/w/cpp/language/implicit_conversion#Integral_promotion
// 
// on architecture with 2 byte ints some unsigned integral types will convert to unsinged int rather than int
// 
// not all wideining converstions are numeric promotions
// char to short or int to long are not considered numeric promotions in c++, they are considered numeric conversions
// this is because they dont "assist in goal of converting smaller types to larger for sake of efficient processing"
// 




// Numeric Conversions
// 
// Numeric conversions - these conver additional conversions between fundamental types beyond promotion
// 
// 5 types of numeric converisons:
//	1)	converting any integral type to another integral type (excluding those that count as promotions)
//	2)	converting any floating point to andother floating oint type (excluding those that count as promotions)
//	3)	converting a floating point type to a integral type
//	4)	converting a integral type to a floating point type
//	5)	converting a floating or inegral type to a bool
// 
// NOTE brace intitialization dissalows any non lossless conversions so some of these conversions cannot be done
// with brace initialization and would require copy initialization
// 
// many numeric conversions are "unsafe" meaning they are at riask of loosing data in the conversion
// 
// numerical conversions fall into three catagories of saftey:
//	1)	Value preserving conversion - safe numeric conversions where the  destination type can exactally represent all
//			possible values of source type (ussually not given any warnings) conversion is allways reversable (lossless)
// 
//	2)	Reinterpretive Conversion - unsafe numeric conversion where the value may be diferent but no data is lost
//			think signed to unsigned conversion, data isnt lost but source and destination do not share all same values
//			warnings are disables by default for this bc generally there isnt a value loss
//			even with value loss data is not lost as value will revert upon reverseing the process (reversable)
// 
//	3) Lossy Conversions - conversion where data might get lost
//			double to int is a lossy conversion, the decimal is lost
//			dpuble to float is also lossy as float is narrower/ cant store as many decimal places
//			ie conversion back to original type results in a different value than the original
// 
//		tip: int to double is usually a safe conversion (int typically 4 byte whie double 8) but on architaectures where
//		int and double both have size 8byte it is lossy 
//		std::cout << static_cast<long long>(static_cast<double>(10000000000000001LL));
//		would print 10000000000000000 on those systems
// 
// Unsafe conversions beigng used requs:
//		constrain values to be converted to just those that can be converted to equal values
//			for example int can safely be converted to unsigned in if er garuntee int is not negative
//		or we just dont care about the stst being list such as int to bool because taht conversion is generally becaues
//			we only care if the int is 0 or not
// 
// Most important rules to remember with Numeric Conversions:
//		In ALL cases converting a value into a type whose range soednt support the value the results will be unexpeced
//			for example assigning 3000 to a cahr (-128, 128) will cause char to overflow
// 
//		Unsigned overflow is well-defined but apperantly signed overflow is not garunteed to work the same on 
//			different architectures
// 
//		Converting from a wider to a narrower type in teh same family (ie integral) is gererally safe so long as the
//			value fits withing the new types range
//		
//		In the case of floating point values some rounding may occur due to loss of percision in smaller types
//			(e.g. 
//			float f = 0.123456789;
//			std::cout << std::setprecision(9) << f << '\n';
//			Prints 0.123456791
//			)
// 
//		Conversion from a int type to float type is generally ok so long as teh value is in range 



// Narrowing Conversions, List Initialization, and ConstExpr Intitializers
// 
// Narrrowing Conversion - a potentially unsafe numeric conversion where destination type might not hold all values of 
//		source type
// 
// Narrowing Conversion Types:		
//		Floating point type to integral type
//		floating point type to narrower floating point type unless teh value is constexpr AND is in range of destination
//			type (even if teh destination type doesnt have enoug precision to store all sig digits of num
//		Integral to float type unless the value is constexpr and whose value can be stored exactally in teh destination
//			type
//		Integral type to another integral type that cannot represent all values of original type unless the value is
//			constexpr andcan be stored exactally in destination type. covers both wider to narroeer integral conversions
//			aswell as inegral sign conversions (signed to unsigned or vice versa)
// 
// generally implicit narroeing conversions throw warnings except signed unsigned conversions
// 
// Best Preactice: narrowing conversions can be unsafe and should be avoidedif possible but if it is intentional 
//		make it explicit using static_cast
// 
// In cases where a noarrowing conversion cannot be avoided sucah as function call, make it explicit conversion
//		for self, other devs, and compiler using static_cast
// 
// Brace initialization disallows narrowing conversions
//	this property is main resadon it is the prefered initialiation method
// once again use static cast if you want to convert here intentionally
// 
// 
// Some Constexpr conversions aren't considered narrowing
// if source value isnt known untill runtime, the result cant be determined until runtime. therefore whether the conversion
// preserves the value cant be determines untill runtime
// as such it will issue warnings even ifin practce an error never will occur
// 
// the exception for all the conversion rules was if it was constexpr and fit, that is becaues the compieler can 
// check at compile time if there will be an error with the constexpr value
// 
// NOTE floating point type to int type is allway considered narroeing even if the value fits in range of destination
// 
// NOTE if the floating is constexpr to a narroeier floating it is not considered narrowing even if there is precision
// loss in teh conversion
// 
// the constexpr exception clauses are usefull as they allow for list initalization of most variables with literals 
// while avoiding the need to add literal suffixes or clutter things with static casts
// 
// this is why a narroeing floating to floating conversion is not maked as narrowing (u wont get errors but will
// have percision loss if you init a float with a value beyond its precision
// 



//Arithmatic Conversions
// 
// when an operator requires both operands be the same type, it will cinvert diserate types to a common type and
// the output of the operator wil be of that Common Type. the rules of these conversions are Usual Arithmatic Conversions
// 
// Operators that require operands of the same type:
// Binary Arithmatic: +,-,*,/,%
// Binary Relational: <,>,<=,>=,==,!=
// Binary Bitwise Aritmatic: &, ^, |
// Conditional Operator: ?:  (excluding the conditon expected to be type bool
// 
// Usual Arithmatic Cinversion Rules (simplified):
// tyoe ranking highest to lowest:
// long double
// double float
// long long
// long
// int
// 
// Step 1)
// if one operand is integral and other is floating, the integral is promoted to the floating type of other
// (Otherwise integral operands are numerically promoted) not sure why it says this bc tha hapens in later steps
// maybe it refers to an integral type not on the list is integral promoted to int ie shorts
// 
// Step 2)
// after promotion, if one is signed and other not sprecail rules time
// Otherwise operand with lower rank is converted to higher rank
// 
// Special signed-unsigned rules
// If rank of unsigned is greater or equal to signed, signed is converted to type of unsigned operand
// If type of signed can reoresent all values of the type of the unsigned, unsigned is converted to signed's type
// Else both are converted to corisponding unsigned type of the signed operator
// 
// to find teh comon type of two types, use std::common_type_t<type1, type2>
// 



// Explicit type conversion (Casting, Static_cast)
// 
// when type conversion is needed such as need to set a double to the quotient and remainder of two ints
// unless cast one or both operands to a floating type, it will do int dividion and lose the remainder we want to keep
// 
// Cpp has 5 casting methods (type casting operators):
// C-Style casts, Static Casts, Const Casts, dynamic Casts, reinterprit casts
// all casts work generally the same, take an expression, return a temporary object of teh desired type with converted value
// 
// the difference in casts is what kinds of conversions they are allowed to perform
// 
// C-Style - covered in 25.10
// 
// const Cast, reinterpret cast- usually avoide bc dangerous if misused
// 
// C-Style cast-
//		in standard c programing casts are done with operator()
//		(desired Type)Value
//		still can be found in code converted from C
//		cpp includes a more function stype cast of c style syntax DesiredType(value)
//		c style casts are actually a variety of different conversions including const and reinterpret meaning
//		its possible to it to be misused. produce unexpected behavior, 
// 
// Best Practice : because of the uncertanty dont use c style casts
// 
//		there is one thing c style can do teh others cant, convert a derived object to a base class that is inacessable
// 
// Static Cast- 
//		generally should be used for most values, done with the static_cast keyword
//		static_cast<DesiredType>(value)
// 
//	Important Properties of Static cast: 
//		Provides compile time type checking, if compiler sonest know how to convert it will throw an error
//		It is intentionally "less powerful" than c style cast to prevent dangerous conversions such as reinterpretations
// 
// Best Practice favor static cast unless a specific reason to use a different cast type
// 
// if going to have a narrowing conversion intetntionally, don't so so implicitly, explicitly use static cast to
// make it clear to self and other devs, and prevent warnings
// 
// Casting vs initializing a temp object
// static_cast<int>(x) // returns a temp int object direct initialized with x
// int {x} // returns a twmp int object direct list initialized with x
// 
// int (x) is a c style cast so we should generally avoid it, but
// int {x} uses list init which dissalows narrowing conversions which can be an inpediment 
// when using it intentionally for casts. 
// 
// Direct list init of a temporary ONLY allows Single wourd type names due to a wierd quirk of syntaxes
// Meaning it cant be used for an unsigned int for exapmple unless i make  asingle word alias for 
// unsigned int
// using unit = unsigned int;
// std::cout << uint {x};
// 
// All this to say using static cast, tho often more verbose, is more consistant to use and easier to search
// for with ctrl+f
// 
//



// Typedefs and Type Aliases
// 
// the using keyword creates and aliase for an existing data type (using can also be used for namespace but not advisesd)
// 
// using Distance = double; // define distance as an alias for type double
// 
// this means now i can use Distance in place of the word Double wherever it would be used such as variable init
// Distance milesToDestination{3.4}; // defines a variable of type double
// 
// historically most type aliasing is in three forms:
//		ending in the suffix _t (short for type) often used in standard library for globally scoped type names such as
//			size_t or nullptr_t. originated in c, now out of favor
//		ending in sufix _type. used for some standard library types (std::string::size_type)
//			however, many nested aliases dont use suffix at all. so this suffix is inconsistent
//		type aliases with no suffix, modern convention is to use no suffix but start the name with a capital letter
// 
// Best Practice: name aliases with a capital letter and no suffix unless there is a particular reason to do otherwise
// 
// type asialses are not "type safe" meaning the editor will not throw errors for conversions between teo aliases 
//	that are same type but are supposed to be distinct (think distance and speed both used as aliases for long, 
//	they get the right type for varibles but setting a distance (long) by a speed(long) is probabky not what we intend to do
//	but editor will not warn about it
// 
// c++ 20 standard does not support strong typedef (a distinct type with the properties of the base type but throws
//	errors when mixing between the two) but many 3rd party libraries do
// 
// aliases have scope like variables do, inside a block it has block scope, inside global namespace it has global scope
// 
// TypeDefs - short for type Definition
// older way of making aliases for types, yseing the type def keyword
// 
// //these both prpoduce the same result
//	typedef long Miles;
//	using Miles = long
// 
// type def is in c++ fpr backward compatibility but are generally replaced by type aliases in modern c++
// 
// for more complex types typedef can get confusing so
// Best Practice: prefer using type aliases over typedefs
// 
// in conventional language typedef and type alias are interchangeable terms
// 
// TYPE ALIASE USES
// primary use is for platform independant coding
// if we dont know whether a platform will use 2 or 4 byte integers for int we can use aliases for variables based on number
// of bits needed, then in a preprocessor directive set those aliases to match the coresponding type for that size
// based on the platform. 
//
// tldr :
// #ifdef INT_2_BYTES
//	using int8_t = char;
//	using int16_t = int;
//	using int32_t = long;
//	#else
//	using int8_t = char;
//	using int16_t = short;
//	using int32_t = int;
//	#endif
// 
// thats right, fixed width integers ive used before are actually just type aliases
// 
// another (and often most used) use is for making short alias for really long type namse such as 
//	std::vector<std::pair<std::string, int>> which from what i can tell makes a map like variable of string and integer
// 
// third use is documenting the use of a variable (such as the return value for a function)
// using TestScore = int;
// TestScore gradeTests( int[4] answers]);
// 
// using teh TestScore alias allows for the meaning of teh return value to be easily known without studying function or
// referencing the documentation
// 
// fourth use
// easier code mantinance as if the variable needed for a specific use changes over thr course of writing the program,
// dont need to change all the instances, can just change what type the alias is of, obv this has risks (changing the
// type of a variable can have unforseen consequences on teh whole code changning behavior
// 
// misuse of type aliases can lead to more downsides than upsides such as hiding familiar types behind custom names 
// that need to be searched to be understood. in other words only use type aliases when they provide a clear benifit 
// to resadability or mantinance
// 
// Best Practice: use type aliases only if there is a clear benifit to readibility or manntinance
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//