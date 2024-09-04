# Random Points
A program that using the creation of random points to demonstrate use of pointers
# Notes
1. `main()` Function:

The program asks the user for the number of `points` (`n`) and the minimum and maximum values for the `x` and `y` coordinates.
It calls `generateRandomPoints` to create an array of pointers to `Point` objects.
It then prints the points using `printPoints`.
The `averageDistance` function calculates the average distance between all pairs of points, which is then printed.
Finally, the program cleans up the dynamically allocated memory.
2. `generateRandomPoints()` Function:

This function generates n random points within the given `minX`, `maxX`, `minY`, and `maxY` bounds.
It uses `rand()` to generate random numbers, scaled to the specified range, and creates `Point` objects dynamically.
3. `printPoints()` Function:

Prints each point's coordinates in a nicely formatted way.
3. `averageDistance()` Function:

Calculates the average distance between all pairs of points using the overloaded subtraction operator in the `Point` class.
The average is computed by dividing the total distance by the number of pairs.
