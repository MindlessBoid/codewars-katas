#include <string>

class SnakesLadders
{
  public:
    SnakesLadders()
      :m_currentPositionP1(0), m_currentPositionP2(0), m_IsP1Turn(true), m_IsOver(false)
    {   
    };
    std::string play(int die1, int die2)
    {
      if(m_IsOver) return "Game over!";
      
      //update current position
      uint8_t& currPos = (m_IsP1Turn) ? m_currentPositionP1 : m_currentPositionP2;
      currPos += die1 + die2;
      if(currPos > 100) currPos = 200 - currPos;
      //can use map instead of switch 
      switch (currPos)
      {
      case 2:
        currPos = 38;
        break;
      case 7:
        currPos = 14;
        break;
      
      case 8:
        currPos = 31;
        break;
      case 15:
        currPos = 26;
        break;
      
      case 16:
        currPos = 6;
        break;
      
      case 21:
        currPos = 42;
        break;
      
      case 28:
        currPos = 84;
        break;
      case 36:
        currPos = 44;
        break;
      
      case 46:
        currPos = 25;
        break;
      
      case 49:
        currPos = 11;
        break;
      case 51:
        currPos = 67;
        break;
      
      case 62:
        currPos = 19;
        break;
      case 64: 
        currPos = 60;
        break;
      
      case 71:
        currPos = 91;
        break;
      
      case 74:
        currPos = 53;
        break;
      
      case 78:
        currPos = 98;
        break;
      case 87:
        currPos = 94;
        break;
      
      case 89:
        currPos = 68;
        break;
      case 92:
        currPos = 88;
        break;
      
      case 95:
        currPos = 75;
        break;
      
      case 99: 
        currPos = 80;
        break;
      
      case 100:
          m_IsOver = true;
      
      default:
        break;
      }
      
      std::string currPlayer = std::string("Player ") + (m_IsP1Turn ? "1" : "2");
      std::string currStatus = m_IsOver ? std::string(" Wins!") : (std::string(" is on square ") + std::to_string(currPos));
      
      //update the next turn
      m_IsP1Turn = (die1 == die2) ? m_IsP1Turn : !m_IsP1Turn;
      return currPlayer + currStatus;
    }

  private:
    uint8_t m_currentPositionP1;
    uint8_t m_currentPositionP2;
    bool m_IsP1Turn;
    bool m_IsOver;

};