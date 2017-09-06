#ifndef DELYNOI_MESH_H
#define DELYNOI_MESH_H

#include <delynoi/models/neighbourhood/SegmentMap.h>
#include <utilities/UniqueList.h>
#include <fstream>
#include <delynoi/models/polygon/Polygon.h>
#include <delynoi/models/neighbourhood/PointMap.h>

class Mesh{
protected:
    SegmentMap edges;
    PointMap pointMap;
    UniqueList<Point> points;
    std::vector<Polygon> polygons;
public:
    Mesh();
    Mesh(std::vector<Point> &p, std::vector<Polygon> &e, SegmentMap s, PointMap pM);
    Mesh(UniqueList<Point> p, std::vector<Polygon>& e, SegmentMap s, PointMap pM);
    Mesh(const Mesh& m);
    void printInStream(std::ofstream& file);
    void printInFile(std::string fileName);
    void createFromFile(std::string fileName);
    void createFromStream(std::ifstream& ofstream);

    std::vector<Polygon>& getPolygons();
    std::vector<Polygon> getPolygons() const;
    Polygon& getPolygon(int index);

    SegmentMap& getSegments();
    SegmentMap getSegments() const ;

    PointMap& getPointMap();
    PointMap getPointMap() const;

    UniqueList<Point>& getPoints();
    UniqueList<Point> getPoints() const;

    Point getPoint(int i);
    NeighboursBySegment getNeighbours(IndexSegment s);
};


#endif