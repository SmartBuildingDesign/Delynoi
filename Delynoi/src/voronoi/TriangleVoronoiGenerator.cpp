#include <Delynoi/voronoi/DelaunayToVoronoi.h>
#include <Delynoi/voronoi/TriangleVoronoiGenerator.h>

using namespace Delynoi;

TriangleVoronoiGenerator::TriangleVoronoiGenerator(const std::vector<Point> &point_list, const Region &region, const bool ignoreInvalidTriangles) {
    TriangleDelaunayGenerator delaunayGenerator(point_list, region);
    DelaunayInfo _delaunay = delaunayGenerator.getConformingDelaunay();

    this->delaunay = delaunayGenerator.initializeMesh<Polygon>(ignoreInvalidTriangles);
    this->voronoi = DelaunayToVoronoi(_delaunay).getMesh();
}

Mesh<Polygon> &TriangleVoronoiGenerator::getMesh() {
    return this->voronoi;
}

Mesh<Polygon> &TriangleVoronoiGenerator::getTriangulation() {
    return this->delaunay;
}

void TriangleVoronoiGenerator::clear() const {
    this->voronoi.clear();
    this->delaunay.clear();
}
