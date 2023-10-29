#include "../include/functions.hpp"

double calculate_all_area(Vector<Figure*>& vec) {
  double area = 0;
  for (auto& el : vec) {
    area += static_cast<double>(*el);
  }

  return area;
}

void print_all_areas(Vector<Figure*>& vec) {
  std::cout << "areas of all figures: " << std::endl;
  
  for (auto& el : vec) {
    std::cout << static_cast<double>(*el) << ", ";
  }

  std::cout << std::endl;
}

void print_all_centres(Vector<Figure*>& vec) {
  std::cout << "centres of all figures: " << std::endl;

  for (auto& el : vec) {
    std::cout << el->calculate_centre() << ", ";
  }

  std::cout << std::endl;
}