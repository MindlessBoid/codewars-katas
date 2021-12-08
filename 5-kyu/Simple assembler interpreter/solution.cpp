#include<string>
#include<unordered_map>
#include<vector>

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
  std::unordered_map<std::string, int> result;
  for(size_t i = 0; i < program.size(); i++)
  {
    std::string instruction = program[i];

    /*parsing*/
    size_t pos1 = instruction.find_first_of(' ');
    size_t pos2 = instruction.find_first_of(' ', pos1 + 1);
    //find register
    std::string reg = instruction.substr(pos1 + 1, pos2 - pos1 - 1);
    //find var or const
    std::string var;
    if(pos2 != std::string::npos) var = instruction.substr(pos2 + 1);
    
    /*deal with instructions accordingly*/
    //assume the program is complier error-free
    switch (instruction[0])
    {
    case 'm':
      result[reg] = (isalpha(var[0])) ?  result[var] : stoi(var);
      break;
    
    case 'i':
      result[reg]++;
      break;
    
    case 'd':
      result[reg]--;
      break;
    
    case 'j':
      {
        int val = (isalpha(reg[0])) ? result[reg] : stoi(reg);
        if(val != 0)
        {
          int steps = (isalpha(var[0])) ? result[var] : stoi(var);
          i += steps - 1;//-1 cause i increments by one at the end of the for loop
        }
      }
      break;

    default:
      break;
    }
  }
  return result;
}