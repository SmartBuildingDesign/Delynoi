#ifndef DELYNOI_NEIGHBOURS_H
#define DELYNOI_NEIGHBOURS_H

#include <iostream>
#include <utilities/utilities.h>

class Neighbours {
private:
    int n1;
    int n2 = -1;
public:
    Neighbours();
    Neighbours(int i1);
    Neighbours(int i1, int i2);
    Neighbours(Pair<int> p);
    void setNeighbour(int i);
    bool isNeighbour(int i);
    int getFirst() const;
    int getSecond() const;
    int getOther(int n);
    std::string getString() const;
    bool operator==(const Neighbours& other) const;
};


#endif 