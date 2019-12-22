import numpy as np
import matplotlib.pyplot as plt
from matplotlib import colors
from heapq import *

# Main class that receives a grid and finds the shortest path with A*
class Solver():
	
	def __init__(self):
		super(Solver, self).__init__()

		self.start = (0, 0) # initial position
		self.goal = (10, 13) # goal position
		self.grid = np.array([[0,0,0,1,1,0,0,0,0,0,0,0,0,0],
						      [1,0,0,1,1,1,1,1,1,1,1,1,0,1],
						      [0,0,0,0,0,0,0,0,0,0,0,0,0,0],
						      [1,0,1,1,1,1,1,1,1,1,1,1,1,1],
						      [0,0,0,0,0,0,0,0,0,0,0,0,0,0],
						      [1,1,1,1,1,1,1,1,1,1,1,1,0,1],
						      [0,0,0,0,0,0,0,0,0,0,0,0,0,0],
						      [1,0,1,1,1,1,1,1,1,1,1,1,1,1],
						      [0,0,0,1,0,0,0,0,0,0,0,0,0,0],
						      [1,1,0,1,1,1,0,1,1,1,1,1,0,1],
						      [0,0,0,0,0,0,0,0,0,1,0,0,0,0]])


	def findPath(self):
		self.path = self.astar()
		print("Done finding path")
		self.createFigure()

	# Create a matplotlib figure to show the path found
	def createFigure(self):
		# The path is represented as 4's
		print(len(self.path))
		for j in range(len(self.path)):
                  r = self.path[j][0]
                  c = self.path[j][1]
                  self.grid[r][c]= 4

		self.grid[self.goal[0]][self.goal[1]] = 2
		self.grid[self.start[0]][self.start[1]] = 3
		cmap = colors.ListedColormap(['white','red','green','#0060ff','#aaaaaa'])
		plt.pcolor(self.grid[::1],cmap=cmap,edgecolors='k', linewidths=1)
		plt.show()

	def heuristic(self, a, b):
	    return (b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2 # Euclidean distance between the two points

	def astar(self):
		# The set of neighbours for each node
	    # neighbours = [(0,1),(0,-1),(1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1)] # This would also check diagonals
	    neighbours = [(0,1),(0,-1),(1,0),(-1,0)] # Right, left, up, down

	    close_set = set() # set to contain visited nodes
	    path = {}
	    gscore = {self.start:0} # Movement cost
	    fscore = {self.start:self.heuristic(self.start, self.goal)} # The heuristic of A star
	    heap = []

	    heappush(heap, (fscore[self.start], self.start)) # push the current node and its score to the heap
	    
	    # While there is something in the heap
	    while heap:

	        current = heappop(heap)[1]

	        if current == self.goal: # reached the target position
	            final_path = []
	            while current in path:
	                final_path.append(current)
	                current = path[current]
	            return final_path

	        close_set.add(current) # add current node to closed set
	        for i, j in neighbours: # iterate through all neighbours
	            neighbour = current[0] + i, current[1] + j            
	            hscore = gscore[current] + self.heuristic(current, neighbour)
	            if 0 <= neighbour[0] < self.grid.shape[0]:
	                if 0 <= neighbour[1] < self.grid.shape[1]:                
	                    if self.grid[neighbour[0]][neighbour[1]] == 1:
	                        continue
	                else: # y limits
	                    continue
	            else: # x limits
	                continue
	            
	            # Using set() makes "in" tests O(1)
	            if neighbour in close_set and hscore >= gscore.get(neighbour, 0):
	                continue
	                
	            if  hscore < gscore.get(neighbour, 0) or neighbour not in [i[1]for i in heap]:
	                path[neighbour] = current
	                gscore[neighbour] = hscore
	                # fscore[neighbour] = hscore + self.heuristic(neighbour, self.goal)
	                fscore[neighbour] = hscore
	                heappush(heap, (fscore[neighbour], neighbour)) # push the neighbour and its score into he heap
	                
	    return False

if __name__ == '__main__':
	a = Solver() # Create an instance of the Solver class
	a.findPath() # Call the function that will solve A star