#ifndef UTILITIES_UTILITIES_H
#define UTILITIES_UTILITIES_H

#include <Delynoi/utilities/Pair.h>
#include <algorithm>
#include <iomanip>
#include <regex>
#include <sstream>
#include <vector>

// ReSharper disable once CppEnforceNestedNamespacesStyle
namespace Delynoi { // Nested namespaces requires C++ std17. This is 14+ NOLINT(*-concat-nested-namespaces)
    namespace utilities {
        template<typename T>
        std::string toString(T a) {
            std::stringstream sstream;
            sstream << a;
            std::string s = sstream.str();

            return s;
        }

        template<typename T>
        int indexOf(const std::vector<T> &vector, T element) {
            const int pos = std::find(vector.begin(), vector.end(), element) - vector.begin();

            return pos < static_cast<int>(vector.size()) ? pos : -1;
        }

        template<typename T>
        int sign(T x) {
            return (x > 0) - (x < 0);
        }

        extern std::string toStringWithPrecision(double d, int precision);

        extern int hash32(int key);

        extern int random_integer(int min, int max);

        extern std::string getPath();

        extern Pair<double> normalize(const Pair<double> &vector);

        extern double radian(double angle);

        extern double degrees(double angle);

        extern std::vector<std::string> split(std::string s, const std::regex &regex);

        extern std::vector<std::string> splitBySpaces(std::string s);

        extern std::ifstream openFile(const std::string &fileName);
    } // namespace utilities
} // namespace Delynoi

#endif
