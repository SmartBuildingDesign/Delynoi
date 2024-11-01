#ifndef DELYNOI_EARTRIANGULATIONGENERATOR_H
#define DELYNOI_EARTRIANGULATIONGENERATOR_H

#include <Delynoi/triangulation/TriangulationGenerator.h>

namespace Delynoi {
    /*
     * Class that triangulates a polygon using the classic ear triangulation scheme.
     */
    class EarTriangulationGenerator final : public TriangulationGenerator {
    private:
        /* Gets an independant ear out of the polygon
         * @param point mesh points
         * @param pointList list of points of the polygon
         * @return a triangle (an ear of the polygon)
         */
        static Triangle getEar(const std::vector<Point> &points, std::vector<int> &pointList);

    public:
        /* Triangulates a polygon.
        * @param p polygon to triangulate
        * @param points list of points instances which the polygon points reference to (most likely, mesh points)
        * @return list of triangles obtained triangulating the polygon
        */
        std::vector<Triangle> triangulate(Polygon p, std::vector<Point> &points) override;
    };
} // namespace Delynoi

#endif