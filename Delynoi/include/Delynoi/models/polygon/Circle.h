#ifndef DELYNOI_CIRCLE_H
#define DELYNOI_CIRCLE_H

#include <vector>
#include <Delynoi/models/basic/Point.h>
#include <cstdlib>
#include <cmath>
#include <Delynoi/utilities/geometryFunctions.h>
#include <Delynoi/utilities/delynoi_utilities.h>

namespace Delynoi {
/*
 * Class that models a circle using its center and its radius.
 */
    class Circle {
    protected:
        /*
         * Circle radius
         */
        double radius;
        /*
         * Circle center
         */
        Point center;
    public:
        /*
         * Constructor
         */
        Circle(double r, Point c);

        /* Generates points that represent the boundary of the circle
         * @return list of points that model the circle boundary
         */
        std::vector<Point> discretizeCircle();
    };
}

#endif