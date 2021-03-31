del parser.tab.* lex.yy.c parser
flex lex.l
bison -d parser.y
gcc -o parser ast.c semantic.c lex.yy.c parser.tab.c
parser.exe test.c > text.txt