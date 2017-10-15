//
//  rollingMean.hpp
//  EX_03
//
//  Created by Evan OLLIVIER on 14/10/2017.
//  Copyright © 2017 Evan OLLIVIER. All rights reserved.
//

#ifndef rollingMean_hpp
#define rollingMean_hpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdexcept>
#include <string>

namespace s4prc {
   
   
    
    class RollingMean
    {
    private:
        std::vector<double> series_;
        int next_key_;
        
        
    public:
        
        RollingMean(std::vector<double> series_d)
        :
        series_{std::move(series_d)},
        next_key_{0}
        {
            if(series_.size()==0){
                throw std::runtime_error{"Empty array"};
            }
        }
        
        
        
        
        
        RollingMean(int taille = 5)
        :
        series_{ std::vector<double> (taille)},
        next_key_{0}
        {  }
    
        int count () const { return (int)series_.size(); }
        double mean() const {
            double total=0;
            for(int i=0; i<count(); i++){
                total+=series_[i];
            }
            return total/(double)count();
        }
        
        void sample(double val){
            series_[next_key_]=val;
            next_key_=(next_key_+1)%count();
        }
        

        std::string list(){
            std::string output {"{"};
            for(int i=0; i<count(); i++){
                output+=std::to_string(series_[i])+", ";
            }
            return output+"}";
        }
        

    };
    
    std::ostream &
    operator<<(std::ostream &output,
               RollingMean &r);
    
    
    
    inline void fill(double val, RollingMean &r){
        for(int i=0; i<=r.count(); i++){
            r.sample(val);
        }
    }
    
   
    
}

#endif /* rollingMean_hpp */
