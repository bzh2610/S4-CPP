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
    inline Pixel operator*(const Pixel &pix,const double k)
    {
        Pixel r;
        r.r =static_cast<uint8_t>(pix.r*k);
        r.g =static_cast<uint8_t>(pix.g*k);
        r.b =static_cast<uint8_t>(pix.b*k);
        return r;
    }
    
    
    // Pixel <-- Pixel + Pixel
    inline Pixel operator+(const Pixel &pix1,const Pixel &pix2)
    {
        Pixel r;
        r.r = static_cast<uint8_t>(pix1.r+pix2.r);
        r.g = static_cast<uint8_t>(pix1.g+pix2.g);
        r.b = static_cast<uint8_t>(pix1.b+pix2.b);
        return r;
    }
    
    inline Pixel operator/(const Pixel &pix1,const double k)
    {
        Pixel r;
        r.r = static_cast<uint8_t>(pix1.r/k);
        r.g = static_cast<uint8_t>(pix1.g/k);
        r.b = static_cast<uint8_t>(pix1.b/k);
        return r;
    }
    
    
    
    // Pixel <-- Pixel << int
    inline Pixel operator<<(const Pixel &pix, const int k)
    {
        Pixel r;
        r.r = static_cast<uint8_t>(pix.r<<(k));
        r.g = static_cast<uint8_t>(pix.g<<(k));
        r.b = static_cast<uint8_t>(pix.b<<(k));
        return r;
    }
    
    
    // Pixel <-- Pixel >> int
    inline Pixel operator>>(const Pixel &pix, const int k)
    {
        Pixel r;
        r.r = static_cast<uint8_t>(pix.r>>(k));
        r.g = static_cast<uint8_t>(pix.g>>(k));
        r.b = static_cast<uint8_t>(pix.b>>(k));
        return r;
    }
    
    // Pixel <-- Pixel & int
    inline Pixel operator&(const Pixel &pix,const int k)
    {
        Pixel r;
        r.r = static_cast<uint8_t>(pix.r & k);
        r.g = static_cast<uint8_t>(pix.g & k);
        r.b = static_cast<uint8_t>(pix.b & k);
        return r;
    }
    
    
    // Pixel <-- Pixel | int
    inline Pixel operator|(const Pixel &pix,const int k)
    {
        Pixel r;
        r.r = static_cast<uint8_t>(pix.r | k);
        r.g = static_cast<uint8_t>(pix.g | k);
        r.b = static_cast<uint8_t>(pix.b | k);
        return r;
    }
    
    inline Pixel operator|(const Pixel &pix, const Pixel &pix2)
    {
        Pixel r;
        r.r = pix.r | pix2.r;
        r.g = pix.g | pix2.g;
        r.b = pix.b | pix2.b;
        return r;
    }


// merge pixels from image1 with pixels from image2
// - image1 is read-only and has dimensions w1*h1
// - image2 is read-only and has dimensions w2*h2
// - resulting image has dimensions w1*h1
// using a generic merge operation on pixels
// - Pixel <-- oper(Pixel, Pixel)


} // namespace img

#endif // IMG_PIXEL_HPP

//----------------------------------------------------------------------------
