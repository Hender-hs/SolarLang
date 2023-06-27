#pragma once

#include <iostream>
#include <vector>

namespace SolarLang {

    template<typename T> class Vector
    {
    public:

        unsigned int indexState = 0;

        std::vector<T> getVector()
        {
            return _vector;
        };

        T getValue()
        {
            return _vector.at(indexState);
        }

        T next()
        {
            indexState++;
            return getValue();
        };

        T prev()
        {
            indexState--;
            return getValue();
        };

        void add(T value)
        {
            _vector.push_back(value);
        };

        void push_back(T value)
        {
            _vector.push_back(value);
        };

        void assign(std::vector<std::string> value)
        {
            _vector = value;
        };

        void assign(T value)
        {
            _vector = value;
        };

        T operator[](int index)
        {
            return _vector.at(index);
        };

    private:
        std::vector<T> _vector;
    };

}
