flex flex.l
bison bison.y -d -v

g++ -o test -std=gnu++14 bison.tab.c src/ast/StatementList.cpp src/ast/Node.cpp src/ast/Expression.cpp src/ast/Print.cpp src/ast/ExpressionList.cpp src/ast/BinaryExpr.cpp src/ast/Literal.cpp src/ast/IntLiteral.cpp src/visitor/Interpreter.cpp src/ast/RealLiteral.cpp src/ast/EmptyNode.cpp src/ast/Statement.cpp src/ast/BooleanLiteral.cpp src/ast/StringLiteral.cpp src/ast/UnaryExpr.cpp src/ast/ArrayLiteral.cpp src/ast/IfStatement.cpp src/ast/TupleElementList.cpp src/ast/TupleElement.cpp src/ast/TupleLiteral.cpp src/type_system/LiteralTypes.cpp src/ast/WhileStatement.cpp src/ast/VarDef.cpp src/ast/DefinitionList.cpp src/ast/SymbolTable.cpp src/ast/Reference.cpp src/ast/ReferenceTail.cpp src/ast/ForStatement.cpp src/ast/TypeIndicator.cpp