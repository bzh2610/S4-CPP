//----------------------------------------------------------------------------

#ifndef S4PRC_EXPRNODE_HPP
#define S4PRC_EXPRNODE_HPP 1

#include <string>
#include <memory>
#include <iostream>

namespace s4prc {
    
    class ExprNode
    {
    public:
        
        ExprNode(std::string content,
                 std::unique_ptr<ExprNode> left=nullptr,
                 std::unique_ptr<ExprNode> right=nullptr);
        
        ExprNode(const ExprNode &rhs);
        ExprNode & operator=(const ExprNode &rhs);
        ExprNode(ExprNode &&rhs) =default;
        ExprNode & operator=(ExprNode &&rhs) =default;
        ~ExprNode() =default;
        
        double
        eval() const;
        
        friend
        std::ostream &
        operator<<(std::ostream &output,
                   const ExprNode &n);
        
    private:
        std::string content_;
        std::unique_ptr<ExprNode> left_;
        std::unique_ptr<ExprNode> right_;
    };
    
} // namespace s4prc

#endif // S4PRC_EXPRNODE_HPP

//----------------------------------------------------------------------------
