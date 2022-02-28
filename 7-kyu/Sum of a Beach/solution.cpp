#include <string>
#include <regex>
int sum_of_a_beach(std::string s)
{
    //regex_iterator is used to access the individual matches of a regex with the underlying character sequence
    //std::sregex_iterator = std::regex_iterator<std::string::const_iterator>
    std::regex words_regex("sand|water|fish|sun", std::regex_constants::icase);
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();
    return std::distance(words_begin, words_end);
}