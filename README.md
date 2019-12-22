# Pathfinding Algorithms

This is a repository for path finding algorithms.


## Files in this repository:

### A* with heap - Python
This is an impelmentation of A* with a binary heap in Python.
Note that this version uses a modified cost function

The following image shows an example result with the following colour code:
- White: walkable
- Red: obstacle (not walkable)
- Blue: starting position
- Green: goal position
- Grey: path found

![Can't load image, please go to the 'figures' folder](figures/astar_heap.png)

Note that in this version on each iteration it is only allowed to go Up, Down, Left or Right. To allow diagonal checks change the following line of code:
```
neighbours = [(0,1),(0,-1),(1,0),(-1,0)]
```
to:
```
neighbours = [(0,1),(0,-1),(1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1)]
```