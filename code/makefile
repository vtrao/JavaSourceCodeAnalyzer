v5 : lex.yy.c vv1.tab.c
	gcc lex.yy.c vv1.tab.c -lfl -o v5
lex.yy.c : vv1.l vv1.y
	flex vv1.l
vv1.tab.c : vv1.y
	bison -d vv1.y
