//----------------------------------------------------------------------------

#include "exprNode.hpp"
#include <stdexcept>

namespace s4prc {
    
    ExprNode::ExprNode(std::string content,
                       std::unique_ptr<ExprNode> left,
                       std::unique_ptr<ExprNode> right)
    : content_{std::move(content)} // ``memorise'' the parameter
    , left_{std::move(left)}   // std::unique_ptr<T> is only movable (not copyable)
    , right_{std::move(right)} // std::unique_ptr<T> is only movable (not copyable)
    {
        if(bool(left_)^bool(right_))
        { throw std::runtime_error("either zero or two child nodes expected"); }
    }
    
    ExprNode::ExprNode(const ExprNode &rhs)
    : content_{rhs.content_} // copy
    , left_{}
    , right_{}
    {
        if(rhs.left_)
        { left_=std::make_unique<ExprNode>(*rhs.left_); } // copy
        if(rhs.right_)
        { right_=std::make_unique<ExprNode>(*rhs.right_); } // copy
    }
    
    ExprNode &
    ExprNode::operator=(const ExprNode &rhs)
    {
        content_=rhs.content_; // copy
        if(rhs.left_)
        { left_=std::make_unique<ExprNode>(*rhs.left_); } // copy
        else
        { left_.reset(); }
        if(rhs.right_)
        { right_=std::make_unique<ExprNode>(*rhs.right_); } // copy
        else
        { right_.reset(); }
        return *this;
    }
    
    double
    ExprNode::eval() const
    {
        if(!(left_||right_)) // no child nodes, assume a value
        { return std::stod(content_); }
        if(content_=="+")
        { return left_->eval()+right_->eval(); }
        if(content_=="-")
        { return left_->eval()-right_->eval(); }
        if(content_=="*")
        { return left_->eval()*right_->eval(); }
        if(content_=="/")
        { return left_->eval()/right_->eval(); }
        throw std::runtime_error("unexpected operation "+content_);
    }
    
    std::ostream &
    operator<<(std::ostream &output,
               const ExprNode &n)
    {
        if(!(n.left_||n.right_)) // no child nodes, assume a value
        { output << n.content_; }
        else // assume an operation
        { output << '(' << *n.left_ << n.content_ << *n.right_ << ')'; }
        return output;
    }
    
} // namespace s4prc

//----------------------------------------------------------------------------
