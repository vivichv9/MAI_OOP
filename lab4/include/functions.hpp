#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#include "../containers/Vector.hpp"
#include "interfaces/Figure.hpp"
#include "../src/Point.cpp"

double calculate_all_area(Vector<std::shared_ptr<Figure<double>>>& vec);

void print_all_areas(Vector<std::shared_ptr<Figure<double>>>& vec);

void print_all_centres(Vector<std::shared_ptr<Figure<double>>>& vec);

#endif