#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#include "containers/Vector.hpp"
#include "interfaces/figure.hpp"

double calculate_all_area(Vector<Figure*>& vec);

void print_all_areas(Vector<Figure*>& vec);

void print_all_centres(Vector<Figure*>& vec);

#endif