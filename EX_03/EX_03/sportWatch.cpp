#include "sportWatch.hpp"



namespace s4prc {
    SportsWatch::SportsWatch(const SportsWatch &rhs)
    : vitesse_{}
    , rythme_{}
    , altitude_{}
    {
        if(rhs.vitesse_)
        { vitesse_=std::make_unique<RollingMean>(*rhs.vitesse_); } // copy
        if(rhs.rythme_)
        { rythme_=std::make_unique<RollingMean>(*rhs.rythme_); } // copy
        if(rhs.altitude_)
        { altitude_=std::make_unique<RollingMean>(*rhs.altitude_); } // copy
    }
    
    
    
    
    SportsWatch &
    SportsWatch::operator=(const SportsWatch &rhs)
    {
       
        if(rhs.vitesse_)
        { vitesse_=std::make_unique<RollingMean>(*rhs.vitesse_); } // copy
        else
        { vitesse_.reset(); }
        if(rhs.rythme_)
        { rythme_=std::make_unique<RollingMean>(*rhs.rythme_); } // copy
        else
        { rythme_.reset(); }
        if(rhs.altitude_)
        { altitude_=std::make_unique<RollingMean>(*rhs.altitude_); } // copy
        else
        { altitude_.reset(); }
        return *this;
    }
    
}
