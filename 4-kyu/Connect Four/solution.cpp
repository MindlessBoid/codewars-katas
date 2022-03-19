#include <string>
#include <vector>

bool checkWin(const std::vector<std::vector<int>>& board, int x, int y, int dx, int dy)
{
  auto checkBound = [](const std::vector<std::vector<int>>& board,int x, int y)
  {
    int numRows = board.size();
    int numCols = board.front().size();
    return x >= 0 && y >= 0 && x < numRows && y < numCols;
  };
  int count = 0;
  for(int i = 1; i < 4; i++)
    if(checkBound(board, x + dx*i, y + dy*i) && board[x][y] == board[x + dx*i][y + dy*i]) 
      count++;
    else break;
  for(int i = 1; i < 4; i++)
    if(checkBound(board, x - dx*i, y - dy*i) && board[x][y] == board[x - dx*i][y - dy*i]) 
      count++;
    else break;

  return count >= 3;

}
std::string who_is_winner(const std::vector<std::string>& pieces_position_list)
{
  std::vector<std::vector<int>> board(6, std::vector<int>(7, 0));
  std::vector<size_t> rowIndices(7, 0);
 for(auto piece: pieces_position_list)
  {
    // 0: empty, 1: red, 2: Yellow
    int colIndex = piece[0] - 'A';
    int rowIndex = 5 - rowIndices[colIndex]++;
    board[rowIndex][colIndex] = piece[2] == 'R' ? 1 : 2;

    if(checkWin(board, rowIndex, colIndex, 1, -1) 
    || checkWin(board, rowIndex, colIndex, 1, 1)
    || checkWin(board, rowIndex, colIndex, 1, 0)
    || checkWin(board, rowIndex, colIndex, 0, 1)
    )
      return board[rowIndex][colIndex] == 1 ? "Red" : "Yellow";
  }

  return "Draw";
}
/* Quite unreadable solution
std::string who_is_winner(const std::vector<std::string>& pieces_position_list)
{
  std::vector<std::vector<int>> board(6, std::vector<int>(7, 0));
  std::vector<size_t> rowIndices(7, 0);
  for(auto piece: pieces_position_list)
  {
    // 0: empty, 1: red, 2: Yellow
    int colIndex = piece[0] - 'A';
    int rowIndex = 5 - rowIndices[colIndex]++;
    board[rowIndex][colIndex] = piece[2] == 'R' ? 1 : 2;
    int curr = board[rowIndex][colIndex];
    int i = rowIndex;
    int j = colIndex;


     // Diagonal 1 right to left
    int countDiag1 = 3;
    while(i < 5 && j > 0 && board[++i][--j] == curr) countDiag1--;
    i = rowIndex; j = colIndex;
    while(i > 0 && j < 6 && board[--i][++j] == curr) countDiag1--;
    if(countDiag1 <= 0) return curr == 1 ? "Red" : "Yellow";
  
    //diagonal 2 left to right
    int countDiag2 = 3;
    i = rowIndex; j = colIndex;
    while(i < 5 && j < 6 && board[++i][++j] == curr) countDiag2--;
    i = rowIndex; j = colIndex;
    while(i > 0 && j > 0 && board[--i][--j] == curr) countDiag2--;
    if(countDiag2 <= 0) return curr == 1 ? "Red" : "Yellow";
  
    //vertical
    int countVer = 3;
    i = rowIndex; j = colIndex;
    while(i < 5 && board[++i][j] == curr) countVer--;
    i = rowIndex; j = colIndex;
    while(i > 0 && board[--i][j] == curr) countVer--;
    if(countVer <= 0) return curr == 1 ? "Red" : "Yellow";
  
    //horizaontal
    int countHor = 3;
    i = rowIndex; j = colIndex;
    while(j < 6 && board[i][++j] == curr) countHor--;
    i = rowIndex; j = colIndex;
    while(j > 0 && board[i][--j] == curr) countHor--; 
    if(countHor <= 0) return curr == 1 ? "Red" : "Yellow";
  
  }

  return "Draw";
}
*/