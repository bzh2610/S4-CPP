//----------------------------------------------------------------------------

#include "wordPool.hpp"
#include <random>

namespace s4prc {
    
    WordPool::WordPool(int wordCount,
                       int maxLength)
    : maxLength_{maxLength}
    , words_{}
    {
        std::default_random_engine rndGen{std::random_device{}()};
        std::uniform_int_distribution<int> lengthDistrib{1,maxLength};
        std::uniform_int_distribution<int> charDistrib{'A','Z'};
        words_.reserve(wordCount);
        for(int i=0;i<wordCount;++i)
        {
            const int length=lengthDistrib(rndGen);
            std::string s;
            s.reserve(length);
            for(int i=0;i<length;++i)
            { s+=char(charDistrib(rndGen)); }
            words_.emplace_back(std::move(s));
        }
    }
    
} // namespace s4prc

//----------------------------------------------------------------------------
