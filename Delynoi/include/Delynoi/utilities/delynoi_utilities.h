#ifndef DELYNOI_DELYNOIUTILITIES_H
#define DELYNOI_DELYNOIUTILITIES_H

#include <Delynoi/models/basic/Point.h>
#include <vector>

/*
 * Namespace that includes common geometric utilities of the Delynoi library.
 */
// ReSharper disable once CppEnforceNestedNamespacesStyle
namespace Delynoi { // Nested namespaces requires C++ std17. This is 14+ NOLINT(*-concat-nested-namespaces)
    namespace delynoi_utilities {
        /*
         * Returns the trivial vector of indexes of length n (0,1,2...,n-1)
         * @param index_vector vector that will be set with the trivial vector
         * @param n length of the generated vector
         */
        extern void TrivialIndexVector(std::vector<int> &index_vector, int n);

        /* Computes the cross product of two points
         * @param a b points to operate
         * @return result of the operation
         */
        extern double crossProduct(const Point &a, const Point &b);

        /* Computes the norm of a point (basically, a vector starting from the origin)
         * @param p point which norm will be calculated
         * @return norm of the point
         */
        extern double norm(const Point &p);

        /*Computes the square of the norm of a point (basically, a vector starting from the origin)
         * @param p point which square norm will be calculated
         * @return norm of the point
         */
        extern double squareNorm(const Point &p);

        /* Determines the orientation of three points (counter clockwise or clockwise)
         * @param p q r points to operate
         * @return whether the points are oriented counter clockwise (positive) or clockwise (negative)
         */
        extern double orientation(const Point &p, const Point &q, const Point &r);

        /* Creates a number of points that discretize a circle arc
         * @param center center of the circle
         * @param radius radius of the circle
         * @param initAngle initial angle of the curve
         * @param endAngle final angle of the curve
         * @return vector with the points representing the curve
         */
        extern std::vector<Point> generateArcPoints(const Point &center, double radius, double initAngle, double endAngle);

        /* Check if a given triangle is valid (have three vertex, all different). Throws an error if not.
         * @param trianglePoints list of indexes of the triangle
         */
        extern void checkTriangleIntegrity(const std::vector<int> &trianglePoints);
    } // namespace delynoi_utilities
} // namespace Delynoi

#endif
