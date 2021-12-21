class Adder
{
private: 
  int n;
public:  
  Adder(int n_)
  {
    n = n_;
  }

  //should not return a ref
  Adder operator() (int n_)
  {
    return Adder(n + n_);
  }

  //User-defined conversion function
  //this case custom type Adder acts as an int => dont to overload +, -, ==
  operator int()
  {
    return n;
  }
  
  friend bool operator==(const int& a, const Adder& b) { return a == b.n; }

};
auto add(int n)
{
  return Adder(n);
} 