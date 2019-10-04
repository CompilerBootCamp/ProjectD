// Identidier and numbers
%token VAR
//%token NUMBER

// Keywords
%token AND OR XOR NOT IS
%token READINT READREAL READSTRING PRINT
%token RETURN IF THEN ELSE END WHILE FOR
%token IN LOOP DOT
%token REAL BOOL STRING EMPTY
%token FUNC TRUE FALSE

// Delimiters
%token LEFTCIRCLEBRACKET	// (
%token RIGHTCIRCLEBRACKET	//  )
%token LEFTCURLYBRACKET		// }
%token RIGHTCURLYBRACKET	// }
%token  DOT					// .
%token COMMA				// ,
%token ARROW				// =>

// Operator signs
%token ASSIGN  				// :=  
%token SEMICOLON		// ;
%token LESS					// <
%token LESSOREQUAL	// <=
%token GREATOREQUAL	// >=
%token EQUAL				// =
%token DIVIDEQUAL		// /=
%token PLUS					// +
%token MINUS				// -
