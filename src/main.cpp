#include "lib/colour.h"
#include <fstream>
#include <iostream>

int main() {

  // Image

  int image_width = 256;
  int image_height = 256;
  std::string filename{"img.ppm"};
  std::fstream s{filename, s.binary | s.trunc | s.in | s.out};
  if (!s.is_open()) {
    std::cout << "failed to open " << filename << '\n';
    return 1;
  }

  // Render

  s << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      auto c = Colour(double(i) / (image_width - 1),
                      double(j) / (image_height - 1), 0.0);
      WriteColour(s, c);
    }
  }
  s.close();
}
