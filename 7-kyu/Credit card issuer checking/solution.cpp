#include <string>
std::string getIssuer(const std::string &number)
{
  std::string str1 = number.substr(0, 1);
  std::string str2 = number.substr(0, 2);
  std::string str4 = number.substr(0, 4);
  size_t length = number.length();
  if(str1 == "4" && (length == 16 || length == 13)) return "VISA";
  if((str2 == "51" || str2 == "52" || str2 == "53" || str2 == "54" || str2 == "55") && length == 16) return "Mastercard";
  if((str2 == "34" || str2 == "37") && length == 15) return "AMEX";
  if(str4 == "6011" && length == 16) return "Discover";

  return "Unknown";
}