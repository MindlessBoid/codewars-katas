// Using operator overloading
struct Omnibool
{
  bool operator==(bool rhs) 
  {
    return true;
  }
};
Omnibool omnibool;

// Using define 
// since omnibool will be compare with operator == 
// == has the precedence before for ||
// so no matter the outcome of ==, it will always return true
#define omnibool true || false