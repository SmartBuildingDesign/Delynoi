#ifndef DELYNOI_POINTDATA_H
#define DELYNOI_POINTDATA_H

namespace Delynoi {
    /*
     * Class used dor the compuattion of the Voronoi diagram. It relates a point index to an edge index.
     */
    class PointData {
    public:
        /*
         * Point index and edge index
         */
        int point;
        int edge;

        /*
         * Constructor
         */
        explicit PointData(const int p) {
            this->point = p;
            this->edge = -1;
        }

        /* Sets an edge to the point, checking if it is a boundary one (they have prioirity for the Voronoi diagram
         * algorithm)
         * @param edge edge to check
         * @param marker flag indicating whether the segment is in the boundary or not
         */
        void setEdge(const int _edge, const int marker) {
            if (this->edge == -1 || marker == 1) this->edge = _edge;
        }
    };
} // namespace Delynoi

#endif
