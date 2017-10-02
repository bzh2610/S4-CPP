
#include "intSet.hpp"

void test_IntSet();

int main(int argc, const char * argv[]) {
    test_IntSet();
    return 0;
}


void test_IntSet(){
    std::cout << __func__ << "\n";
    
    prc::intset a = prc::make_inset("A", {1,2,3,4,5}); // On réalise une copie des valeurs
    std::cout << "INTSET: \nVal adresse " << &a.values << "\n";
    std::cout << to_string(a) << "\n";

    prc::intset b = prc::make_inset("B", {3,4,5,6,7});
    std::cout << to_string(b) << "\n";
    
    a+=b;
    
   // std::cout << to_string(a) << "\n";
    
    auto output = intersect(a, b);
    prc::intset one = std::get<0>(output);
    prc::intset two = std::get<1>(output);
    

  std::cout << "Intersection : " <<to_string(one) << "\nDifférence" << to_string(two) << "\n";
}
