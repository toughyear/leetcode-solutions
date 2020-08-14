#include <bits/stdc++.h>
using namespace std;

// TODO: note to self - Keep track of edge cases clearly

//DFS implementation
//use & to pass as reference, changing the values directly
// and not by creating a copy

void DFS(int i, int j, vector<vector<char>> &grid)
{
    // make sure its not visited
    if (grid[i][j] == 'v')
    {
        //already visited
        return;
    }

    // set itself as visited before calling DFS on other elements
    grid[i][j] = 'v';

    // call DFS on surroundings exist and if they are unvisited 1
    if ((i - 1 >= 0) && (grid[i - 1][j] == '1'))
    {
        DFS(i - 1, j, grid);
    }
    if ((i + 1 < grid.size()) && (grid[i + 1][j] == '1'))
    {
        DFS(i + 1, j, grid);
    }
    if ((j - 1 >= 0) && (grid[i][j - 1] == '1'))
    {
        DFS(i, j - 1, grid);
    }
    if ((j + 1 < grid[0].size()) && (grid[i][j + 1] == '1'))
    {
        DFS(i, j + 1, grid);
    }

    // control reaches here when all connecting nodes have been visited
    //and set as 'v'

    return;
}

//solution function
int numIslands(vector<vector<char>> &grid)
{

    // we will set visited as 'v' char and '1', '0' are default
    //counter to store number of islands
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            //Island should be strictly '1'
            if (grid[i][j] == '1')
            { //increase count of islands by 1
                count++;
                // not visited, call DFS with reference to grid
                DFS(i, j, grid);
            }
            // else do nothing
        }
    }

    return count;
}

int main()
{

    vector<vector<char>> test1 = {{'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'}};

    vector<vector<char>> test2 = {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}};

    vector<vector<char>> test3 = {
        {'1', '1', '1'},
        {'0', '1', '0'},
        {'1', '1', '1'},
    };

    cout << numIslands(test1) << endl;
    cout << numIslands(test2) << endl;
    cout << numIslands(test3) << endl;

    return 0;
}