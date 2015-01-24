# lee-pathfinder
C++ implementation of Lee algorithm, a pathfidning algorithm

The implementation contains:
* LeePathfinder.h - class used for pathfinding
* utils.h - tiny header with utility function for loading maze matrix from file
* sample.cpp - sample of how the path is retrieved.

***

####Maze matrix

Legend:
* 0 - empty spaces
* 1 - obstacles
* 2,3 - start and end route points
Matrix sample is contained in the Sample MVS/leetest.map
Matrix is loaded into int array and then passed to LeePathfinder along with x and y dimensions.

####LeePathfinder
LeePathfinder object is initialized with an array of int which is maze matrix and its x and y dimensions.
* **CalculatePath** returns a vector of int pairs, which is a backtraced path (list of nodes) from end to start in original maze.
* **GetIndexesMap** returns a matrix, which is result of wave expansion. It has same dimensions as maze matrix. Unmarked nodes are marked with -2, obstacles with -1. **NOTE:** returns correct result **only** if CalculatePath was called before. Otherwise returns array of -2.
