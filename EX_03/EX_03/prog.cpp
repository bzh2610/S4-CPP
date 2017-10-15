//
//  main.cpp
//  EX_03
//
//  Created by Evan OLLIVIER on 14/10/2017.
//  Copyright © 2017 Evan OLLIVIER. All rights reserved.
//
#include "rollingMean.hpp"
#include "sportWatch.hpp"

void test_rollingMean(){
       std::cout << __func__ << "\n";
    s4prc::RollingMean i3a{ {1.0, 2.0, 3.0, 4.12} };
    std::cout << i3a.list() << "\n" << i3a << "\n";
    i3a.sample(6.5);
    std::cout << i3a.list() << "\n" << i3a << "\n";
    i3a.sample(7.5);
    std::cout << i3a.list() << "\n" << i3a << "\n";
    
    std::cout << "\n\n";
    
    s4prc::RollingMean i3b;
    std::cout << i3b.list() << "\n" << i3b << "\n";
    s4prc::fill(3.14, i3b);
    std::cout << i3b.list() << "\n" << i3b << "\n";
}

void  test_smartWatch(){
    std::cout <<"\n" << __func__ << "\n";
    s4prc::SportsWatch first(1,1,1);
    std::cout << first.list() << "\n";
    std::cout<< "Mean "<< std::get<0>(first.mean()) <<" ,"<< std::get<1>(first.mean()) <<" ,"<< std::get<2>(first.mean()) <<"\n";
    
    first.sample(1,2,3);
    std::cout << first.list() << "\n";
    std::cout<< "Mean "<< std::get<0>(first.mean()) <<" ,"<< std::get<1>(first.mean()) <<" ,"<< std::get<2>(first.mean()) <<"\n";
    
    
    std::cout <<"\n" << "2.2 Recopie" << "\n\n";
    s4prc::SportsWatch second {std::move(first)};
    //On vérifie que la 1ere ne se modifie plus
    first.sample(4,5,6);
    std::cout << first.list() << "\n";
    //On vérifie que la 2e est comme la 1ere
    std::cout << second.list() << "\n";
    std::cout<< "Mean "<< std::get<0>(second.mean()) <<" ,"<< std::get<1>(second.mean()) <<" ,"<< std::get<2>(second.mean()) <<"\n";
  
    
    s4prc::SportsWatch third = second;
    std::cout << third.list() << "\n";
    std::cout<< "Mean "<< std::get<0>(third.mean()) <<" ,"<< std::get<1>(third.mean()) <<" ,"<< std::get<2>(third.mean()) <<"\n";
//  Hophophop ça ne marche pas


}


int main() {
    test_rollingMean();
    test_smartWatch();
    return 0;
}
