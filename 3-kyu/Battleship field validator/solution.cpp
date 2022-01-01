#include <vector>

bool validate_battlefield(std::vector< std::vector<int> > field) {
  const size_t NUM_ROWS = field.size();
  const size_t NUM_COLS = field[0].size();
  //std::vector<std::vector<bool>> hasVisited(NUM_ROWS, std::vector<bool>(10, false));
  int numOfBattleships = 1;// 4 cells
  int numOfCruisers = 2;// 3 cells
  int numOfDestroyers = 3;// 2 cells
  int numOfSubmarines = 4;// 1 cells

  for(size_t i = 0; i < NUM_ROWS; i++)
  {
    for(size_t j = 0; j < NUM_COLS; j++)
    {
      // since we iterate from left to right and top to bottom
      // we just need to look at the right and bottom neighbor for valid cell
      if(field[i][j] == 1)
      {
        //checked, not necessary needed
        field[i][j] = 0; 

        int length = 1;
        /*
          Only need to check 4 surrounding cells due to the way of iteration
          Either:
          0 0 0      0 0 ?
          0 1 ?  or  0 1 ?
          ? ? ?      0 ? ?

          ?: cell of interest
         */
       
        int right = (j == NUM_COLS - 1) ? 0 : field[i][j+1];
        int bottom = (i == NUM_ROWS - 1) ? 0 : field[i+1][j];
        int bottomLeft = (i == NUM_ROWS - 1 || j == 0) ? 0 : field[i+1][j-1];
        int bottomRight = (i == NUM_ROWS - 1 || j == NUM_COLS - 1) ? 0 : field[i+1][j+1];
        
        // Valid cases
        //right
        if(right == 1 && (bottom || bottomLeft || bottomRight) == 0)
        {
          while(field[i][j + length] == 1)
          {
            field[i][j + length] = 0; //checked
            length++;
          }
        }
        //bottom
        else if(bottom == 1 && (right || bottomLeft || bottomRight) == 0)
        {
          while(field[i + length][j] == 1)
          {
            field[i + length][j] = 0; //checked
            length++;
          }
        }
        //case submarine
        else if((right || bottom || bottomLeft || bottomRight) == 0)
        {
            //should not be continue cause we need up update the count of ships later
        }
        //other cases
        else 
        {
          return false;
        }

        //update number of ships
        int& num =  length == 4 ? numOfBattleships 
                  : length == 3 ? numOfCruisers 
                  : length == 2 ? numOfDestroyers
                  : numOfSubmarines;
        num--;
      }  
      //not necessary needed for readability
      else continue;
    }
  }
  return (numOfBattleships  || numOfCruisers || numOfDestroyers || numOfSubmarines) ? false : true;
}
