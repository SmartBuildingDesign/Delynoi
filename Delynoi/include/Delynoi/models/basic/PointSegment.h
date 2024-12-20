#ifndef DELYNOI_POINTSEGMENT_H
#define DELYNOI_POINTSEGMENT_H

#include <Delynoi/models/basic/Point.h>
#include <Delynoi/models/basic/Segment.h>

namespace Delynoi {
    /*
     * This class models a segment which endpoints are represented by the points directly.
     */
    class PointSegment final : public Segment<Point> {
    public:
        /*
         * Constructor. Creates a segment with two endpoints.
         */
        PointSegment(const Point &p1, const Point &p2);

        /*
         * Constructor. Creates an empty segment.
         */
        PointSegment();

        /*
         * @return the length of the segment
         */
        double length() const;

        /*
         * Determines whether a point is contained in the segment.
         * @param point  point to check
         * @return whether the point is contained or not
         */
        bool contains(const Point &point) const;

        /*
        * Returns the string representation of the segment.
        * @return string representing the segment as a pair
        */
        std::string getString() const override;

        /*
       * @return angle of the line segment in degrees.
       */
        double cartesianAngle() const;

        /* Equality operator.
         * @param other segment to compare
         * @return are the two segments equal or not
         */
        bool operator==(const PointSegment &other) const;
    };
} // namespace Delynoi

#endif
