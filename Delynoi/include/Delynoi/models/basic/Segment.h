// ReSharper disable CppFunctionIsNotImplemented
#ifndef DELYNOI_SEGMENT_H
#define DELYNOI_SEGMENT_H

#include <Delynoi/models/basic/Point.h>

namespace Delynoi {
    /*
     * Template class that encapsulates all behaviour common to segments, no matter how they are represented.
     */
    template<class T>
    class Segment {
    protected:
        /*
         * Endpoints of the segment
         */
        T p1;
        T p2;

        /*
         * @return the length of the segment
         */
        static double length(const Point &_p1, const Point &_p2);

        /*
         * Determines whether four points (defining two line segments) intersect or not, and set as the last value the intersection
         * point if they intersect.
         * @param p1 p2 points defining first segment
         * @param o1 o2 points defining second segment
         * @param inter intersection point (only valid if segments intersect)
         * @return segments intersect or not
         */
        static bool intersects(const Point &_p1, const Point &_p2, const Point &o1, const Point &o2, Point &inter);

        /*
         * @return angle of the line segment in degrees.
         */
        static double cartesianAngle(const Point &_p1, const Point &_p2);

        /*
         * Determines whether four points (defining two infinite lines) intersect or not (it is always the case unless they are parallel).
         * Sets the intersection point in the fifth given point.
         * * @param p1 p2 points defining first line
         * @param o1 o2 points defining second line
         * @param inter intersection point (only valid if lines intersect)
         * @return lines intersect or not
         */
        virtual bool intersectionInfinite(Point _p1, Point _p2, Point o1, Point o2, Point &inter);

        /*
         * Determines whether a point is contained in a segment.
         * @param point  point to check
         * @param p1 p2 points defining a segment
         * @return whether the point is contained or not
         */
        bool contains(const Point &point, const Point &_p1, const Point &_p2) const;

    public:
        virtual ~Segment() = default;
        /*
         * Constructor. Empty segment.
         */
        Segment();

        /*
         * Constructor. Segment with two endpoints.
         */
        Segment(T p1, T p2);

        /*
         * @return the first endpoint.
         */
        T getFirst() const;

        /*
         * @return the second endpoint.
         */
        T getSecond() const;

        /*
         * Virtual method. Returns the string representation of the segment.
         * @return string representing the segment as a pair
         */
        virtual std::string getString() const = 0;

        /*
         * Determines if a value is one of the two endpoints of the segment.
         * @param p value to check
         * @return is it a vertex or not
         */
        bool isVertex(T p);
    };
} // namespace Delynoi

#endif
