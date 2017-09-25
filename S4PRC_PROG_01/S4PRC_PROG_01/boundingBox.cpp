//
//  boundingBox.cpp
//  S4PRC_PROG_01
//
//  Created by Evan OLLIVIER on 18/09/2017.
//  Copyright © 2017 Evan OLLIVIER. All rights reserved.
//


#include "boundingBox.hpp"

namespace box {

    
    BoundingBox make_BoundingBox(int x, int y, int h, int w){
         if( h <0 || w <0){
        throw std::runtime_error{"Hauteur / Largeur negative"};
         }
        /*try{
            if( h <0 || w <0){
                throw "Hauteur / Largeur négative";
            }
        }catch(const char *message){
            std::cerr << message << "\n";
            std::exit(1);
        }*/
        
        
        return BoundingBox{x, y, h, w};
    }
    
    std::string tostring(BoundingBox boite){
        std::string output = "BoundingBox{ x=" + std::to_string(boite.x) + ", y=" + std::to_string(boite.y) + ", h=" + std::to_string(boite.h)+ ", w="+std::to_string(boite.w)+ " }";
        
        return output;
    }
    
   
    
    
}
