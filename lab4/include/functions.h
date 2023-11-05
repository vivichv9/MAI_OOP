#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#include "Vector.h"
#include "Figure.h"

inline double calculate_all_area(mystd::Vector<std::shared_ptr<Figure<double>>>& vec);

inline void print_all_areas(mystd::Vector<std::shared_ptr<Figure<double>>>& vec);

inline void print_all_centres(mystd::Vector<std::shared_ptr<Figure<double>>>& vec);

#endif