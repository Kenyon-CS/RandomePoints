#include <iostream>
#include <cstdlib>  // For rand(), srand()
#include <ctime>    // For time()
#include "Point.h"

// Function prototypes
Point** generateRandomPoints(int n, double minX, double maxX, double minY, double maxY);
void printPoints(Point** points, int n);
double averageDistance(Point** points, int n);

int main() {
    int n;
    double minX, maxX, minY, maxY;

    // Input from user
    std::cout << "Enter the number of points: ";
    std::cin >> n;
    std::cout << "Enter the min x: ";
    std::cin >> minX;
    std::cout << "Enter the max x: ";
    std::cin >> maxX;
    std::cout << "Enter the min y: ";
    std::cin >> minY;
    std::cout << "Enter the max y: ";
    std::cin >> maxY;

    // Generate random points
    Point** points = generateRandomPoints(n, minX, maxX, minY, maxY);

    // Print the points
    printPoints(points, n);

    // Calculate and print the average distance
    double avgDist = averageDistance(points, n);
    std::cout << "Average distance between points: " << avgDist << std::endl;

    // Clean up the dynamically allocated memory
    for (int i = 0; i < n; ++i) {
        delete points[i];
    }
    delete[] points;

    return 0;
}

// Function to generate random points within given bounds
Point** generateRandomPoints(int n, double minX, double maxX, double minY, double maxY) {
    Point** points = new Point*[n];
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < n; ++i) {
        double x = minX + (static_cast<double>(rand()) / RAND_MAX) * (maxX - minX);
        double y = minY + (static_cast<double>(rand()) / RAND_MAX) * (maxY - minY);
        points[i] = new Point(x, y);
    }

    return points;
}

// Function to print the points in a nicely formatted way
void printPoints(Point** points, int n) {
    std::cout << "Generated Points:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Point " << i + 1 << ": (" << points[i]->GetX() << ", " << points[i]->GetY() << ")" << std::endl;
    }
}

// Function to calculate the average distance between all pairs of points
double averageDistance(Point** points, int n) {
    double totalDistance = 0.0;
    int pairCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            totalDistance += *points[i] - *points[j];
            pairCount++;
        }
    }

    return pairCount > 0 ? totalDistance / pairCount : 0.0;
}
