//----------------------------------------------------------------------------

#include "gravity.hpp"
#include <cmath>

namespace s4prc {
    
    Gravity::Gravity(double x,
                     double y,
                     double z)
    : Gravity() // delegating constructor
    {
        const double sqrMag=x*x+y*y+z*z; // square magnitude of input vector
        if(sqrMag!=0.0) // get rid of default values only if input vector is not null
        {
            const double factor=9.81/std::sqrt(sqrMag);
            xyz_={ x*factor, y*factor, z*factor }; // adjust magnitude
        }
    }
    
    void
    Gravity::reverse()
    {
        for(int i=0;i<int(xyz_.size());++i)
        { xyz_[i]=-xyz_[i]; }
    }
    
    void
    Gravity::set_(int index,
                  double value)
    {
        double sqrRemaining=0.0;
        for(int i=0;i<int(xyz_.size());++i)
        {
            if(i!=index)
            {
                const double v=xyz_[i];
                sqrRemaining+=v*v;
            }
        }
        if(sqrRemaining!=0.0)
        {
            const double mag=9.81;
            value=std::max(-mag,std::min(mag,value));
            const double factor=std::sqrt((mag*mag-value*value)/sqrRemaining);
            for(int i=0;i<int(xyz_.size());++i)
            { xyz_[i]=(i==index) ? value : xyz_[i]*factor; }
        }
    }
    
    std::ostream &
    operator<<(std::ostream &output,
               Gravity g)
    {
        return output << "{ " << g.x()
        << ", " << g.y()
        << ", " << g.z() << " }";
    }
    
} // namespace s4prc

