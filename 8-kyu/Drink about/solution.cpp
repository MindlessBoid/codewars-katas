#include <string>
//descending
std::string people_with_age_drink(int age) {
  return std::string("drink ") + (age >= 21 ? "whisky"
                    :age >= 18 ? "beer"
                    :age >= 14 ? "coke"
                    :"toddy");
}
//ascending
/*std::string people_with_age_drink(int age) {
  return std::string("drink ") + (age < 14 ? "toddy" 
                                  :age < 18 ? "coke"
                                  :age < 21 ? "beer"
                                  :"whisky");
}*/