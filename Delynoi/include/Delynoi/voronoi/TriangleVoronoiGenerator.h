#ifndef DELYNOI_TRIANGLEMESHGENERATOR_H
#define DELYNOI_TRIANGLEMESHGENERATOR_H

#include <Delynoi/models/Mesh.h>
#include <Delynoi/voronoi/TriangleDelaunayGenerator.h>
#include <Delynoi/voronoi/structures/DelaunayInfo.h>

namespace Delynoi {
    /*
     * Class in charge of creating the Voronoi diagram from the Delaunay triangulation.
     */
    class TriangleVoronoiGenerator {
    private:
        /*
         * Voronoi diagram in the format of a Delynoi mesh
         */
        Mesh<Polygon> voronoi;
        Mesh<Polygon> delaunay;

    public:
        /*
         * Constructor. Using the point list (seed points) and a domain it computes the Voronoi diagram and sets it in the
         * class member
         */
        TriangleVoronoiGenerator(std::vector<Point> &point_list, const Region &region, bool ignoreInvalidTriangles = false);

        /*
         * @return voronoi diagram
         */
        Mesh<Polygon> &getMesh();

        /*
         * @return delaunay diagram
         */
        Mesh<Polygon> &getTriangulation();

        /*
         * Clear mesh data
         */
        void clear();
    };
} // namespace Delynoi

#endif
