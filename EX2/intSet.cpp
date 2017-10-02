
#include "intSet.hpp"




namespace prc {
    intset make_inset(const std::string name_init, const std::vector<int> values_init){
       
        intset result {std::move(name_init), std::move(values_init)};
        // std::cout << "~~~make_inset~~~\nVal: " << &result.values  << "\n";
        return result;
    }

    
    
    std::string to_string(const intset &jeu_d_entiers){
        
        std::string output = jeu_d_entiers.name;
        output+= " { ";
        for(int i = 0; i<jeu_d_entiers.values.size(); i++){
            if(i > 0){
                output+=",";
            }
            output+=std::to_string(jeu_d_entiers.values[i]);
        }
        output+="}";
        return output;
    }
    
    
    std::tuple<prc::intset, prc::intset> intersect(const intset a, const intset b){
        std::vector<int> intersection = {};
        std::vector<int> difference_symetrique = {};
        std::string intersection_name = a.name+"<I>"+b.name;
        std::string difference_name = a.name+"<U>"+b.name;
        
        for(int i=0; i< a.values.size(); i++){
            bool already_in = false;
            for(int j = 0; j < b.values.size(); j++){
                if(a.values[i] == b.values[j]){
                    already_in = true;
                }
            }
            
            if(already_in){
                intersection.push_back(a.values[i]);
                
                //std::cout << a.values[i] << "\n";
            }else{
                // std::cout << a.values[i] << "\n";
                difference_symetrique.push_back(a.values[i]);
            }
        }
        
        return std::make_tuple(make_inset(intersection_name, intersection), make_inset(difference_name, difference_symetrique));
        
    
    
    }
}
