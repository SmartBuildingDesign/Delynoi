#ifndef UTILITIES_PAIR_H
#define UTILITIES_PAIR_H

namespace Delynoi {
    template<typename T>
    class Pair {
    public:
        T first;
        T second;

        Pair(T first, T second);

        Pair(const Pair &other);

        Pair();

        bool operator==(const Pair &other) const;

        bool operator<(const Pair &other) const;

        T dot(Pair other);

        Pair operator*(double other);

        Pair operator+(const Pair &other) const;
    };

    template<typename T>
    Pair<T>::Pair(T first, T second) {
        this->first = first;
        this->second = second;
    }

    template<typename T>
    Pair<T>::Pair(const Pair &other) {
        this->first = other.first;
        this->second = other.second;
    }

    template<typename T>
    Pair<T>::Pair() = default;

    template<typename T>
    bool Pair<T>::operator==(const Pair &other) const {
        return this->first == other.first && this->second == other.second;
    }

    template<typename T>
    T Pair<T>::dot(Pair other) {
        return this->first * other.first + this->second * other.second;
    }

    template<typename T>
    Pair<T> Pair<T>::operator*(const double other) {
        return Pair(this->first * other, this->second * other);
    }

    template<typename T>
    Pair<T> Pair<T>::operator+(const Pair &other) const {
        return Pair(this->first + other.first, this->second + other.second);
    }

    template<typename T>
    bool Pair<T>::operator<(const Pair &other) const {
        if (this->first == other.first) {
            return this->second < other.second;
        }

        return this->first < other.first;
    }
} // namespace Delynoi

#endif
