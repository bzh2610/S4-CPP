//
//  main.cpp
//  S4PRC_PROG_01
//
//  Created by Evan OLLIVIER on 18/09/2017.
//  Copyright © 2017 Evan OLLIVIER. All rights reserved.
//
void test_BoundingBox();

#include "boundingBox.hpp"

static_assert(sizeof(box::BoundingBox)<=16, "Taille maximale du type BoundingBox depassee, (16bits)");


int main(int argc, const char * argv[]) {
    // insert code here...
    
    test_BoundingBox();
    return 0;
}



void test_BoundingBox(){
    
    std::cout << __func__ << "\n";
    auto boite = box::make_BoundingBox(5, 5, 5, 5);
    auto grosse_boite = box::make_BoundingBox(5, 5, 10, 5);
    
    
    std::cout << "La structure prend " << sizeof(boite) << "octets" << "\n";
    std::cout << tostring(boite) << "\n"; //ADL
    
    
    
    //test box contains a, b (points)
    int a=9, b=10;
     if(box::contains(boite, a, b)){
           std::cout << "(x,y) = ("<< a << "," << b <<") est dans" << tostring(boite)  << "\n";
     }else{
         std::cout << "(x,y) = ("<< a << "," << b <<") n'est pas dans" << tostring(boite)  << "\n";
     }
    
    a=10, b=15;
    if(box::contains(boite, a, b)){
        std::cout << "(x,y) = ("<< a << "," << b <<") est dans" << tostring(boite)  << "\n";
    }else{
        std::cout << "(x,y) = ("<< a << "," << b <<") n'est pas dans" << tostring(boite)  << "\n";
    }
    
    a=12, b=16;
    if(box::contains(boite, a, b)){
        std::cout << "(x,y) = ("<< a << "," << b <<") est dans" << tostring(boite)  << "\n";
    }else{
        std::cout << "(x,y) = ("<< a << "," << b <<") n'est pas dans" << tostring(boite)  << "\n";
    }
    
    
    
    
    
    
    //test box contains boite, boite
    
    boite = box::make_BoundingBox(5, 5, 5, 5);
    grosse_boite = box::make_BoundingBox(5, 5, 10, 5);
    
    if(contains(boite, grosse_boite)){
        std::cout << tostring(boite) << "est dans" << tostring(grosse_boite)  << "\n";
    }else{
         std::cout << tostring(boite) << "n'est pas dans" << tostring(grosse_boite)  << "\n";
    }
    
    

    boite = box::make_BoundingBox(5, 5, 5, 5);
    grosse_boite = box::make_BoundingBox(-5, -5, 15, 25);
    
    if(contains(boite, grosse_boite)){
        std::cout << tostring(boite) << "est dans" << tostring(grosse_boite)  << "\n";
    }else{
        std::cout << tostring(boite) << "n'est pas dans" << tostring(grosse_boite)  << "\n";
    }
    
    boite = box::make_BoundingBox(5, 5, 5, 5);
    grosse_boite = box::make_BoundingBox(-5, -5, 10, 10);
    
    if(contains(boite, grosse_boite)){
        std::cout << tostring(boite) << "est dans" << tostring(grosse_boite)  << "\n";
    }else{
        std::cout << tostring(boite) << "n'est pas dans" << tostring(grosse_boite)  << "\n";
    }
    
    
    std::cout << "~~~~~~~~~~~~~~~~~~~~\n TABLEAU DYNAMIQUE \n~~~~~~~~~~~~~~~~~~~~\n";
    std::vector<box::BoundingBox> toutes_les_boites {boite, grosse_boite};
    toutes_les_boites.push_back(box::make_BoundingBox(1, 2, 3, 4));
    int i = 1;
    int vector_size = (int)toutes_les_boites.size(); //sizeof(toutes_les_boites)/sizeof(toutes_les_boites[0]);
    std::cout << vector_size << " elements \n";
    while (vector_size - i >= 0){
        for(int j=0; j<=vector_size-i; j++){
            std::cout << tostring(toutes_les_boites[j]) << "\n";
        }
        std::cout << "\n";
        toutes_les_boites.erase(toutes_les_boites.end() - i);
        i++;
    }
    
    
    
    //if(boite)
    
}
