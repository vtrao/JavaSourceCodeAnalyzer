%{
   #include "vv1.tab.h"
   #include<stdio.h>
%}

%%

\/\*([^*]|\*[^/])*\*\/(\n*)   { }
(\/\/|(\/\/[\/]+))(.*)	      { }	
(\"(.)*\")		      { }
[ ]*("public")                { yylval = (int)strdup(yytext);       return pub;         }
[ ]*("protected")             { yylval = (int)strdup(yytext);       return protect;     }
[ ]*("abstract")              { yylval = (int)strdup(yytext);       return abst;        }
[ ]*("throws")                { yylval = (int)strdup(yytext);       return ths;         }
[ ]*("implements")            { yylval = (int)strdup(yytext);       return imp;         }
[ ]*("extends")               { yylval = (int)strdup(yytext);       return ext;         }
[ ]*("interface")             { yylval = (int)strdup(yytext);       return inter;       }
[ ]*("final")                 { yylval = (int)strdup(yytext);       return fin;         }
[ ]*("import")                { yylval = (int)strdup(yytext);       return import;      }
[ ]*("package")               { yylval = (int)strdup(yytext);       return pack;        }
[ ]*("private") 	      { yylval = (int)strdup(yytext);       return pri;         }
[ ]*("continue")              { }            
[ ]*("boolean")		      { yylval = (int)strdup(yytext);       return boo;         }
[ ]*("int")		      { yylval = (int)strdup(yytext);	    return ing;         }
[ ]*("this")		      { yylval = (int)strdup(yytext);       return thi;         }
[ ]*("float")		      { yylval = (int)strdup(yytext);       return flo;         }     
[ ]*("return")		      { }
[ ]*("break")                 { }
[ ]*("default")               { yylval = (int)strdup(yytext);       return def;         }			
[ ]*("for")                   { }	
[ ]*("long")                  { yylval = (int)strdup(yytext);       return lon;         }
[ ]*("short")                 { yylval = (int)strdup(yytext);       return sho;         }
[ ]*("byte")                  { yylval = (int)strdup(yytext);       return byt;         }  
[ ]*("do")                    { }
[ ]*("goto")                  { }  	
[ ]*("static")                { yylval = (int)strdup(yytext);       return sta;         }		
[ ]*("case")                  { }	 
[ ]*("double")                { yylval = (int)strdup(yytext);       return dou;         }
[ ]*("if")                    { }
[ ]*("new")                   { yylval = (int)strdup(yytext);       return new;         }
[ ]*("else")                  { }
[ ]*("void")                  { yylval = (int)strdup(yytext);       return voi;         }
[ ]*("char")                  { yylval = (int)strdup(yytext);       return cha;         }
[ ]*("switch")                { }
[ ]*("while")                 { }
[ ]*("class") 		      { yylval = (int)strdup(yytext);       return cla;         }
[ ]*(",")                     { yylval = (int)strdup(yytext);       return comma;       }  
[ ]*("(")                     { yylval = (int)strdup(yytext);       return cirbral;     }
[ ]*(")")                     { yylval = (int)strdup(yytext);       return cirbrar;     }
[ ]*("[")                     { yylval = (int)strdup(yytext);       return sql;         }
[ ]*("]")                     { yylval = (int)strdup(yytext);       return sqr;         }
[ ]*("*")		      { yylval = (int)strdup(yytext);       return star;        }
[ ]*("{")		      { yylval = (int)strdup(yytext);       return curbral;     }
[ ]*("}")		      { yylval = (int)strdup(yytext);       return curbrar;     }
[ ]*(":")                     { yylval = (int)strdup(yytext);       return colon;       }
[ ]*(";")                     { yylval = (int)strdup(yytext);       return semicolon;   }
[ ]*(".")                     { yylval = (int)strdup(yytext);       return dot;         }    
[ ]*("=")                     { yylval = (int)strdup(yytext);       return equ;         }
[ ]*("synchronized")          { }
[ ]*("native")                { }
[ ]*("volatile")              { }
[ ]*("instanceof")            { }
[ ]*("super")                 { }
[ ]*("strictfp")              { }
[ ]*("try")                   { }
[ ]*("catch")                 { }
[ ]*("transient")             { }
[ ]*("const")                 { }
[ ]*("finally")               { }
[ ]*("throw")                 { }
[a-zA-Z_$][a-zA-Z0-9]*        { yylval = (int)strdup(yytext);       return identifier;  }
[ ]*("!")                     { }
[ ]*("&&")                    { }
[ ]*("||")                    { }
[ ]*("?")                     { }
[ ]*[0-9]*		      { }
[ ]*("\b")                    { }
[ ]*("\t")                    { }
[ ]*("\n")                    { }
[ ]*("\f")                    { }
[ ]*("\r")                    { }
[ ]*("\u")                    { }
[ ]*("\'")                    { }
[ ]*("\\")                    { }
[ ]*("==")		      { }
[ ]*("!=")		      { }
[ ]*(">")		      { }
[ ]*("<")		      { }
[ ]*(">=")		      { }
[ ]*("<=")		      { }
[ ]*("/")		      { yylval = (int)strdup(yytext);       return di;          }
[ ]*("%")		      { yylval = (int)strdup(yytext);       return mo;          }
[ ]*("++")		      { }
[ ]*("--")		      { }
[ ]*("~")		      { }
[ ]*("&")		      { }
[ ]*("|")		      { }
[ ]*("^")		      { }
[ ]*(">>")		      { }
[ ]*(">>>")		      { }
[ ]*("<<")		      { }
[ ]*("&=")		      { }
[ ]*("|=")		      { }
[ ]*("^=")		      { }
[ ]*(">>>=")     	      { }
[ ]*("<<=")		      { }
[ ]*("+")                     { yylval = (int)strdup(yytext);       return pl;          }
[ ]*("-")		      { yylval = (int)strdup(yytext);       return mi;          }
[ ]*("@")                     { }
.|\n	                      { }

%%
/*int main(int argc,char *argv[])
	{
[ ]*("+=")                    { }
[ ]*("-=")                    { }
[ ]*("*=")                    { }
[ ]*("/=")                    { }
[ ]*("%=")                    { }
	FILE *fp;
	if(argc==1)
		{printf("insufficient arguments");exit(0);}
	else
		fp=fopen(argv[1],"r");
		yyin=fp;
		yylex(); 
	return(0);
	}*/
		
