#include <Delynoi/utilities/Pair.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <random>
#include <regex>
#include <sstream> // Required for Mac-OS
#include <utility>
#include <vector>

// ReSharper disable once CppEnforceNestedNamespacesStyle
namespace Delynoi { // Nested namespaces requires C++ std17. This is 14+ NOLINT(*-concat-nested-namespaces)
    namespace utilities {
        std::string toStringWithPrecision(const double d, const int precision) {
            std::stringstream sstream;
            sstream << std::fixed << std::setprecision(precision);
            sstream << d;
            std::string s = sstream.str();

            return s;
        }

        int random_integer(const int min, const int max) {
            static std::random_device rd;
            static std::mt19937 rng(rd());
            // ReSharper disable once CppTemplateArgumentsCanBeDeduced
            std::uniform_int_distribution<int> uni(min, max); // Template required for MacOS

            return uni(rng);
        }

        std::string getPath() {
#if defined(_WIN64) || defined(_WIN32)
            std::string path = std::getenv("USERPROFILE");
            return path + "\\";
#elif defined(__linux__) || defined(__APPLE__)
            std::string path = std::getenv("HOME");
            return path + "/";
#endif
        }

        Pair<double> normalize(const Pair<double> &vector) {
            const double norm = std::sqrt(std::pow(vector.first, 2) + std::pow(vector.second, 2));

            return {vector.first / norm, vector.second / norm};
        }

        double radian(const double angle) {
            return angle * M_PI / 180;
        }

        double degrees(const double angle) {
            const double a = angle > 0 ? angle : 2 * M_PI + angle;
            return a * 180 / M_PI;
        }

        int hash32(int key) {
            constexpr int c2 = 0x27d4eb2d;
            key = key ^ 61 ^ key >> 16;
            key = key + (key << 3);
            key = key ^ key >> 4;
            key = key * c2;
            key = key ^ key >> 15;
            return key;
        }

        std::vector<std::string> split(std::string s, const std::regex &regex) {
            std::vector<std::string> result;

            std::sregex_token_iterator it(s.begin(), s.end(), regex, -1);

            for (const std::sregex_token_iterator reg_end; it != reg_end; ++it) {
                if (!it->str().empty())
                    result.push_back(it->str());
            }

            return result;
        }

        std::vector<std::string> splitBySpaces(std::string s) {
            return split(std::move(s), std::regex("\\s+"));
        }

        std::ifstream openFile(const std::string &fileName) {
            const std::string completeName = getPath() + fileName;
            std::ifstream infile(completeName);

            if (!infile.good()) {
                throw std::runtime_error("Could not open file. Please check path.");
            }

            return infile;
        }
    } // namespace utilities
} // namespace Delynoi
