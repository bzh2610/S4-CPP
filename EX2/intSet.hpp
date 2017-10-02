
#ifndef intSet_hpp
#define intSet_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>


namespace prc {

    struct intset
    {
        std::string name;
        std::vector<int> values;
    };
    
    
    

    
    intset make_inset( std::string name_init, std::vector<int> values_init);
   
    std::string to_string(const intset &jeu_d_entiers);
    
    inline intset operator+=(const intset &a_modifier,
                             const intset &v){
        
        std::string name= a_modifier.name + "<U>" + v.name;
        std::vector<int> valeurs = {};
        

        for(int i=0; i< v.values.size(); i++){
            bool not_in = true;
            for(int j = 0; j < a_modifier.values.size(); j++){
                if(a_modifier.values[j] == v.values[i]){
                    not_in = false;
                }
            }
            
            if(not_in){
                valeurs.push_back(v.values[i]);
            }
        }
        
        intset output = make_inset(name, valeurs);
        
        return output;
    }
    
    std::tuple<prc::intset, prc::intset> intersect(const intset a, const intset b);
    
    
}
#endif /* intSet_hpp */
