flex flex.l
bison bison.y -d

g++ -o test -std=gnu++14 bison.tab.c src/ast/StatementList.cpp src/ast/Node.cpp src/ast/Expression.cpp src/ast/Print.cpp src/ast/ExpressionList.cpp src/ast/BinaryExpr.cpp src/ast/Literal.cpp src/ast/IntLiteral.cpp src/visitor/Interpreter.cpp src/ast/RealLiteral.cpp src/ast/EmptyNode.cpp src/ast/Statement.cpp src/ast/BooleanLiteral.cpp src/ast/StringLiteral.cpp src/ast/UnaryExpr.cpp src/ast/ArrayLiteral.cpp src/ast/IfStatement.cpp