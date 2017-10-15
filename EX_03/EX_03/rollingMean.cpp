//
//  rollingMean.cpp
//  EX_03
//
//  Created by Evan OLLIVIER on 14/10/2017.
//  Copyright © 2017 Evan OLLIVIER. All rights reserved.
//

#include "rollingMean.hpp"



namespace s4prc {
    std::ostream &
    operator<<(std::ostream &output,
               RollingMean &r)
    {
        return output << "{" << r.count() << " samples with mean " << r.mean() << "}";
        
    }

}
