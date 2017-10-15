//----------------------------------------------------------------------------

#ifndef S4PRC_WORDPOOL_HPP
#define S4PRC_WORDPOOL_HPP 1

#include <vector>
#include <string>

namespace s4prc {
    
    class WordPool
    {
    public:
        
        WordPool(int wordCount,
                 int maxLength);
        
#if 1 //-- disable copy, enable default move and destructor --
        WordPool(const WordPool &) =delete;
        WordPool & operator=(const WordPool &) =delete;
        WordPool(WordPool &&) =default;
        WordPool & operator=(WordPool &&) =default;
        ~WordPool() =default;
#endif
        
        int
        maxLength() const
        { return maxLength_; }
        
        int
        size() const
        { return int(words_.size()); }
        
        std::string
        operator[](int idx) const
        { return words_[idx]; }
        
    private:
        int maxLength_;
        std::vector<std::string> words_;
    };
    
} // namespace s4prc

#endif // S4PRC_WORDPOOL_HPP

//----------------------------------------------------------------------------
