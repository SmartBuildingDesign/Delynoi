#ifndef DELYNOI_HOLE_H
#define DELYNOI_HOLE_H

#include <Delynoi/models/basic/IndexSegment.h>
#include <Delynoi/models/basic/Point.h>
#include <Delynoi/models/basic/Segment.h>
#include <vector>

namespace Delynoi {
    /*
     * Class that models a generic hole, which has a center and a list of points that define its boundary.
     */
    class Hole {
    protected:
        /*
         * Elements that define the hole, its points, center and segments.
         */
        std::vector<Point> HolePoints;
        Point center;
        std::vector<IndexSegment> segments;

    public:
        virtual ~Hole() = default;
        /*
         * Default constructor.
         */
        Hole() = default;

        /*
         * Constructor.
         */
        Hole(std::vector<Point> points, const Point &center, std::vector<IndexSegment> seg) {
            this->center = center;
            this->HolePoints.assign(points.begin(), points.end());
            this->segments.assign(seg.begin(), seg.end());
        }

        /*
         * Copy constructor.
         */
        Hole(const Hole &other) {
            this->center = other.center;
            this->HolePoints.assign(other.HolePoints.begin(), other.HolePoints.end());
            this->segments.assign(other.segments.begin(), other.segments.end());
        }

        /*
         * @return the center of the hole
         */
        virtual Point getCenter() {
            return this->center;
        }

        /*
         * @param s vector in which the hole segments will be set
         * @param offset value to add to the segment (representing that the hole could belong in a mesh with many points)
         */
        void getSegments(std::vector<IndexSegment> &s, const int offset) {
            for (const IndexSegment &seg: this->segments) {
                s.push_back(seg.add(offset));
            }
        }

        /*
         * @return list of points defining the hole
         */
        virtual std::vector<Point> getPoints() {
            return this->HolePoints;
        }

        /* Checks if a point is inside the hole
         * @param p point to check
         * @return if the point is inside the hole or not
         */
        bool containsPoint(const Point &point) {
            int j = HolePoints.size() - 1;
            bool oddNodes = false;

            for (int i = 0; i < HolePoints.size(); i++) {
                Point pI = HolePoints[i];
                Point pJ = HolePoints[j];

                if (pI == pJ) {
                    continue;
                }

                if (pI.getY() <= point.getY() && pJ.getY() > point.getY() || pJ.getY() <= point.getY() && pI.getY() > point.getY()) {

                    if (pI.getX() + (point.getY() - pI.getY()) / (pJ.getY() - pI.getY()) * (pJ.getX() - pI.getX()) < point.getX()) {
                        oddNodes = !oddNodes;
                    }
                }
                j = i;
            }

            if (oddNodes) {
                return true;
            }

            IndexSegment container(-1, -1);
            std::vector<IndexSegment> _segments;
            this->getSegments(_segments, 0);

            for (auto &segment: _segments) {
                if (segment.contains(HolePoints, point)) {
                    container = segment;
                }
            }

            return container.getFirst() != -1 && container.getSecond() != -1;
        }
    };
} // namespace Delynoi

#endif
