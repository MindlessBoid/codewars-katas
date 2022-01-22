#include <string>

std::string cat_mouse(std::string x) {
  return x.length() - 2 > 3 ? "Escaped!" : "Caught!"; // or just > 5
}
