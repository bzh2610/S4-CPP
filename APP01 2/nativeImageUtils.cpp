//----------------------------------------------------------------------------

#if defined _WIN32
# define NATIVE_IMAGE_UTILS_API extern "C" __declspec(dllexport)
#else
# define NATIVE_IMAGE_UTILS_API extern "C"
#endif

#include <cstdint>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "pixel.hpp"

//----------------------------------------------------------------------------
// Minimal function called from Python
//----------------------------------------------------------------------------

NATIVE_IMAGE_UTILS_API
int
hello(const char *msg)
{
  std::string s{msg};
  int result=int(s.size());
  std::cout << "native hello() received '" << msg
            << "' and is about to return " << result << '\n';
  return result;
}

//----------------------------------------------------------------------------
// Blend images
//----------------------------------------------------------------------------

NATIVE_IMAGE_UTILS_API
void
imgBlend(int w1,               // first input image (and result) width
         int h1,               // first input image (and result) height
         const img::Pixel *d1, // first input image pixels (w1*h1)
         int w2,               // second input image width
         int h2,               // second input image height
         const img::Pixel *d2, // second input image pixels (w2*h2)
         int k,                // cursor value within range [0;100]
         img::Pixel *d)        // resulting image pixels (w1*h1)
{
  (void)w1; (void)h1; (void)d1; // avoid ``unused parameter'' warnings
  (void)w2; (void)h2; (void)d2;
  (void)k; (void)d;

  // ... À COMPLÉTER ...
  //
  // renseigner les `w1*h1' pixels de `d'
  //

    
    
    std::uint8_t red {(uint8_t)200};// {(uint8_t) (rand() % 255 )};
    std::uint8_t green {(uint8_t)50};//{(uint8_t) (rand() % 255) };
    std::uint8_t blue {(uint8_t)10};//{(uint8_t) (rand() % 255) };

    
    
#if 0 // uniform colour

    std::for_each(d, d+h1*w1, [&red, &blue, &green](auto &p){
        
        p.r = red;
        p.g = green;
        p.b = blue;
        
    });
#elif 0 // uniform colour dimmed according to k


    // On renseigne l'opérateur *
    
    
    std::for_each(d, d+h1*w1, [&red, &blue, &green, &k](auto &p){
        p.r = red;
        p.g = green;
        p.b = blue;
        p = p*(k/100.0);
    });
    
    
    
#elif 0 // copy of d1 dimmed according to k
    std::transform(d1, d1+h1*w1, d, [&k](auto &p){
        img::Pixel pixel;
        pixel.r = p.r;
        pixel.g = p.g;
        pixel.b = p.b;
        pixel = pixel*(1-(k/100.0));
        return pixel;
    });
    

#elif 1 // full problem (hardcoded loops)

    

    for(int i = 0; i<w1; i++){
        for(int j = 0; j<h1; j++){
            d+i*j=d+i*j*k+
        }
    }
    
#else // full problem (generic loops)


#endif
}

//----------------------------------------------------------------------------
// Reveal an image hidden into another one
//----------------------------------------------------------------------------

NATIVE_IMAGE_UTILS_API
void
imgReveal(int w1,               // input image (and result) width
          int h1,               // input image (and result) height
          const img::Pixel *d1, // input image pixels (w1*h1)
          int k,                // cursor value within range [0;8]
          img::Pixel *d)        // resulting image pixels (w1*h1)
{
  (void)w1; (void)h1; (void)d1; // avoid ``unused parameter'' warnings
  (void)k; (void)d;

  // ... À COMPLÉTER ...
  //
  // renseigner les `w1*h1' pixels de `d'
  //

  // similar to copy of d1 dimmed according to k

}

//----------------------------------------------------------------------------
// Hide an image into another one
//----------------------------------------------------------------------------

NATIVE_IMAGE_UTILS_API
void
imgHide(int w1,               // first input image (and result) width
        int h1,               // first input image (and result) height
        const img::Pixel *d1, // first input image pixels (w1*h1)
        int w2,               // second input image width
        int h2,               // second input image height
        const img::Pixel *d2, // second input image pixels (w2*h2)
        int k,                // cursor value within range [0;8]
        img::Pixel *d)        // resulting image pixels (w1*h1)
{
  (void)w1; (void)h1; (void)d1; // avoid ``unused parameter'' warnings
  (void)w2; (void)h2; (void)d2;
  (void)k; (void)d;

  // ... À COMPLÉTER ...
  //
  // renseigner les `w1*h1' pixels de `d'
  //

  // similar to blending

}

//----------------------------------------------------------------------------
