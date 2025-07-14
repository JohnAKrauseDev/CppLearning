

// TESTING YOUR CODE IN CPP
//
// test your code in parts rather than waiting for it tp be a complete whole first
// ofc test nce its a whole aswell
// 
// writing code in small well defined units as functions or classes with frequent comlining and testing 
// is best practice
// 
// INFORMAL TESTING
// a temporary bit of code to call the function/class/other in each of its output states that gets
// erased after testing
// 
// SAVING TESTS
// it can be better to save your tests asfunctions so they can be re called if you change anything
// 
// EVEN BETTER
// make a function that containst the test aswell as a marker for what failed aswell as teh expected answer
// a better method can be use assert which means it aborts if its expression fails (is false)
// 
// UNIT TEST FRAMEWORKS
// apperantly they are pretty cool but i ned to look into them on my own
// 
// INTEGRATION TESTING
// retest program once everything has been integrated
// 
// 


// Code Coverage
// 
// Statement Coverage - refers the percentage of statements in your code exercised by your testing routines
// but osme functions cannot be fully tested with a single call so sometimes 100% coverage isnt enough
// 
// Branch Coverage - refers to the percentage of branches that have been excecuted,
// each possible branch is counted seperatly. if has 2 branches even if the if has no else statement
// 
// with an example function where it has two return statements with an if the statement coverage can be 100%
// with sdingle call but requires two to get branch coverage
// 
// best practice is to aim for 100% branch coverage for your code
// 
// Loop Coverage - pass the 0, 1, 2 test meaning a loop is generally sound if you test
// 0 itterattions, 1 itteration and 2 itterations
// this ofcourse is barring if you have some branch that relyies on a higher loop count internally
// 
// Testing different catagories of inputs
//  good catagories to test by type: 
// Integer - pos, neg, 0, and, if relevant, overflow
// Float - test precision numbers ie slightly larger or smaller than expected ie .1 or .7 -.7
// Strings - empty, alpha numeric, all whitespace, some whitespcace (lead, trail, inner)
// pointer - Nullptr also



// Common Semantic errors in C++
// 
// semantic errors are errors where there isnt necesearly an syntax error, its just doesnt do what you intend
// can seem like undefines behavior
// 
// Conditional Logic Errors
// inncorectly codes the logic of a loop or conditional such as < instead of <=
// this can cause issues especially for loops ehere the loop can just be skipped entirely or become infininte if 
// the logic is done poorly
// 
// Infinite Loops
// many ways to cause this from logical errors to forgetting to itterate the loop variable
// 
// Off By One
// simple using wrong comparison logical or starting at wrong value causing loop to itterate one too many
// or too few times
// 
// Incorrect Operator precenence
// simple, often happens with logicals without proper parentasies
// 
// Precision Error with Floating Points
// when the floating point varible doesnt have enough orecision to store the whole number
// this can cause errors especially with == or !=
// 
// Integer division
// intending to do floating point division but accidentally doing int division
// 
// Accidental Null statements
// ";"  is a null stsattement and will messe up while loops or if statements if you put it between it and the block start
// 
// Not using a compound statement when one is reqired
// accidentally executing something always that you meant to be part of say an if's output
// 
// Using Asignment instead of Equality conditional
// = instead of == on accident
// 
// Forgetting to Use Function Call Operator when calling a function
//  forgettin gto add () at teh end of a function name for a call
// using function nam without () is generaly a pinter which usually implicitly converts to bool
// 



// Detecting and handling errors
// many errors in prorams come not from syntax or semantic errors but rahter faulty assumptions
// such as a program designed to look up student names and return their grade, faulty assumpptions could be:
// assming the student looked up does exist
// assuming all student names are unique
// assuming that the class uses letter grading system instead of pass fail
// 
// defensive programming is trying to anticipate all potential misuse by users or deveopers and handle it
// 
// Hsndling Errors in Functions
// 4 main strategies:
//	handle error in function
//	pass back error to the caller to deal with 
//	halt the program
//	throw an exceotion
// 
// handling error within the function
// this is gererally the best strategy if possible so it contains the error and corrects before it impacts 
// any external code
// either retry untill sucesseful
// or cancle teh operatin being executed
// 
// think asking user for a vaid input untill they input one or perioically checking for aninternet connection
// 
// Passing errors back to the handler
// you could make the return type a bool that returns sucess or failure
// or you coukd return a value that isnt going to be used normally (think -1 when array index is supposed to be returned
// said value is called a sentinle value (value with special meaning such as failed function)
// sentinle vlauses are not viable if the full range of the return value is used
// in those cases use std:: optional or std::expected
// 
// Fatal Errors
// of the error is so bad that the program cant continue to opperate properly it is refered to as a 
// non-recoverable error aka fatal error
// 
// Exceptions
// because returning errors from functions is messy c++ offers a seperate way of passing errors back
// called exceptions
// the idea is that when the exception is thrown, if the current function does not cach teh error the caller has
// the opportunity to catch the error, it progressivly moves up the stack untill is is caught and handled
// after which the execution continues normally  or untill main fails and program is terminated with exception
// error
// 
// Cout vs Cerr vs Logging
// both cout an cerr print text to teh console but modern os's provide ways to redirect output streams to files
// first cover the types of applications
// 
// two types of applications 
// Interactive applications (ones the user interacts with after running (such as games))
// Non-Interacive applications donot require user interaction to operate (aybe used to generate output used 
// by another program/application
// 
// Two types of Non-Interactives
// tools- launched to achive some immediate result before terminating
// services- run siently in the backround to perform some ongoing function such as virus scanner
// 
// cout for user facing text
// cout for user facing error messages in interacitve program
// cerr for logfile status and diagnostic info for help with diagnostic issue but not interesting
// 	for normal users
// for non interactive (tool or service), use cerr for error output only ie could not open file x
//	this allows errors to be parsed seperatly from regular output
// for "transactional" programs such as interactive web browser or non interacitve web server, use logfile
//	to produce a log of teh transactional events for review
// 


// STD::CIN AND HANDLING INAVALID INPUTS
// always consider how a user might misuse program, 
// predict teh misuse and handle it or prevent it, this is what makes a progrma robust
// 
// cin and >> recap
// 
// leading whitespace is discarded from input buffer,
// if buffer is now empty await user inputing more data.
// then extract as many consecutive chars as can untill newline or reaches a characte invalid for the 
// variable being extracted to
// 
// if characters were extracted in step 3, sucesss, extracted chars are converted into a value assigned to var
// if no characers extracted, failed, object being assigned gets value of 0 and future extractions fail intill 
// std::cin is cleared
// 
// Validating input
// 3 basic ways:
// inline (as user types):
//		prevent user from typing invalid input in the first place
// post entry (after user types):
//		let user enter whatever then validate the string is correct and if so convert to final variable form
//		let user enter whatever, let cin try to extract, then handle error cases
// 
// the first option is gernerally done by validating every character as the user presses the keys and just
// discarding invalid ones (not adding them to screen)
// however this validation method is not supported by std::cin
// 
// strings dont have limits on what can be put in them  but will stop at first whitespace then program can
// parse the string for validity, but parsing strings and converting them to other types such as numbers can be tricky
// so its is only done in rare cases
// 
// most often used methos is to let cin and >> do the hard work then deal with the fallout during failures
// 
// Types of Invalid Text Input
// generally can be split into 4 types of errors:
// extraction succeds but input is meaningless (entering k as math operator)
// extraction suceds but there is additional input ( '*t what' as math opperator)
// extraction fails  (k into a numeric input)
// extraction succeds but user overflows a numeric value
// 
// thus a robust program should be prepared for all those cases woth code to handle it
// 
// case 1: meaningless input 
// input validation- check if input waht what was expected, if so pass else alert user and ask for new input
// eg use while loop untill get valid input then return
// 
// case 2: extranious input
// in the case of extranious input seperated by whitespace the extranious parts are just held untill the 
// next time that it trys to assign out of the cin buffer
// that excess can be discarded using
// std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
// meaning discard characters up to the current size of teh cin buffer untill you encounter a newline (removed aswell)
// usialy wrap that into a function since its a long line to type
// 
// another way to deal with extranious input is to treat it as a failure case, as in use 
// !std::cin.eof() && std::cin.peek() != '\n';
// to return true if there is input still in the buffer after extraction or true if the next char is not a '\n'
// this can just feed into teh method of ignoring a line like case 1
// 
// 
// case 3: Extraction Fails
// when no input can be extracted to specified variable
// eg: enter a decimal: a
// 
// in the caluculator program in 9.5: 
//
//}
// this would result in a loop of asking for input followed bysaying imput is invalid eitout user being able to input
// 
// when cin tries to extract but fails, future requests for input extraction immedialy fail and are passed over
// untill cin is cleared
// 
// to so so, detect extraction has failed, use cin.clear(), and remove the bad inputs with ignore() like case 2:
// 
// example:
// if (std::cin.fail()) // If the previous extraction failed
//{
//     Let's handle the failure
//    std::cin.clear(); // Put us back in 'normal' operation mode
//    ignoreLine();     // And remove the bad input
//}
// but if (!(std::cin)) also works as cin converts to bool indicaing sucess or failure
// 
// 
// SPECIAL CASE, EOF
// end of file is a special error state that means there is no more data vaib=lible
// generted nrmally afte an input opperation fails sue to no data being availible ie reading contents of disk
// in the case of input this is no problem as we can just close file and move on
// 
// cin can generate eof error in rare cases: most commonly when special key combo for os input such as (ctr-z + enter)
// that makes an EOF character
// wha happens when cin encounters eof is os specific, on winows all future chaacters are flushed and if the 
// EOF chaacter is the first character it generates an EOF warning
// std::clear() will clear an EOF error but if inuput stream disconected the next request will generate EOF error
// best thing when reciving an eof error is to terminate program bc that generally means its job is donne
// 
// sonce we will likely ceck for a failed input stream offten, its a good function candidate
// #include <limits> // for std::numeric_limits
//
//void ignoreLine()
//{
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//}
//
//// returns true if extraction failed, false otherwise
//bool clearFailedExtraction()
//{
//    // Check for failed extraction
//    if (!std::cin) // If the previous extraction failed
//    {
//        if (std::cin.eof()) // If the user entered an EOF
//        {
//            std::exit(0); // Shut down the program now
//        }
//
//        // Let's handle the failure
//        std::cin.clear(); // Put us back in 'normal' operation mode
//        ignoreLine();     // And remove the bad input
//
//        return true;
//    }
//
//    return false;
//}
// 
//  Case 4: eXTACTION SUCCEEDS BUT USER OVERFLOWS A NUMERIC VALUE
// 
//  cin goes into failure mode but also assigns the closest in range value
// 
// CONCLUSION
//  every time i use user input text consider:
// Could extraction fail?
// Could the user enter more input than expected ?
// Could the user enter meaningless input ?
// Could the user overflow an input ?



// Assert/ Static_assert
// 
// fixing the problem of sytactically valid but semantically meaningless paramater inputs
// we could halt program or skip function whenever this occurs but those both suck, skippin is functionally
// silent failure which is terrible for debugging, terminating program may loose call stack and potentially
// useful debugging information ( mainly with exit not abort, abort tyically allows debugging at point of abortion)
// 
// Precondiotion - any condition that must be true prior to teh execution of osme section of code typically
//		for a function body (think putting an if at teh start of a function wit an early return)
// 
// this early return if is refered to as a bouncer pattern as it bounces out immediatly when an error is detected
// the main benifits are less nesting and all cases are visible up front rather than burried after computation
// 
// Invariant - Must be true while some section of code is executing such as with loops (exection while true untill false)
// 
// Postcondition - must be true after the execution of some section of code, not sure a good exampple
// 
// Assertions - an epression that will be true unless there is a bug in the program if assertion ever evaluates to 
//		false then the program terminates using abort()
// this abort typically contains the expression that failed as text along with code file name and line number
// 
// assert() resides in <cassert>
// 
// assert used with preprocesse macros is considered one of teh few acceptable uses of preprocessor macros
// eg :
// #define IDENTIFIER substitution_text
// 
// asserts are encouraged to be used liberally, and are consdered better than comments
// string literalls always evalutate to true so adding a decriptive string to an assert works like customiing teh error
// message
// 
// assert(condition && "description of what the ondition means in teh context of thiis assertion");
// 
// asserts can also be used to document cases that are not implemented bc they weren't needed at the time 
// of wrtiting the code
// assert( moved && "Need to handle cases of student movng classes");
// 
// 
// NDEBUG
// assert comes with a small performance cost as it checks so ideally assert shouldnt be encountered in production code
// the solution is a preprocessor macro called NDEBUG
// when that macr is called it disabbles all asserts, most IDE's set NDEBUG by default for release configurations
// meaning of i want assert in the production code ill need to turn it off in the settings
// for testing ourposes though i can use #define NDEBUG or #undef NDEBUG to enable or disable in a trans unit
// 
//static_assert
// static asserts are checked at compile time instesad if runtime, as such it causes an compile error
// 
// static_assert is a keyword so it is there bu defulat no need to incluse <cassert>
// 
// static_assert(sizeof(long) == 8, "long must be 8 bytes");
// aka
// static_assert(condition, "optional diagnostic message");
// 
// because it is evaluated at compile time the condition must be a const expression
// since it is keyword it can be placed anywhere in the code file even global namespace
// it is not deactivated in release builds like assert is
// sonce compiler does the evaluation, there is no runtiime cost to static_assert
// 
// Best Practice: if static_assert can be used instead of assert, do so
// 
// asserts are used to detect programming errors where the programer declares a thing that should never
// happen and its their fault if it happens and trips the assert
// assertions are generally compiled out so there is little reason not to liberally use them
// 
// error handling is gracefully handling cases that could happen, if rearely in a release build, this an be
// either recoverable or non-recoverable issues but atleast they can be cleaned up and a proper diagnostic
// message given, error detection/handling has a runtime and development cost
// 
// use assertions to catch programming errors, incorrect assumptions, or conditions that should never occur in
// correct code
// use error handling for issues we expect eill occur during noral operation or program
// use both when someting shouldnt happem but want to fail gracefully if it does
// 
// when using assert it should never have side effects as it will not do that in te production cide when assert is gone
// 
// assetrts immediatly terminate progam without time for cleanup, so dont use in cases where it can cause corruption
// if teh proram terminates unexpectedly
// 



// RECAP
// Scope Creep is when projects capabilities grow beyond teh original intention at start or projects phase
// 
// Software Verificaiton - the process of testing whether or not teh software works as expected in all cases
// Unit Test- test designed to test a small portion of code (usually finction or call) in isolation to ensure a 
//		particular behavior occurs as expected
// Unit Test Framework - help organize your unit tests (third party code, look into on own)
// Integration Testing - test a bunch of units all together to ensure they work properly (testing whole program even)
// 
// Code Coverage - refers to how uch of the code is executed while testing
// Statement Coverage -  refers to percentage of statements in a program that have been tested in testing routines
// Branch Coverage - refers to the percentage of branches tested in testing routines
// Loop Coverage - aka teh 0,1,2 test means test the loop with 0, 1, and 2 itterations for approproate behavior
// 
// Happy Path - the path of execution that occurs when no errors are encountered
// Sad Path - a path ehere errors occur
// non-recoverable error - aka fatal error, so severe program cannot keep running
// robust - means a program cn handle errors well
// 
// buffer - a chunk of memory set aside for storing data temporarily while it is moved from one place to another
// 
// Input Validation - checking if user input conforms to what the program is expecting
// 
// std::cerr output stream(liek cout) designed to be used for error messages
// 
// Precondiotion - any condition that must be true prior to teh execution of osme section of code typically
//		for a function body (think putting an if at teh start of a function wit an early return)
// 
// this early return if is refered to as a bouncer pattern as it bounces out immediatly when an error is detected
// the main benifits are less nesting and all cases are visible up front rather than burried after computation
// 
// Invariant - Must be true while some section of code is executing such as with loops (exection while true untill false)
// 
// Postcondition - must be true after the execution of some section of code, not sure a good exampple
// 
// Assertions - an epression that will be true unless there is a bug in the program if assertion ever evaluates to 
//		false then the program terminates using abort()
// 
// static asserts are checked at compile time instesad if runtime, as such it causes an compile error when false
// 
// 
// 
// 
// 
// 
// 
//


