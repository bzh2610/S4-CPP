//----------------------------------------------------------------------------

#ifndef IMG_PIXEL_HPP
#define IMG_PIXEL_HPP 1

#include <cstdint>

namespace img {

struct Pixel 
{
  std::uint8_t r{}, g{}, b{};
};


    

    
    // Pixel <-- Pixel * double
    // Eg : Pixel a  = pixelb * 0.89
    inline Pixel operator *(const Pixel &p, const double d){
        Pixel sortie;
        
        sortie.r = (std::uint8_t)(p.r*d);
        sortie.g = (std::uint8_t)(p.g*d);
        sortie.b = (std::uint8_t)(p.b*d);
        
        return sortie;
    }
    
    // Pixel <-- Pixel + Pixel

    inline Pixel operator +(const Pixel &p, const Pixel &q){
        Pixel sortie;
        
        sortie.r = (std::uint8_t)((p.r+q.r)/2);
        sortie.g = (std::uint8_t)((p.g+q.g)/2);
        sortie.b = (std::uint8_t)((p.b+q.b)/2);
        
        return sortie;
    }
    
    // Pixel <-- Pixel << int

    
    
    // Pixel <-- Pixel >> int

    
    // Pixel <-- Pixel & int

    
    
    // Pixel <-- Pixel | int



// merge pixels from image1 with pixels from image2
// - image1 is read-only and has dimensions w1*h1
// - image2 is read-only and has dimensions w2*h2
// - resulting image has dimensions w1*h1
// using a generic merge operation on pixels
// - Pixel <-- oper(Pixel, Pixel)


} // namespace img

#endif // IMG_PIXEL_HPP

//----------------------------------------------------------------------------
