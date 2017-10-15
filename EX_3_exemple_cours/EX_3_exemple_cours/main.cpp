//----------------------------------------------------------------------------

#include <iostream>
#include <cmath>
#include "init.hpp"
#include "gravity.hpp"
#include "wordPool.hpp"
#include "exprNode.hpp"

void
test_init()
{
    std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
    s4prc::Init0 i0;
    std::cout << "i0: <" << i0.d << "><" << i0.i << "><" << i0.s << ">\n";
    s4prc::Init1 i1;
    std::cout << "i1: <" << i1.d << "><" << i1.i << "><" << i1.s << ">\n";
    s4prc::Init2 i2;
    std::cout << "i2: <" << i2.d << "><" << i2.i << "><" << i2.s << ">\n";
    s4prc::Init3 i3a{ 123.456, 987, "Hello" };
    std::cout << "i3a: <" << i3a.d << "><" << i3a.i << "><" << i3a.s << ">\n";
    s4prc::Init3 i3b;
    std::cout << "i3b: <" << i3b.d << "><" << i3b.i << "><" << i3b.s << ">\n";
}

double
magnitude(s4prc::Gravity g)
{
    return std::sqrt(g.x()*g.x()+g.y()*g.y()+g.z()*g.z());
}

void
test_Gravity()
{
    std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
    const s4prc::Gravity g1;
    std::cout << "g1=" << g1 << " (mag=" << magnitude(g1) << ")\n";
    // g1.reverse(); // non-const member function not allowed on const data
    s4prc::Gravity g2{ 1, 2, 3 };
    std::cout << "g2=" << g2 << " (mag=" << magnitude(g2) << ")\n";
    g2.reverse();
    std::cout << "reversed g2=" << g2 << " (mag=" << magnitude(g2) << ")\n";
    s4prc::Gravity g3{opposite(g1)};
    std::cout << "g3=" << g3 << " (mag=" << magnitude(g3) << ")\n";
    for(int i=1;i<=5;++i)
    {
        g3.setX(i);
        std::cout << "g3=" << g3 << " (mag=" << magnitude(g3) << ")\n";
        g3.setY(-0.5*i);
        std::cout << "g3=" << g3 << " (mag=" << magnitude(g3) << ")\n";
        g3.setZ(i/3.0);
        std::cout << "g3=" << g3 << " (mag=" << magnitude(g3) << ")\n";
    }
}

#define COPY_WORDS 0

#if COPY_WORDS
void
useWords(std::string title,
         s4prc::WordPool wp)
#else
void
useWords(std::string title,
         const s4prc::WordPool &wp)
#endif
{
    std::cout << title << ": " << wp.size() << " words (up to "
    << wp.maxLength() << " letters) \n";
    if(wp.size())
    { std::cout << "     " << wp[0] << " ... " << wp[wp.size()-1] << '\n'; }
}

void
test_WordPool()
{
    std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
    s4prc::WordPool wp1{5'000'000,20};
#if COPY_WORDS
    s4prc::WordPool wp2{wp1};
#else
    s4prc::WordPool wp2{std::move(wp1)};
#endif
    useWords("init wp1",wp1);
    useWords("init wp2",wp2);
#if COPY_WORDS
    wp1=wp2;
#else
    wp1=std::move(wp2);
#endif
    useWords("assign wp1",wp1);
    useWords("assign wp2",wp2);
}

void
test_ExprNode()
{
    std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
    using std::make_unique;
    using Node = s4prc::ExprNode;
    auto expr=make_unique<Node>("*",
                                make_unique<Node>("10.1"),
                                make_unique<Node>("+",
                                                  make_unique<Node>("5.2"),
                                                  make_unique<Node>("3.4")));
    std::cout << "expr: " << *expr << "=" << expr->eval() << '\n';
    // auto twiceExpr=make_unique<Node>("+",expr,expr); // not any chance!
#if 0 // moving twice the same information! (are you serious?)
    auto twiceExpr=make_unique<Node>("+",std::move(expr),std::move(expr));
#else
    auto twiceExpr=make_unique<Node>("+",
                                     make_unique<Node>(*expr),  // copy
                                     make_unique<Node>(*expr)); // copy
#endif
    std::cout << "twiceExpr: " << *twiceExpr << "=" << twiceExpr->eval() << '\n';
    *expr=*twiceExpr; // copy
    std::cout << "expr: " << *expr << "=" << expr->eval() << '\n';
}

int
main()
{
    test_init();
    test_Gravity();
    test_WordPool();
    test_ExprNode();
    return 0;
}

//----------------------------------------------------------------------------
