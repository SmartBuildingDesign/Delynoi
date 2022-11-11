#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "modernize-concat-nested-namespaces"

#include <Delynoi/models/generator/Functor.h>
#include <Delynoi/models/generator/functions/RandomDouble.h>
#include <Delynoi/models/generator/functions/RandomInteger.h>
#include "FunctorClasses.cpp"

namespace Delynoi {
    namespace functions {
        Functor *constant() {
            return new Uniform(1.0);
        }

        Functor *displace_points(double delta) {
            return new DisplaceDelta(delta);
        }

        Functor *constantAlternating() {
            return new ConstantAlternating();
        }

        Functor *uniform(double delta) {
            return new Uniform(delta);
        }

        Functor *sine(double amplitude, double frecuency, double phase) {
            return new Sine(amplitude, frecuency, phase);
        }

        Functor *cosine(double amplitude, double frecuency, double phase) {
            return new Cosine(amplitude, frecuency, phase);
        }

        Functor *random_integer(double min, double max) {
            return new Random_Integer(min, max);
        }

        Functor *random_double(double min, double max) {
            return new Random_Double(min, max);
        }
    }
}

#pragma clang diagnostic pop