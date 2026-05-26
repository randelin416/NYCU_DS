#ifndef __TRAITS_H__
#define __TRAITS_H__

#include <string>
#include "template_vector.h"

// TODO: Base Traits (e.g., for numbers)
template <typename T>
struct DataTraits {
    static T identity() {
        return T(); 
    }
    
    static T apply(T a, T b) {
        // Implement addition logic
    }
};

// TODO: Specialization for std::string
template <>
struct DataTraits<std::string> {
    static std::string identity() {
        // Return identity element for string
    }
    
    static std::string apply(std::string a, std::string b) {
        // Implement concatenation logic with ", "
    }
};

// Accumulator Class (Do not modify)
template <typename T, typename Traits = DataTraits<T>>
class Accumulator {
public:
    static T sum(MyVector<T>& vec) {
        T result = Traits::identity();
        for(int i = 0; i < vec.size(); ++i) {
            result = Traits::apply(result, vec[i]);
        }
        return result;
    }
};

#endif