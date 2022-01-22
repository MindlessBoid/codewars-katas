#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>

/*Breadth 1st search*/
bool path_finder(std::string maze) {
  // TODO: Determine whether one can reach the exit at (n - 1, n - 1)
  // starting from (0, 0) in a n × n maze (represented as a string)
  // and return a boolean value accordingly

  int n = maze.find_first_of('\n'); //count number columns or n

  std::vector<bool> isVisited(maze.size());
  std::vector<int> queue;
  queue.push_back(0); //start at (0, 0)
  isVisited[0] = true;
  while(!queue.empty())
  {
    //if use std::list to pop_front then use queue.front and to be more like BFS
    int current = queue.back();
    queue.pop_back();

    //neighbors
    int up = current - n - 1;
    int down = current + n + 1;
    int right = current + 1;
    int left = current - 1;
    int dirs[] = {up, down, right, left};
    
    for(auto dir : dirs)
    {
      //failed cases
      if(dir < 0 || dir >= maze.size() || maze[dir] == '\n' || maze[dir] == 'W' || isVisited[dir] == true) continue;
      else
      {
        //set true right when adding to the queue 
        isVisited[dir] = true;
        queue.push_back(dir);
        //if the valid neighbor is the end just returnn true no need to check anymore
        if(dir == maze.size() - 1) return true;
      }
    }
  }
  return false;
}



/* Dumb solution
Breadth first search
bool path_finder(std::string maze) {
  std::stringstream ss(maze);
  std::vector<std::string> vMaze;
  std::string buffer;
  while(std::getline(ss, buffer))
  {
    vMaze.push_back(buffer);
  }

  const int NUM_ROWS = vMaze.size();
  const int NUM_COLS = vMaze[0].size();
  
  std::vector<std::vector<bool>> isVisited(NUM_ROWS, std::vector<bool>(NUM_COLS, false));
  std::list<std::pair<int, int>> queue;

  queue.push_back(std::make_pair(0, 0));
  isVisited[0][0] = true;
  while(!queue.empty())
  {
    int x = queue.front().first;
    int y = queue.front().second;
    if(x == NUM_ROWS - 1 && y == NUM_COLS - 1) return true;
    queue.pop_front();

    //check neighbors
    if(x + 1 < NUM_ROWS && vMaze[x + 1][y] == '.' &&  !isVisited[x + 1][y]) 
    {
      queue.push_back(std::make_pair(x + 1, y));
      isVisited[x + 1][y] = true;  
    }
    if(y + 1 < NUM_COLS && vMaze[x][y + 1] == '.' && !isVisited[x][y + 1]) 
    {
      queue.push_back(std::make_pair(x, y + 1));
      isVisited[x][y + 1] = true;
    }
    if(x - 1 >= 0 && vMaze[x - 1][y] == '.' && !isVisited[x - 1][y]) 
    {
      queue.push_back(std::make_pair(x - 1, y));
      isVisited[x - 1][y] = true;
    }
    if(y - 1 >= 0 && vMaze[x][y - 1] == '.' && !isVisited[x][y - 1]) 
    {
      queue.push_back(std::make_pair(x, y - 1));
      isVisited[x][y - 1] = true;
    }  
  }
  return false;
}
*/