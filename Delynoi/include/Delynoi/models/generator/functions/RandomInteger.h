#ifndef DELYNOI_RANDOMINTEGER_H
#define DELYNOI_RANDOMINTEGER_H

#include <Delynoi/models/generator/Functor.h>
#include <random>

namespace Delynoi {
    /*
     * Generates random integer numbers.
     */
    class Random_Integer final : public Functor {
    private:
        /*
        * Parameters for the number generation. Maximum and minimum possible values.
        */
        double min;
        double max;

        /*
      * Parameters for random integer number generation.
      */
        static std::default_random_engine rd;
        static std::mt19937 rng;
        std::uniform_int_distribution<> uni;

    public:
        /*
         * Constructor.
         */
        Random_Integer(double min, double max);

        /*
       * Applies the function (as this is random generation, the result does not use the argument).
       * @param x argument of the function
       * @return function result
       */
        double apply(double x) override;
    };
} // namespace Delynoi

#endif