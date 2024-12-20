#ifndef VEAMY_CENTERTRIANGULATIONGENERATOR_H
#define VEAMY_CENTERTRIANGULATIONGENERATOR_H

#include <Delynoi/triangulation/TriangulationGenerator.h>

namespace Delynoi {
    /*
     * Class that triangulates a Polygon (necessarily convex) using its geometrical center.
     */
    class CenterTriangulationGenerator final : public TriangulationGenerator {
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