

//----------------------------------------------------------------------------

#ifndef S4PRC_INIT_HPP
#define S4PRC_INIT_HPP 1

#include <string>

namespace s4prc {
    
    struct Init0
    {
        double d;
        int i;
        std::string s;
    };
    
    struct Init1
    {
        double d{12.34};
        int i{56};
        std::string s{"Init1"};
    };
    
    struct Init2
    {
        double d;
        int i;
        std::string s;
        
        Init2()
        : d{98.76}   // member initialiser list
        , i{54}
        , s{"Init2"}
        { /* (empty) constructor body */ }
    };
    
    struct Init3
    {
        double d;
        int i;
        std::string s;
        
        Init3(double in_d,
              int in_i,
              std::string in_s)
        : d{in_d} // member initialiser list
        , i{in_i}
        , s{in_s}
        { /* (empty) constructor body */ }
        
#if 1 // enable/disable during experimentation
        
        Init3()
        : Init3{ 34.56, 78, "Init3" } // delegating constructor
        { /* (empty) constructor body */ }
        
#endif
    };
    
} // namespace s4prc

#endif // S4PRC_INIT_HPP

//----------------------------------------------------------------------------

