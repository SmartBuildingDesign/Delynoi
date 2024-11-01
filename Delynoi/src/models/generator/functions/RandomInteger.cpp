#include <Delynoi/models/generator/functions/RandomInteger.h>

using namespace Delynoi;

std::default_random_engine Random_Integer::rd; // NOLINT(*-msc51-cpp)
std::mt19937 Random_Integer::rng(rd());

Random_Integer::Random_Integer(const double min, const double max) {
    this->min = min;
    this->max = max;
    this->uni = std::uniform_int_distribution<>(min, max);
}

double Random_Integer::apply(double x) {
    return (uni) (rng);
}
