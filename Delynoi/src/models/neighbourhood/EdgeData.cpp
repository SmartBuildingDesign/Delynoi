#include <Delynoi/models/neighbourhood/EdgeData.h>

using namespace Delynoi;

EdgeData::EdgeData(const int p1, const int p2) {
    this->p1 = p1;
    this->p2 = p2;
    this->t1 = -1;
    this->t2 = -1;
}

void EdgeData::setTriangle(const int t) {
    if (this->t1 == -1) {
        this->t1 = t;
    } else {
        this->t2 = t;
    }
}

std::string EdgeData::getString() const {
    return utilities::toString<double>(this->p1) + " " + utilities::toString<double>(this->p2);
}

bool EdgeData::operator==(const EdgeData &other) const {
    return this->p1 == other.p1 && this->p2 == other.p2 ||
           this->p2 == other.p1 && this->p1 == other.p2;
}
