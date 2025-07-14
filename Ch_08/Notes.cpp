

// CONTROL FLOW INTRO (flow control)
// 
// when program run cpu starts at top of main(), executes statments in sequential order (by default)
// then ends at main
// 
// the specific sequence of statments that the cou executes is called teh execution path or path for short
// a program that asks for input then prints the input regaurdless of contents is a stright-line program
// there are no ways for the behavior to vary
// 
// however a smarter program would have multiple paths and may just repeat if the user inputs an invalid input
// sp the number of times it asks or the output is not knowable till runtime
// 
// an if statement is an example of a flow control statement 
// a flow control statement that causes a point of execution to change to a non sequential statement is called 
// branching


// CATEGORIES OF FLOW CONTROL STATEMENTS
// 
// Conditional Statements: cause a section of code to execute only if some condition is met
//			If
//			else
//			switch
// 
// Jumps: Tells the CPU to start executing the statements at some other locaition
//			goto
//			break
// 			continue
// 
// Function Calls: Jump to some other location and back
//			function calls
//			return
// 
// Loops: Repeatedly execute some sequence of code 0+ times untill some condition is met
//			while
//			do-while
//			for
//			ranged-for
// 
// Halts: terminate the program
//			std::exit()
//			std::abort()
// 
// Exceptions: A special kind of flow control structure designed for error handling
//			try
//			throw
//			catch
//


// IF (AND BLOCKS)
// there are two basiv conditional type flow controls:
// if and switch
// 
// if recap 
// for an if statment to execute more than a single expression the bounds of the if must be contained within blocks
// 
// BEST PRACTICE generally put single expresion if statments into blokcs aswell to avoid problems or confusion
// 
// if you dont include blocks in your if statments thers are still implicit blicks so a variable created in an 
// if statment immediatly goes out of scope
// 
// if else when you only want to execute code after the first true condition
// (keeps checking for first instance of a true then exits all ifs)
// if if when you want to execute code after all true conditions
// (checks for every possible tru and executes code for alll of them)
// 
// 
//COMMON IF PROBLEMS
// 
// NEsted ifs and the dangling else:
//	if
//		if
//	else
// which if owns the else?
// the answer is it belongs to the last if withiout an else
// 
// to get an else on the first if and also to avoid ambiguity:
// enclose nested ifs inside blocks
//
// Flattening Nested ifs 
// nested ifs can be flattened by restructuring the logic or by uding logical operators, as code that is less
// nested is less prone to errors
// for example :
//	if
//	{
//		if
//		else
//	}
//	else
// can be flattened to 
//	if
//	else if
//	else
// 
//
//
// NULL STATMENTS
// null statements are just a semicolon ";"
// they are used when the editor needs a statment but we dont have anyting to put there
// such as to give something for an if to use incase the intended statement is commented out
// for readibility null statments are given their own line
// they can easily cause issues for an if statement by accidentally ending the starting line of an if with a semicolon
// EG:
// if (false);
// {badThing()} //because if statement executes the ; as a null statement, bad thing allways executes instead of never
// 



//CONSTEXPR IF STATEMENTS
// 
// c++17 introduced constexpr if statements for those with constexpr conditionals
// the syntax is :  if constexpr (myConstexprCOnditional)
// 
// best practice if the conditional is a const expression use a constepr if
// 
// however modern compilers will often treat potential constexpr ifs as constepr wothout keyword but they are
// not required to do so
// 
// will generate error if reg if has a constexpr conditional without if being marked constexpr

//SWITCH STATEMENTS
// if you eant to chain if else statements its often better to use switch
// 
// syntax:  
//	switch(x)
// {
//	case 1:
//	
//	case 2:
// 
//	case 3:
//	
//	default:
// 
// }
// 
// A switch conditional must resolve to an integral so int or enum both work aswell as some other types i belive
// it uses int type because the most common implementation of switch is a jump table that jumps execution
// to a line based off input as an array coordinate rather than a list of comparisons 
// however that is just eh historic method, i could change in future standards
// 
// Case lables the basic case keyword followed by a const expression, the tyoe must match or convert to the
// type of the conditinal (guess that mean it cant be they bot convert to int), same case cant be used twice
// case converts its expression to int so like '6' would be int 54
// 
// if no case matches and no default label, entire switch does nothing
// 
// convention is to put default label as the last block
// 
// tested out switch in testing_01
// 
// SWITCH CONVENTIOSN
// cases are not their own scope so they are generally not indented but it can lead to poor readibility
// so the general soltion is to indent the whole block but remove teh indent from the case labels so that
// readibility is there while not impling each is its own scope
// 
// while switch is more readable than if else chain if else is more flexible and allows for stuff lik
// comparrisonns other than equality
// testing multiple conditions
// determin if value is in range
// an expression typ swithc doesnt support
// or expressions that evaluate to bool
// 



// SWITCH FALLTHROUGH AND SCOPING
// 
// when switch label doesnt end in return or break the execution line continues through every subsequent case
// sice fallthroug is raerly intended many compilers give wanrings
// 
// commenting intenitona fallthrough is common to let others know its not oversight
// 
// to help in this c++17  added the attribute falltrhough
// atribute indicated by [[ ]]
// [[fallthrough]] modifies a null statement to indicate intentional flalthrough to devs and compiler
// syntax: 
// case
// behavior
// [[fallthrough]];
// case
// break
// 
// sequential case labels 
// can be a way of more readibly testing a value against many possible values as if it was an OR chain
// 
// someFunct (char c)
// {
//		return (c==a || c==b || c==d || c== e ......);
// }
// 
//  someFunctAlt (char c)
// {
//	switch (c)
//	{
//	case 'a':
//	case 'b':
//	...
//	return true;
// default :
//	return false;
//	}
// }
// 
// this is not considered fallthrough as execution starts at first statement after lable and lables aresnt statemetns
// 
// since lables donot define new scope variables can be created in them unlike if else however
// said variable would be in switch scope it would need to be used up before end of switch block or break
// 
// defininition or declaration of variables allowed before case lables but initialization is not 
// (bc it would never get resached as switch wpuld skip it to go to a case)
// initiation must happen after the last case lable
// assignment is allowed inside the cases though
// definition in teh cases is allowed but considered bad pracitce
// 
// if you need to define a variable in a case for the sake of the statements in tha case do so in an
// explicit block in the case
// 




// GOTO STATEMENTS
// unconditional Jump- causes the execution to jump to another spot in the code, the term means it always
// happens when executioin gets to it unlike if or switch which have conditions
// in cpp unconditioinal jump statement is goto and teh location is a statement label
// 
// syntax
// 
// tryAgain: //the statement label
// stuff
// if (GameOver)
//	goto tryAgain; //go to lable tryAgain
// 
// unconditional jump with an if is s=useful for when trying to avoid user inputting invalid input
// 
// ststement lables have function scope meaning they are visible in one function but are visible from
// the start of the function (thisnk if teh first statement in a funct was to jump down to end, 
// it needs to know where teh end is before it gets there
// 
//sstatements lables must connect to a statement and not be on theri own, a null statement works
// 
// you can only jump within function bounds, not function to function jumps
// 
// goto is generally shunned as it can increase the sphagetti quakity of the code
// teh exception is goto is fine used as a method of leaving a nested loop withoug returning from the function
// HOWEVER thats only really accepted if teh alternatives are worse for code readibility
// 



// Intro to loops and while statements
// 
// While loop, loop while condition is true
// 
// while (!(x>10) )
// {
// print (x++);
// }//counts from x to 10 and stops when x == 11
// 
// if the while is false to begin with it is skipped and only will execute if execution returns to it 
// and it evaluates as true
// 
// if a while is true and that never changes it is an infininte loop that can only get briken by:
// a return, break, goto, exit, or exception being thrown or user killing program
// 
// if you want an infininte loop for like a program that runs indefinitly just use:
// while(true)
// 
// loop vaiables are used to control how many times a loop executes
// they are usually int type but sometimes char or other
// 
// loop variables are often named i j or k  as a holdover convention from fortran language but to make 
// searching easier, modernly they are usually iii jjj or kkk so search funct doesnt have false positives
// 
// safest to use signed ints for loop variables as otherwise can run into issues
// like a while >= 0 is never false if unsigned as when it is 0 -1 it overflows
// 
// often we want to do someting every n intterations of a loop, easy to do by usng 
// modulo operator on loop variable
// 
// nested loops... i already knew everything it said
// 




// DO WHILE
// do while ensures that a while loop executes atleast once before evaluating wether to loop unlike a while
// which checks before executing any code
// 
// syntax 
//	do
//	{
//	stuff
//	}
//	while(conditon)



// FOR STATEMENTS (FOR LOOPS)
// 
// there are two types, the traditional one but also a new "range based" one covered later
// 
// for (init-statement; condition; wnd-expression)
//	statement;
// 
// for statement is evaluated in 3 parts:
//	first teh init statment executes at start before loop, this usually is a variable defenition
// vars from the init statement have loop scope meaning they exist from def through the end of teh loop 
// (fancy block scope)
// 
// then with each loop itteration the condition is evaluated if true execute if false loop terminates 
// and execution moves past the loop
// 
// finally the statement is executed and the end expression is evaluated, typically this is a ++i or --i
// 
//  != is dangerous in for loops because if could accidentally be always true if iii skips over that number
//  generaly better to just use the equivalent < or <= that covers overspill
// 
// 
// off by one errors are where the loop executes one too many or too fwe times, can be caused by using wrong relational 
// operator ie < instead of <= or by pre or post incrementing whne other was intended, also by just thinking of
// the numbers wrong, which is why often use 0 init instead of 1 
// 
// in for loops it is possible to omit the init statement and or the end expression and use your oen equivalent,
// still need the ; in the for statment's parameters tho
// 
// a for loop with empty parameters is equivalent to a while (true) but its bad practice
// 
// for loops can work with multiple counters
// for (int x{0}, y{0}; x<10; ++x, --y)
// one of teh only times the comma operator is allowed/ defining multiple variables in the same statement
//
// nested fors: conthing new
// 
// variables used only inside a loop shoul be defined inside the loop
// creating a variable has noo cost, but initializing one does,
// however initializing a var is just as costly as assigning a variable so no problem with
// initializing it as part of the loop
// 
// for loops are preferable over while loops when there is an obvoius loop variable
// while loops are preferable when there is not an obvoius loop variable
// 



// BREAK CONT
// in the context of a switch statement, break is tyoicallly used at the end of each case to signify the case
// is finished (exits switch to prevent fallthrough
// 
// in teh context of a loop, the break statement can be used to end the loop early.
// Execution continues with the next statement after the end of the loop
// in otherwords this has teh same effect as go to to exit a loop but always exits at the wnd of teh loop
// 
// break is the most common way of exiting an intentional infininte loop
// 
// break vs return
// break terminates a switch or a loop and execution continues at the end of the loop
// return terminates the entire function the loop is contained within an resumes exection after the function call
// 
// continue ends the current loop of the loop but does not exit the loop
// 
// be wary of continues in while loops as if it skips the itterator the loop may become infinite unintentionally
//
// there is debate over how muhch break and continue should be used as they might mess up some conmplicated logic
// and be easily missed
// 
// however if used properly it can make loops much mire readable by reducing the number of nested blocks
// and removing need for complicated looping logic
// 
// best practice, use break and cont where they simplify loop logic
// 
// Use early returns when they simplify your function’s logic.
// 
//


// Halts
// in c++ halts are impemented as functions not as keywords
// 
// when a program ends normally, main returns, all local vars and func param are destroyed
// then std::exit is called and passed the return value of main
// 
// std::exit is a function that causes program to terminate normally
// normal termination- program exited in an expected way (not necessarily sucessful, just expected)
// 
// std::exit then runs a number of cleanup functions like destroying static duration vars, 
// file cleanup(if files were used then return control back to the os with the status code that exit got passed
// 
// using the cstdlib header std::exit can be explicitly called, this can be done at any point in the 
// program or any function
// 
// std::exit does not cleanup local variables in current function nor in functons in the stack, this is dangerous
// if your program relies on locals being cleaned up
// 
// modern os's generally clean up missed allocated memory bt relying on it to do so is a bad habit
// that can lead to memory leaks in your programs while they are running
// additionally there are other kinds of cleanup that may be necessary such as writing data to a file 
// if it hasnt been flushed to file yet it will likely be lost when program suddenly exits
// 
// to avoid havin to write all the cleanup every time they want to use exit there is std::atexit() 
// which allows you to specify a function that will automatically be called on program termination via std::exit
// all cleanup you have to do can be put in there (register teh cleanup functuion at start of main
// 
//  whatever function is registered by atexit() must be void with no params, and will be called by program
// shutting down normally aswell as by calling exit() manually, also multiple functions can be registered under
// atexit()
// 
// ABORT OR TEMRMINATE
// 
// std::abort()- causes "abnormal termination", abnormal termination means unusual runtime errors 
// where program cant run any further such as divide by 0, abort does not do any cleanup
// 
// std::terminate() typically used in conjunction with exceptions, can be called explicitly
// usually implicitly called through unhandled exceptions, by default terminate calls abort()
// 
// best practice: generally sont use halts as they dont do any cleanup, unless there is no safe or reasonable waay to 
// return normally from the main function, its generally safer to use expecptions instead for handling errors
// 




//  RNG INTRO
// algorith- finite sequence of instrucions that can be followed to solve some problem or produce some result
// 
// algorithms are considered stateful if they retainsinfrmation across calls and stateless if not
// 
// deterministic means teh algorithm if given the same input always produces teh same output
// 
// 
// Pseudo rnadom number generators (PRNGs)
// it is an algoirthm that generates a serise of numbers whose properties simulate a sequence of random numbers
// 
// random seed -an initial value passed to a prng to help make each initial run of a prng different
// a user generated seed is fine but if teh user gives same seed each time they open the program the behavior
// will be identicle each time it runs
// 
// if you seed a prng with a seed with maximum variatioins fewer than the maximum number of possible outcomes of 
// the prng it is UNDEREEDED which can cause issues such as nth didgit is never the number 11 or too few
// possinble states such that it can be predited
// 
// prngs can have unifor or biased distribution which could cause issues 
// (think if a one in six chance happens 1/3 times because prng is biased towards outputting 6)
//
// PRNGs should be uniform across high-middle-low, even-odd, positive-negative
// additionally they should have a high period in all seeds
// 
// since prng are eterministic they have a peiod after which they begin to repeat themselves
// because tjey need to mix up its internal state depending on the method, it can get 
// slow when you need many random numbers
// 
// there are hundereds of PRNG's with various usecases / strengths and weaknesses on the internet 
// 
// c++ has inbuilt randomness functions in teh <random> header of standard library
// 
// 
// inbuilt PRNG's:
// 
// NAME				FAMILY							PERIOD		STATESIZE	PERFORMANCE	QUALITY	USE?
// 
// minstd_rand - Linear congruential generator		2^31		4 bytes		BAD			AWFUL	NO
// minstd_rand0 - '        '
// 
// mt19937 -	mersenne twister					2^19937		2500 bytes	decent		decent	probly
// mt19937_64 -	'			'
// 
// ranlux24 - subtract and carry					10^171		96bytes		Awful		good	no
// ranlux48 -	'			'
// 
// kuth_b - shuffled linear congruential			2^31		1028 bytes	awful		bad		no
// 
// default_random_engine - any of above				varies		varies		?			?		No^2
// 
// rand() - linear congruential generator			2^31		4 bytes		bad			awful	no^no
// 
//kuth_b, default_rand..., rand() are only there for compatibility with C
// 
// mersennne twist is the only one shipped with c++ that hsa good quality and oerformance
// 
// the downside of mersenne twist is that after seeing 624 generated numbers the results are predictable
// this is how you gert rng predictors in tas speedruns
// 
// popuar 3rd party prngs are the xoshiro and wyrand families for non cryptographic
// and chacha family for cryptographic (non predictable)
// 



// USING MERSENNE TWISTER RNG
// 
// probab;y most popu;ar one across langages
// mt19937 32 bit unsigned integers
// mt19937_64 generates 64 bit undigned integers
// 
// what about when you want a number in a certian range?
// ud use a uniform distrinbution, a random number distribution thata priduces outputs between two numbers inclusve
// 
// SYNTAX
// std::mt19937 mt();
// std::uniform_int_distribution die6{ 1, 6};
// 
// std::cout die6(mt);
// 
// tihs creates a twister and a uiform int distribution and then prints a random num 1-6
// 
// although this is goint ot print the same number every thim you open program, because the seed for mt is not changing
// 
// two standar way of seeding prng with a changing input:
// use the system clock
// use the system random device
// 
// SEEDING WITH TIME
// 
// the std::time() function and also askin ghow many ticks have happened since eaariest recorded time of program
// 
// using the <chrono> header, to get std::chrono::steady_clock::now().time_since_epoch().count()  
// static cast to <std::mt19937::result_type> for mt19937 seed value
// 
// high_resolution_clock uses the most granular time but relies on the system clock
// steady_clock doesnt rely on system clock  (not sure how it works) but it cant be adjusted by user
// 
// SEEDING WITH RANDOM DEVICE
// asks the oc for a random number, which means method changes per os
// 
// #include <random> (mt19937 and also random_device)
// 
// std::mt19937 mt{std::random_device}
// 
// os's are not required to make random_device nondeterministic
// 
// Best pratice apperantly is to use random device unless it has an issue on your target compiler/architecture
// 
// generally besat practice is not to reseed a prng after it has beem seeded
// 
// MERSENNE TWIST AND UNDERSEEDING ISSUES
// mt has 624 internal intgrals and we seed it with only one using random device or system clock that leave
//  623 to be "made up" by the computer but it results in an underseeded generator
// seeding mt with a 32 but number will never result in a first output of 42
// 
// std::seed_seq 
// can feed it one or more random values for it to generate a seed sequence(as many as needed) 
// apperantly this is better than giving mt only one rand number and faster than trying to call rand device
// for every number (plus that method risks using up rand device's full pool
// 
// prng's can need "warming up" with a bad seed to mix the internals enough for things to start being random enough
// this is done by discarding first x results usually 100s-1000s of results
// 
// when debugging its best to seed prng with single value that causes error to occur untill bug is fixed
// 
// 

// Global Random Numbers (RANDOM.h)
// best way to get a random num to entire project is a global random number in a namespace shared with all
// this is teh exception to teh general rule of no non const globals
// 
// Example of a header only global random solution
// in random.h
// note on its implementation
// it makes a mt19937 twice because of the limitations in what can bepassed through functions
// so the second mt is not being generated its is just copying all the values from teh first mt in teh funct
// 
// 
// 
// 
// 
// 
// 
//
