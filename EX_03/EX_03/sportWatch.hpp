

#ifndef sportWatch_hpp
#define sportWatch_hpp

#include "rollingMean.hpp"
#include <tuple>

namespace s4prc{
    
    class SportsWatch{
        
    private:
        
        std::unique_ptr<RollingMean> vitesse_;
        std::unique_ptr<RollingMean> rythme_;
        std::unique_ptr<RollingMean> altitude_;
        
        
        
    public:
        
        SportsWatch(const SportsWatch &rhs);
        SportsWatch & operator=(const SportsWatch &rhs);
        
        SportsWatch(SportsWatch &&) =default;
        //le constructeur par déplacement utilisant sa définition automatiquement générée,
        SportsWatch & operator=(SportsWatch &&) =default;
       // l'opérateur d'affectation par déplacement utilisant sa définition automatiquement générée,
        ~SportsWatch() =default;
        
        SportsWatch(bool v=0, bool r=0, bool a=0):
        vitesse_ { v==1 ? new RollingMean : nullptr },
        rythme_ { r==1 ? new RollingMean : nullptr },
        altitude_ { a==1 ? new RollingMean : nullptr }
        {}
        
        
        
        std::tuple<double, double, double> mean() const{
         
            double v, r, a = {0};
            if(vitesse_){
                v=vitesse_->mean();
            }if(rythme_){
                r=rythme_->mean();
            }if(altitude_){
                a=altitude_->mean();
            }
        
            
        auto temp = std::make_tuple(v,r,a);
            return temp;
            
        }
        
        
        void sample(double v, double r, double a){
            
            if(vitesse_){
                vitesse_->sample(v);
            }if(rythme_){
                rythme_->sample(r);
            }if(altitude_){
                altitude_->sample(a);
            }
            
        }
        
        
        
        std::string list(){
            std::string output {"{{"};
            if(vitesse_){
                output+=vitesse_->list();
            }
            output+="}, {";
            if(rythme_){
                output+=rythme_->list();
            }
            output+="}, {";
            if(altitude_){
                output+=altitude_->list();
            };
            return output+"}}";
        }
        
        
        
    };

    
   
    
    
}

#endif /* sportWatch_hpp */
