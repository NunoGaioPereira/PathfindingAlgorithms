/*********************
Mouse in a maze backtracking algorithm

Implementation of a backtracking algorithm to find a path from a given starting point
to a goal position in a maze.

The maze will look like:

	{{ 1, 1, 0, 1 }, 
	 { 1, 0, 1, 0 }, 
	 { 1, 1, 1, 0 }, 
	 { 0, 0, 1, 1 }}; 

where 1's are walkable and 0's are walls.

In this implementation the mouse is only allowed to go down and right.
*********************/

#include <iostream>

const int size = 5; // maze size

// Print function
void printSol(int solution[size][size], int size) {
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++) {
			std::cout << solution[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool findPath(int maze[size][size], int x, int y, int solution[size][size], int size) {
	// Reached the goal
	if(x == size-1 && y == size-1) {
		// Reached the destination
		solution[x][y] = 1;
		printSol(solution, size);
		return true;
	} 

	// If the current position is walkable, check bottom and right neighbours
	if(maze[x][y]==1) {
		
		solution[x][y] = 1;
		printSol(solution, size);
		std::cout << std::endl;

		// Check right neihgbour
		if(findPath(maze, x, y+1, solution, size)==1) {
			return true;
		}

		// Check bottom neihgbour
		if(findPath(maze, x+1, y, solution, size)==1) {
			return true;
		}

		solution[x][y] = 0; // If can't go down or right, backtrack to previous position
	}

	// Coulnd't find a path
	return 0;
}


int main() {

	// Initialize the maze
	int maze[size][size] = {{ 1, 1, 0, 1, 0 }, 
				            { 1, 0, 1, 0, 0 }, 
				            { 1, 1, 1, 0, 0 }, 
				            { 0, 0, 1, 1, 1 }}; 

    // Initialize empty solution
	int solution[size][size] = {};

	// Find solution
	bool a = findPath(maze, 0, 0, solution, size);

	if(a) {
		std::cout << "Found a path!" << std::endl;
	} else {
		std::cout << "Coulnd't find a path!" << std::endl;
	}

	return 0;
}