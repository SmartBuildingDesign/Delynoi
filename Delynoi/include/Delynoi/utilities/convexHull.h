#ifndef DELYNOI_CONVEXHULL_H
#define DELYNOI_CONVEXHULL_H

#include <Delynoi/models/basic/Point.h>

/*
 * Namespace that contains all functions related to the computation of the convex hull.
 */
// ReSharper disable once CppEnforceNestedNamespacesStyle
namespace Delynoi { // Nested namespaces requires C++ std17. This is 14+ NOLINT(*-concat-nested-namespaces)
    namespace convex {
        /* Computes the convex hull of a set of points
         * @param points list of points which convex hull will be calculated
         * @param u list of points defining the upper convex hull
         * @param l list of points defining the lower convex hull
         */
        extern void convexHull(std::vector<Point> &points, std::vector<Point> &u, std::vector<Point> &l);

        /* Computes the pair of antipodal pairs of the points, through the rotating callipers algorithm
         * @param points point that will be processed
         * @return the list of antipodal pairs
         */
        extern std::vector<std::pair<Point, Point>> rotatingCalipers(std::vector<Point> &points);
    } // namespace convex
} // namespace Delynoi

#endif
