//https://app.asana.com/0/1209463997007680/1209698555356102
#include <iostream>
#include <vector>
#include <stack>

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int N = 10;

// проверяем что точка внутри поля и не является границей
bool isValid(int x, int y, std::vector<std::vector<int>>& grid) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 1;
}

void dfs(int x, int y, std::vector<std::vector<int>>& grid) {
    std::stack<std::pair<int, int>> stack;

    stack.push({x, y});
    grid[x][y] = 2;  //стартовую точку сразу закрашиваем и пихаем в стек

    while (!stack.empty()) {
        auto [currX, currY] = stack.top();
        stack.pop();
        //в первый раз получаем стартовую точку, в последующие разы ее соседей и тд

        //проверяем соседей
        for (int i = 0; i < 4; i++) {
            int newX = currX + directions[i][0];
            int newY = currY + directions[i][1];

            // если сосед = 1 и валиден - закрашиваем его
            if (isValid(newX, newY, grid)) {
                grid[newX][newY] = 2;
                stack.push({newX, newY});
            }
        }
    }
}

//всё тоже самое, но очередь :) 
void bfs(int x, int y, std::vector<std::vector<int>>& grid) {
    std::queue<std::pair<int, int>> queue;

    queue.push({x, y});
    grid[x][y] = 2;  

    while (!queue.empty()) {
        auto [currX, currY] = queue.front();
        queue.pop();
      
        for (int i = 0; i < 4; i++) {
            int newX = currX + directions[i][0];
            int newY = currY + directions[i][1];
            
            if (isValid(newX, newY, grid)) {
                grid[newX][newY] = 2;
                queue.push({newX, newY});
            }
        }
    }
}

void printGrid(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {      
        for (const auto& cell : row) {    
            std::cout << cell << " ";    
        }
        std::cout << std::endl;            
    }
    std::cout << std::endl;    
}

void Run_2_2() {
    std::vector<std::vector<int>> grid(N, std::vector<int>(N, 0));

    grid[5][5] = 1; grid[5][6] = 1; grid[5][7] = 1; grid[6][7] = 1;
    grid[7][7] = 1; grid[7][6] = 1; grid[7][5] = 1; grid[6][5] = 1;

    // Точка внутри контура 
    int startX = 6;
    int startY = 6;

    printGrid(grid);

    bfs(startX, startY, grid);

    printGrid(grid);
}