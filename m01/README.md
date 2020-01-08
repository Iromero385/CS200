# Introduction to Classes
    Video Tutorial Clips 
    m##-## for module#-clip#
    Textbook example programs on PR folders 
    PR11 for Chapter 11 examples, etc.
    
### m01-01 Struct v Class
    Journey of C --> C++ from struct to class

### m01-02 Ch 13 Content Intro
    Section by section Walk through

### m01-03 Ch 13 Overview
##### Ch 13 Introduction to Classes
    Powerpoint of this Chapter

## m01-04
    Ch 13-2 Introduction to Classes
    Example program:
        Pr13-1 Declare, Define and Apply a Class

## m01-05
##### Ch 13-3 Defining an Instance of a Class
##### Contains 2 Episodes
    Example programs
        Pr13-2 Multiple Instance of the same class 
        Pr13-3 C style dynamic allocation
```C++
 Rectangle *kitchen = nullptr; // To point to kitchen dimensions
 Rectangle *bedroom = nullptr; // To point to bedroom dimensions
 Rectangle *den = nullptr; // To point to den dimensions
 // Dynamically allocate the objects.
 kitchen = new Rectangle;
 bedroom = new Rectangle;
 den = new Rectangle; 
```

        Pr13-4 C++11 style dynamic allocation
```C++
 #include &lt;memory&gt; 
 unique_ptr<Rectangle> rectanglePtr(new Rectangle); 

 // Dynamically allocate the objects.
 unique_ptr<Rectangle> kitchen(new Rectangle);
 unique_ptr<Rectangle> bedroom(new Rectangle);
 unique_ptr<Rectangle> den(new Rectangle); 
``` 

## m01-06 C++ online reference 
##### [cplusplus.com](http://www.cplusplus.com)


## m01-07
##### Ch 13-4 Why private member
    To fortify a class like a castle:
    1. to have limit (privatize) access the data
    2. to security clearance at the gate


## m01-08 
##### Ch 13-5 Separate definition from declaration
    Purpose: Division of responsibility<br>
    Pr13-1.cpp ---> duplcated as ---> m01_08_separate_defined.cpp<br>
    m01_08_separate_defined.cpp ---> move out of scope --->  m01_08_separate_defined.cpp<br>
    m01_08_separate_defined.cpp ===> move out of file ===> m01_08.h
        Separate one Class header file into<br> 
        a specification header (.h) file and a definition (.cpp) file <br>


## m01-09
##### Ch 13.7 Constructors
    Constructors Overview
        [C++ Reference](http://www.cplusplus.com/doc/tutorial/classes/) is used.<br>
    Default Constructor
        an **implicit method**: if no user-defined, the compiler implicitly declares one. <br>
        [C++ Reference](http://www.cplusplus.com/doc/tutorial/classes2/) is used.<br>
    Dynamically Allocated Objects <br>
        Pr13-1.cpp  --->  m01-09_dynamic_alloc_obj.cpp <br>
        6 special Class methods are implicit, i.e. if not specified, a default will be created.

## m01-10
##### Ch 13.8 Passing Arguments 
    Constructor with default arugment<br>
        To modify Pr13-9_condensed.cpp Sales example <br>
    Special Members
        These implicit functions are already covered in the previous moedule.<br>
        The older one can cause a lot of headache, please use them with caution.<br>
        However, the two new ones on the move (&&) operators are GREAT!<br>
    Passing the arguments
        [C++ Reference](http://www.cplusplus.com/doc/tutorial/classes/) and [Initialized List](http://www.cplusplus.com/reference/initializer_list/initializer_list/) are used.<br>

##### Ch 13.9 Destructors <br>
- If an object is dynamically allocated, its memory should be released. <br>

## m01-11
##### Ch 13.10 Overloading Constructors 
    C vs C++ variable declaration<br>
        string str; // C declaration | C++ default construct<br>
        string str("Hello"); // C++ argument construct<br>

    Constructor with a list of different and mixed types of arguments<br>
        Pr-13-13_condensed.cpp Inventory example <br>
        There are 6 built-in implicit methods, i.e. if not defined, compiler will provide one.<br>

## m01-12
##### Ch 13-11 Private Memeber Functions
    Private member functions are also called helpers, or runners.
    Member Access guideline<br>
        All member methods can access other members.<br>
        All public methods can be accessed from outside.<br>
        All private member methods may not be accessed from outside.<br>

## m01-13
##### Ch 13.12 Array of Objects
##### Ch 7.6 Array Intialization
    Initializer List
    [C++ Reference](http://www.cplusplus.com/reference/initializer_list/initializer_list/) is used.<br>

## E01-13
##### Ch 13.13 OOP Practice: Case Study
##### Ch 13.14 OOP Pactice: Simulating Dice
##### Ch 13.15 OOP Practice: Abstract Array Type
##### Ch 13.16 Unified Modeling Language (UML)
##### Ch 13.17 Define Class and its Responsibility