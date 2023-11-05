#include "functions.h"

inline double calculate_all_area(mystd::Vector<std::shared_ptr<Figure<double>>>& vec) {
  double area = 0;
  for (auto& el : vec) {
    area += static_cast<double>(*el);
  }

  return area;
}

inline void print_all_areas(mystd::Vector<std::shared_ptr<Figure<double>>>& vec) {
  std::cout << "areas of all figures: " << std::endl;
  
  for (auto& el : vec) {
    std::cout << static_cast<double>(*el) << ", ";
  }

  std::cout << std::endl;
}

inline void print_all_centres(mystd::Vector<std::shared_ptr<Figure<double>>>& vec) {
  std::cout << "centres of all figures: " << std::endl;

  for (auto& el : vec) {
    std::cout << el->calculate_centre() << ", ";
  }

  std::cout << std::endl;
}