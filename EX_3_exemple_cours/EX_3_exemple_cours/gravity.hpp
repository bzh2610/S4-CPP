//----------------------------------------------------------------------------

#ifndef S4PRC_GRAVITY_HPP
#define S4PRC_GRAVITY_HPP 1

#include <array>
#include <iostream>

namespace s4prc {
    
    class Gravity
    {
    public:
        
        Gravity()
        : xyz_{ { 0.0, 0.0, -9.81 } }
        { }
        
        Gravity(double x,
                double y,
                double z);
        
        double
        x() const
        { return xyz_[0]; }
        
        double
        y() const
        { return xyz_[1]; }
        
        double
        z() const
        { return xyz_[2]; }
        
        void
        reverse();
        
        void
        setX(double x)
        { set_(0,x); }
        
        void
        setY(double y)
        { set_(1,y); }
        
        void
        setZ(double z)
        { set_(2,z); }
        
    private:
        void
        set_(int index,
             double value);
        
        std::array<double,3> xyz_;
    };
    
    std::ostream &
    operator<<(std::ostream &output,
               Gravity g);
    
    inline
    Gravity
    opposite(Gravity g)
    {
        g.reverse();
        return g;
    }
    
} // namespace s4prc

#endif // S4PRC_GRAVITY_HPP

//-----------------------------------------------------------------------
