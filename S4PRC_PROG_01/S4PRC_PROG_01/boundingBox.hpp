//
//  boundingBox.hpp
//  S4PRC_PROG_01
//
//  Created by Evan OLLIVIER on 18/09/2017.
//  Copyright © 2017 Evan OLLIVIER. All rights reserved.
//

#ifndef boundingBox_hpp
#define boundingBox_hpp
#include <array>
#include <stdexcept>
#include <iostream>
#include <vector>

namespace box {
    struct BoundingBox{
        int x, y, h, w;
    };
    
    BoundingBox make_BoundingBox(int x, int y, int h=0, int w=0);
  
    std::string tostring(BoundingBox boite);
  
    
    
    //3.2 Surcharge de fonctions et opérateurs
    //inline bool contains(BoundingBox boite, int a, int b);
  //  inline bool contains(BoundingBox inner, BoundingBox outer);
    
    inline bool contains(BoundingBox boite, int a, int b){
        /*
         a inf/eg a la largeur &&
         b inf/eg à la hauteur &&
         a > x
         b > y
         */
        if( boite.x + boite.w >= a // Xmax >= a
           && boite.y + boite.h >= b //Ymax >=b
           && boite.x <= a  // Xmin <=a
           && boite.y <= b){ //Ymin <=b
            return true;
        }else{
            return false;
        }
    }
    
    
    inline bool contains(BoundingBox inner, BoundingBox outer){
        
        /*Savoir si la boite inner est contenue dans la boite outer*/
        
        if(contains(outer, inner.x, inner.y) && contains(outer, inner.x+inner.w, inner.y+inner.h)){
            return true;
        }else{
            return false;
        }
        
        
        
    }
    
}


#endif /* boundingBox_hpp */
