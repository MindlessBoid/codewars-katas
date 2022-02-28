#include <string>
// Referrence:
//1. https://math.stackexchange.com/questions/140283/why-does-this-fsm-accept-binary-numbers-divisible-by-three
//2. https://www.geeksforgeeks.org/designing-finite-automata-from-regular-expression-set-1/
// At state B there are 2 transition 0 and 1, if 1 then we can ignore the left side of B and get to final state
const std::string multiple_of_3_regex = "(0|1(01*0)*1)*";