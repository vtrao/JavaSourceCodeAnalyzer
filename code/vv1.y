

%{
 #include<stdio.h>
 #define  z 20    /*maximum size of identifier(userdefined)*/
 #define fz 30    /*maximum size of filename(java source)*/
 #define nvil 10  /* number of variables in line */
 #include <dirent.h>

 char javasource[20][100];               /*to store the absolute path of java source files in the given java project*/
 FILE *fop,*syt;                         /* File Pointers*/
 int js=0;                               /*for java source indexing*/
 char fname[fz];                         /*To store the extracted filename from java source absolute path*/
 char name[z];                           /*To store the name of variables,class names etc*/
 char access[10];                        /*To store the access specifier*/
 char isstatic[10];                      /*To store the Static status of instance*/
 char rettype[10],isstatic1[10];         /*To store the return type and static status of method*/
 int  ais=0i,ais1=0,l=0;                 /*for indexing the arrays*/
 char classname[z];                      /*To store the name of class*/
 char array[nvil][z];
 char array2[nvil][z];
 char array1[z];
 int flagm=1;
 int flagv=1;
 int flagp=1;
 int flagl=1;
 void function(char *a);
 void PrintAndProcess();

 	/* The Structures Employed are as listed below */

		struct cll  				/*structure for classes*/
				{
				char name[z];
				char access[10];
				char filename[fz];
				int cnt;
				struct cll *next;
				} *chead,*ctemp;
		struct mfll				/*structure for member functions*/
				{
				char name[z];
				char access[10];
                        	char isstatic[10];
				char rettype[z];
				int  iscon;
				char classname[z];
                        	char filename[fz];
                        	int  cnt;
				int flag;
                        	struct mfll *next;
				} *mfhead,*mftemp;
		struct fpll				/*structure for function parameters*/
				{
				char name[z];
				char type[z];
				char functionname[z];
				char classname[z];
                        	char filename[fz];
                        	int cnt;
				int flag;
                        	struct fpll *next;
				} *fphead,*fptemp;
		struct lvll				/*structure for local variables of function*/
				{
				char name[z];
				char isstatic[10];
				char type[z];
                        	char functionname[z];
                        	char classname[z];
                        	char filename[fz];
                        	int cnt;
				int flag;
                        	struct lvll *next;
				} *lvhead,*lvtemp;
		struct mvll				/*structure for member variables of class*/
				{
				char name[z];
                        	char access[10];
				char isstatic[10];
				char type[z];
                        	char classname[z];
                        	char filename[fz];
                        	int cnt;
				int flag;
                        	struct mvll *next;
				} *mvhead,*mvtemp;
		
%}

%token pub pri voi pl mi di mo
%token cla 
%token identifier
%token thi def
%token boo flo lon sho ing cha byt dou
%token voi equ
%token sta new import
%token comma cirbral cirbrar curbral curbrar dot colon 
%token semicolon star sqr sql ths protect abst fin imp pack ext inter 
%start S

%%
/* Conventions used in defining the grammar G=V,T,P,S are all caps words for set V-Variables or NonTerminals,
								          all small words for set T-Terminals,
									  S is the Start Symbol of the Grammar,
									  set P is defined as follows        */

/* Grammer We mean Production set starts from here */  

/* S is the Start Symbol of the Grammar, IDS is Importdeclarations,TDS Typedeclarations
	S can be set of IDS only or set of TDS or both IDS and TDS                     */
 
S	: 
	| PDS IDS TDS
	|     IDS TDS
	| PDS     TDS
	| PDS IDS  
	| PDS     
	|     IDS  
	|         TDS    
	;

PDS	: pack PN semicolon
	;

PN	: identifier
	| PN dot identifier
	;

/*Defining the IDS of S: ID is Importdeclaration it can be one or plenty */

IDS	: ID 
	| IDS ID
	;

ID	: STID
	| TIODD
	| SSID
	| SIDD
	;

STID	: import ITN semicolon                     
	;

TIODD	: import ITN dot star semicolon           
	;

SSID	: import sta ITN dot identifier semicolon // { printf("\n..IMPORT NAME is : %s\n",(char *)$5); printf("\n"); }
	;

SIDD	: import sta ITN dot star semicolon       
	;

ITN	: identifier                            //  { printf("\n IMPORT NAME is: %s\n",(char *)$1); printf("\n"); }
	| ITN dot identifier                    //  { printf("\n IMPORT NAME is: %s\n",(char *)$1); printf("\n"); }
	;

/*Defining the TDS of S: CD is Classdeclaration it can be one or plenty*/

TDS	: CD
	| TDS CD
	;

/*Defining the CD of TDS: CB is the Classbody and remaining public,class,identifier are tokens or terminals */
					

CD      : CBS pub cla identifier                CB    { classstructure($4,1);}
        | CBS pub cla identifier EXTN           CB    { classstructure($4,1);}
        | CBS     cla identifier                CB    { classstructure($3,0);}
        | CBS     cla identifier EXTN           CB    { classstructure($3,0);}
        |     pub cla identifier                CB    { classstructure($3,1);}
        |     pub cla identifier EXTN           CB    { classstructure($3,1);}
        |         cla identifier                CB    { classstructure($2,0);}
        |         cla identifier EXTN           CB    { classstructure($2,0);}
        ;

EXTN	: ext identifier
	| ext identifier imp IMPS
	| imp IMPS
	;

IMPS	: identifier
	| IMPS comma identifier
	; 

CBS	: abst
	| fin
	;

/*Defining the CB of CD: CBDS is Classbodydeclarations and curbral,curbrar are tokens or terminals */

CB	: curbral CBDS curbrar
	| curbral      curbrar
	;

/*Defining the CBDS of CB: CBD is Classbodydeclaration there can be one or plenty CBD */

CBDS	: CBD 
	| CBDS CBD
	;

/*Defining the CBD of CBDS: CMD is Classmemberdeclaration,B is Block,C is Constructor and St is static 
		   CBD can be CMD | B | C |St  			                                        */

CBD	: CMD 
	| B  
	| ST  
	;


CMD	: FD                            {
					mvtemp=mvhead;
					while(mvtemp->next!=NULL)
						mvtemp=mvtemp->next;
					for(l=0;l<ais;l++)
						{
						mvtemp->next=(struct mvll *)malloc(sizeof(struct mvll));		
						mvtemp=mvtemp->next;
						strcpy(mvtemp->name,array[l]);
						strcpy(mvtemp->access,access);
						strcpy(mvtemp->isstatic,isstatic);
						strcpy(mvtemp->type,rettype);
						strcpy(mvtemp->filename,fname);
						mvtemp->cnt=0;
						mvtemp->flag=flagv;
						mvtemp->next=NULL;
						}
					strcpy(name," ");       strcpy(access," ");  strcpy(isstatic," ");
                                        strcpy(classname," ");  strcpy(rettype," ");
					ais=0;					
					}		  
	| MD 				{
					mftemp=mfhead;	
					while(mftemp->next!=NULL)
						mftemp=mftemp->next;
					mftemp->next=(struct mfll *)malloc(sizeof(struct mfll));
					mftemp=mftemp->next;
					strcpy(mftemp->filename,fname);
					strcpy(mftemp->name,name);
					strcpy(mftemp->access,access);
					strcpy(mftemp->isstatic,isstatic);
					strcpy(mftemp->rettype,rettype);
					mftemp->cnt=0;
					mftemp->flag=flagm;            /* logical*/
					fptemp=fphead;
					while(fptemp!=NULL)
						{
						if(fptemp->flag==flagp)
							strcpy(fptemp->functionname,name);
						fptemp=fptemp->next;
						}
					flagp++;
					lvtemp=lvhead;
					while(lvtemp!=NULL)
						{
						if(lvtemp->flag==flagl)
							strcpy(lvtemp->functionname,name);
						lvtemp=lvtemp->next;
						}
					flagl++;
					strcpy(name," ");       strcpy(access," ");  strcpy(isstatic," ");
					strcpy(classname," "); strcpy(rettype," ");
					mftemp->next=NULL;
					}					
	| CD
	| semicolon
	;

B	: curbral BSS curbrar
	| curbral     curbrar
	;

BSS	: BS
	| BSS BS
	;

BS	: FD1				{
					int p;
					lvtemp=lvhead;
					while(lvtemp->next!=NULL)
						lvtemp=lvtemp->next;				
					for(p=0;p<ais1;p++)
						{
						lvtemp->next=(struct lvll *)malloc(sizeof(struct lvll));
						lvtemp=lvtemp->next;
						strcpy(lvtemp->name,array2[p]);
						strcpy(lvtemp->filename,fname);
						strcpy(lvtemp->type,rettype);
						strcpy(lvtemp->isstatic,isstatic1);
						lvtemp->flag=flagl;
						lvtemp->next=NULL;
						}
					strcpy(isstatic1,"");
				        ais1=0;	
                                        }
	| CD
	| CRLP
	| cirbral
	| cirbrar
	| semicolon
	| equ
	| colon
	| new
	| pl
	| mi
	| di
	| mo
	| comma
	| dot 
	| identifier { fprintf(syt,"%s %s ",(char *)$1,fname); }
	| star
	;

CRLP	: curbral BSS curbrar
	| curbral     curbrar
	;

FD1	:  sta T VDS1 semicolon { strcpy(isstatic1,"static");}
	|      T VDS1 semicolon
	|  identifier VDS1 semicolon { strcpy(rettype,(char *)$1);}
	|  sta T identifier equ new identifier cirbral LL cirbrar { 
								  strcpy(array2[ais1++],(char *)$3);
								  strcpy(isstatic1,"static");
								  }
        |      T identifier equ new identifier cirbral LL cirbrar  {strcpy(array2[ais1++],(char *)$2);} 
	| identifier identifier equ new identifier cirbral LL cirbrar   {
									strcpy(rettype,(char *)$1);
									strcpy(array2[ais1++],(char *)$2);
									}
        |  sta T identifier equ new identifier dot identifier cirbral LL cirbrar { 
										 strcpy(isstatic1,"static");
										 strcpy(array2[ais1++],(char *)$3);
										 }
        |      T identifier equ new identifier dot identifier cirbral LL cirbrar {strcpy(array2[ais1++],(char *)$2);} 
	| identifier identifier equ new identifier dot identifier cirbral LL cirbrar {
										     strcpy(rettype,(char *)$1);
										     strcpy(array2[ais1++],(char *)$2);
										     }
	;

VDS1	: VDD2   
        | VDS1 comma VDD2
        ;

VDD2	: identifier         {strcpy(array2[ais1++],(char *)$1);}
	| identifier equ     {strcpy(array2[ais1++],(char *)$1);}
	| identifier equ dot {strcpy(array2[ais1++],(char *)$1);}
	| VDD2 sql sqr
	;

COM	:  identifier cirbral FPS cirbrar semicolon	                { strcpy(name,(char *)$1);}
        |  identifier cirbral     cirbrar  B				{ strcpy(name,(char *)$1);}
        |  identifier cirbral FPS cirbrar  B				{ strcpy(name,(char *)$1);}
        |  identifier cirbral     cirbrar ths identifier  B		{ strcpy(name,(char *)$1);}
        |  identifier cirbral FPS cirbrar ths identifier  B		{ strcpy(name,(char *)$1);}
	|  identifier cirbral     cirbrar semicolon 	                { strcpy(name,(char *)$1);}
	;

FPS 	: FP 		{
			fptemp=fphead;
			while(fptemp->next!=NULL)
				fptemp=fptemp->next;
			fptemp->next=(struct fpll *)malloc(sizeof(struct fpll));
			fptemp=fptemp->next;
			strcpy(fptemp->name,array1);
			strcpy(fptemp->type,rettype);
			strcpy(fptemp->filename,fname);
			fptemp->cnt=0;
			fptemp->flag=flagp;
			fptemp->next=NULL;
			}
	| FPS comma FP  {
                        fptemp=fphead;
                        while(fptemp->next!=NULL)
                                fptemp=fptemp->next;
                        fptemp->next=(struct fpll *)malloc(sizeof(struct fpll));
                        fptemp=fptemp->next;
                        strcpy(fptemp->name,array1);
                        strcpy(fptemp->type,rettype);
                        strcpy(fptemp->filename,fname);
                        fptemp->cnt=0;
                        fptemp->flag=flagp;
                        fptemp->next=NULL;
                        }
	;

FP	: T VDD1
	;

VDD1	: identifier         { strcpy(array1,(char *)$1); } 
	| identifier equ     { strcpy(array1,(char *)$1); }
	| identifier equ dot { strcpy(array1,(char *)$1); }
	| VDD1 sql sqr
	;

T	: PT
	| RT
	;

PT	: NT
	| boo
	;

NT	: IT
	| FPT
	;

FD	: FMS T VDS semicolon 
	|     T VDS semicolon
	| FMS T identifier equ new identifier cirbral LL cirbrar { strcpy(array[ais++],(char *)$3); }
	|     T identifier equ new identifier cirbral LL cirbrar { strcpy(array[ais++],(char *)$2); }
        | FMS T identifier equ new identifier dot identifier cirbral LL cirbrar { strcpy(array[ais++],(char *)$3); }
        |     T identifier equ new identifier dot identifier cirbral LL cirbrar { strcpy(array[ais++],(char *)$2); }
	;

LL	: LL1
	| LL comma LL1 
	;

LL1	: 
	| identifier
	;

VDS	: VDD			
	| VDS comma VDD
	;

VDD     : identifier         { strcpy(array[ais++],(char *)$1); }
	| identifier equ     { strcpy(array[ais++],(char *)$1); }
	| identifier equ dot { strcpy(array[ais++],(char *)$1); }
        | VDD sql sqr
        ;

/*We can extend expressions here*/

FMS 	: FM2
	|         FM
	|     FM1
	|     FM1 FM
	| FM2 FM1 FM 
	| FM2     FM
	| FM2 FM1
	;

FM2	: fin
	;

FM 	: sta		{strcpy(isstatic,"static");}
	;

FM1 	: pub		{strcpy(access,"public");}
	| pri           {strcpy(access,"private");}
	| protect	{strcpy(access,"protected");}
	;

IT	: byt		{strcpy(rettype,"byte");}
	| sho		{strcpy(rettype,"short");}
	| lon		{strcpy(rettype,"long");}
	| ing		{strcpy(rettype,"int");}
	| cha		{strcpy(rettype,"char");}
	;

FPT	: flo		{strcpy(rettype,"float");}
	| dou		{strcpy(rettype,"double");}
	;

RT	: CT
	| identifier	{strcpy(rettype,(char *)$1);}
	| AT
	;

CT	: TDS1 TA
	| TDS1
	;

TDS1	: TN
	| CT dot identifier
	;

TN	: identifier
	| TN dot identifier
	;

AT	: T sql sqr
	;

TA	: ATAL 
	;

ATAL	: ATA
	| ATAL comma ATA
	;

ATA	: RT
	;

ST	: sta B
	;

MD 	: FMS T    COM
	|     T    COM
	| FMS voi  COM 		{strcpy(rettype,"void");}
        | FMS      COM
        |     voi  COM		{strcpy(rettype,"void");}
        |          COM
	; 


/* carry on to complete the grammar for the problem domain */
 
%%

/* Write the code for main function to solve the problem set */

extern FILE *yyin;
yyerror(char *s)
	{
        fprintf(stderr,"%s\n",s);
        }

void function(char *a)
        {
        struct dirent **name;
        int n=0;
        char aa[30];
        n=scandir(a,&name,0,alphasort);
        if (n < 0)
               {}
        else
                {
                while(n--)
                        {
                        if(strstr(name[n]->d_name,".java"))
                                {
				strcpy(javasource[js],a);
				strcat(javasource[js],"/");
                                strcat(javasource[js++],name[n]->d_name);
                                }
                       /* else if(strstr(name[n]->d_name,".class"))
                                printf("\nClass file %s\n",name[n]->d_name);*/
                        else if(strstr(name[n]->d_name,"."))
                                ;
                        else
                                {
                                strcpy(aa,a);
                                strcat(aa,"/");
                                strcat(aa,name[n]->d_name);
                                function(aa);
                                }
                        }
                }
        }

classstructure(char *v,int lm)
	{
        ctemp=chead;
        while(ctemp->next!=NULL)
        	ctemp=ctemp->next;
        ctemp->next=(struct cll *)malloc(sizeof(struct cll));
        ctemp=ctemp->next;
        strcpy(ctemp->name,v);
        mftemp=mfhead;
        while(mftemp!=NULL)
        	{
	        if(mftemp->flag==flagm)
        		{
		        strcpy(mftemp->classname,ctemp->name);
		        fptemp=fphead;
		        while(fptemp!=NULL)
			        {
			        if(!strcmp(fptemp->functionname,mftemp->name))
				        strcpy(fptemp->classname,ctemp->name);
			        fptemp=fptemp->next;
			        }
		        lvtemp=lvhead;
		        while(lvtemp!=NULL)
			        {
			        if(!strcmp(lvtemp->functionname,mftemp->name))
				        strcpy(lvtemp->classname,ctemp->name);
			        lvtemp=lvtemp->next;
			        }
		        }
	        mftemp=mftemp->next;
        	}
	flagm++;
        mvtemp=mvhead;
        while(mvtemp!=NULL)
        	{
        	if(mvtemp->flag==flagv)
	        	strcpy(mvtemp->classname,ctemp->name);
        	mvtemp=mvtemp->next;
        	}
        flagv++;
	if(lm==0)
	        strcpy(ctemp->access,"default");
	else if(lm==1)
		strcpy(ctemp->access,"public");	
	else	{}
        strcpy(ctemp->filename,fname);
        ctemp->cnt=0;
        ctemp->next=NULL;
        }


int main(int argc,char *argv[])
        {
        FILE *fp,*logf;
	int i=0;
	char tem[fz];
        struct dirent **namelist;
	fop=fopen("analysis.txt","w");
	syt=fopen("syt.txt","w");
	system("date >> logfile.txt");
	logf=fopen("logfile.txt","a");
        int n,k;
	chead =(struct  cll *)malloc(sizeof(struct  cll));      chead->next =NULL;
	mfhead=(struct mfll *)malloc(sizeof(struct mfll));	mfhead->next=NULL;	
	fphead=(struct fpll *)malloc(sizeof(struct fpll));	fphead->next=NULL;
	lvhead=(struct lvll *)malloc(sizeof(struct lvll));	lvhead->next=NULL;
	mvhead=(struct mvll *)malloc(sizeof(struct mvll));	mvhead->next=NULL;
        if(argc==1)
                {
                printf("improper no. of arguments\n");fprintf(logf,"improper no. of arguments\n");
		fprintf(logf,"--------------------------------------------------------------------------\n\n\n");
                exit(0);
                }
        function(argv[1]);
	if(js==0)
		{
		printf("\nNo JAVA Source Found in Project Exting......!\n");
		fprintf(logf,"\nNo JAVA Source Found in Project Exting......!\n");
		fprintf(logf,"--------------------------------------------------------------------------\n\n\n");
		exit(0);
		}
        printf("\n\nThe Java Source Files are \n\n"); fprintf(fop,"\n\nThe Java Source Files are \n\n");
	fprintf(logf,"\n\nThe JAVA Source Files are \n\n");
        for(i=0;i<js;i++)
                {
                printf("\t\t%s \n",javasource[i]); fprintf(fop,"\t\t%s \n",javasource[i]);
		fprintf(logf,"\t\t%s \n",javasource[i]);
                }
	fprintf(logf,"--------------------------------------------------------------------------\n\n\n");
	for(i=0;i<js;i++)
		{
	        fp=fopen(javasource[i],"r");
	        for(n=strlen(javasource[i])-1,k=0;javasource[i][n]!='/';n--,k++)
			tem[k]=javasource[i][n];
		tem[k]='\0';
		for(k=k-1,n=0;k>=0;k--,n++)
			fname[n]=tem[k];
		fname[n]='\0';
        	if(fp==NULL)
                	{
	                fprintf(stderr,"cannt open source file %s\n",fname);
			continue;
                	}
	        yyin=fp;
        	do
                	{
	                yyparse();
        	        }while(!feof(yyin));
		fclose(fp);
		ais=0;ais1=0;
		}
	PrintAndProcess();
	fclose(logf);
	}

void PrintAndProcess()
	{
	chead=chead->next;
        mfhead=mfhead->next;
        mvhead=mvhead->next;
        fphead=fphead->next;
        lvhead=lvhead->next;
/*Classes*/
	printf("\n\n\n\nThe Classes Declared in the Java Project are as listed\n\n");
	fprintf(fop,"\n\n\n\nThe Classes Declared in the Java Project are as listed\n\n");
	ctemp=chead;
        printf("  NameoftheClass\t  AccessType      FileName\n"); 
	fprintf(fop,"  NameoftheClass\t  AccessType      FileName\n");
	while(ctemp!=NULL)
		{
		printf("\t  %-10s \t  %-10s\t %-10s\n",ctemp->name,ctemp->access,ctemp->filename);
		fprintf(fop,"\t  %-10s \t  %-10s\t %-10s\n",ctemp->name,ctemp->access,ctemp->filename);
		ctemp=ctemp->next;
		}
/*Member Functions*/
	printf("\n\n\n\nThe Methods Declared in the Classes are as listed\n\n");
	fprintf(fop,"\n\n\n\nThe Methods Declared in the Classes are as listed\n\n");	
        mftemp=mfhead;
        printf("  Nameofthemethod\t\tAccessType \tIsStaticOrNot\t  ReturnType\tClassName\t  FileName\n");
	fprintf(fop,"  Nameofthemethod\t\tAccessType \tIsStaticOrNot\t  ReturnType\tClassName\t  FileName\n");
        while(mftemp!=NULL)
                {
                printf("\t  %-10s\t \t%-10s  \t %-10s  \t %-10s  \t %-10s\t %-10s\n",
			mftemp->name,mftemp->access,mftemp->isstatic,mftemp->rettype,mftemp->classname,mftemp->filename);
		fprintf(fop,"\t  %-10s\t \t%-10s  \t %-10s  \t %-10s  \t %-10s\t %-10s\n",
                        mftemp->name,mftemp->access,mftemp->isstatic,mftemp->rettype,mftemp->classname,mftemp->filename);
                mftemp=mftemp->next;
                }
/*Member Variables*/
	printf("\n\n\n\n The Member Variables Declared in the Classes are as listed\n\n");
	fprintf(fop,"\n\n\n\n The Member Variables Declared in the Classes are as listed\n\n");
	mvtemp=mvhead;
	printf("  NameofVariable\t \tAccessType \tIsStaticOrNot\t Type      \tClassName\t  FileName\n");
	fprintf(fop,"  NameofVariable\t \tAccessType \tIsStaticOrNot\t Type      \tClassName\t  FileName\n");
	while(mvtemp!=NULL)
		{
		printf("\t  %-10s\t \t%-10s  \t %-10s  \t %-10s  \t %-10s\t %-10s\n",
                        mvtemp->name,mvtemp->access,mvtemp->isstatic,mvtemp->type,mvtemp->classname,mvtemp->filename);
		fprintf(fop,"\t  %-10s\t \t%-10s  \t %-10s  \t %-10s  \t %-10s\t %-10s\n",
                        mvtemp->name,mvtemp->access,mvtemp->isstatic,mvtemp->type,mvtemp->classname,mvtemp->filename);
                mvtemp=mvtemp->next;
                }
/*Function Parameters*/
	printf("\n\n\n\n The FunctionParameters of Various Functions are as listed\n\n");
	fprintf(fop,"\n\n\n\n The FunctionParameters of Various Functions are as listed\n\n");
	fptemp=fphead;
	printf(" NameofParameter\t  Type\t\t FuctionName \t ClassName \t Filename\n");
	fprintf(fop," NameofParameter\t  Type\t\t FuctionName \t ClassName \t Filename\n");
	while(fptemp!=NULL)
	    {
	    printf("\t  %-10s\t %-10s \t %-10s \t %-10s \t %-10s\n",fptemp->name,fptemp->type,fptemp->functionname,
									fptemp->classname,fptemp->filename);
	    fprintf(fop,"\t  %-10s\t %-10s \t %-10s \t %-10s \t %-10s\n",fptemp->name,fptemp->type,fptemp->functionname,
                                                                         fptemp->classname,fptemp->filename);
	    fptemp=fptemp->next;
	    }
/*Local Variables*/
	printf("\n\n\n\n The Local Variables Declared in Various Functions are as listed\n\n");
	fprintf(fop,"\n\n\n\n The Local Variables Declared in Various Functions are as listed\n\n");
	lvtemp=lvhead;
	printf(" NameofLocalVariable \t IsStaticOrNot \t Type \t\tFunctionName \t Classname \t Filename\n");
	fprintf(fop," NameofLocalVariable \t IsStaticOrNot \t Type \t\tFunctionName \t Classname \t Filename\n");
	while(lvtemp!=NULL)
		{
		printf("\t  %-10s\t %-10s \t %-10s \t %-10s \t %-10s \t %-10s\n",lvtemp->name,lvtemp->isstatic,
					lvtemp->type,lvtemp->functionname,lvtemp->classname,lvtemp->filename);
		fprintf(fop,"\t  %-10s\t %-10s \t %-10s \t %-10s \t %-10s \t %-10s\n",lvtemp->name,lvtemp->isstatic,
                                        lvtemp->type,lvtemp->functionname,lvtemp->classname,lvtemp->filename);
		lvtemp=lvtemp->next;
		}
	fclose(syt);
	syt=fopen("syt.txt","r");
/*Solution to 3rd Question*/
/*Solution to 4th Question*/
	while(feof(syt)==0)
		{
		fscanf(syt,"%s%s",&name,&fname);
		lvtemp=lvhead;
		fptemp=fphead;
		mvtemp=mvhead;
		mftemp=mfhead;
		while(lvtemp!=NULL)
			{
			if(!strcmp(lvtemp->filename,fname))
				if(!strcmp(lvtemp->name,name))
					lvtemp->cnt+=1;
			lvtemp=lvtemp->next;
			}
		while(fptemp!=NULL)
                        {
                        if(!strcmp(fptemp->filename,fname))
                                if(!strcmp(fptemp->name,name))
                                        fptemp->cnt+=1;
                        fptemp=fptemp->next;
                        }
		while(mvtemp!=NULL)
                        {
                        if(!strcmp(mvtemp->filename,fname))
                                if(!strcmp(mvtemp->name,name))
                                        mvtemp->cnt+=1;
                        mvtemp=mvtemp->next;
                        }
		while(mftemp!=NULL)
                        {
                        if(!strcmp(mftemp->filename,fname))
                                if(!strcmp(mftemp->name,name))
                                        mftemp->cnt+=1;
                        mftemp=mftemp->next;
                        }
		}
/*3rd Question Output*/
printf("\n\n\n\n\nThese are the unused Private member variables and methods\n");
fprintf(fop,"\n\n\n\n\nThese are the unused Private member variables and methods\n");
	ctemp=chead;
	while(ctemp!=NULL)
		{
		mftemp=mfhead;
		mvtemp=mvhead;
		printf("\n----->In Class \"%s\" of File \"%s\" ",ctemp->name,ctemp->filename);
		fprintf(fop,"\n----->In Class \"%s\" of File \"%s\" ",ctemp->name,ctemp->filename);
		while(mftemp!=NULL)
			{
			if(!strcmp(mftemp->classname,ctemp->name))
				if(mftemp->cnt==0)
					if(!strcmp(mftemp->access,"private"))
						{
						printf("\n\t\t Unused Private Function is-->  %s()",mftemp->name);
						fprintf(fop,"\n\t\t Unused Private Function is-->  %s()",mftemp->name);
						}
			mftemp=mftemp->next;
			}
		while(mvtemp!=NULL)
			{
			if(!strcmp(mvtemp->classname,ctemp->name))
				if(mvtemp->cnt==0)
					if(!strcmp(mvtemp->access,"private"))
						{
						printf("\n\t\t Unused Private Variable is-->  %s",mvtemp->name);
						fprintf(fop,"\n\t\t Unused Private Variable is-->  %s",mvtemp->name);
						}
			mvtemp=mvtemp->next;
			}
		ctemp=ctemp->next;
		}
/*4TH Question Output*/
printf("\n\n\n\n\nThese are the unused Function Parameters and Local Variables\n");
fprintf(fop,"\n\n\n\n\nThese are the unused Function Parameters and Local Variables\n");
	mftemp=mfhead;
	while(mftemp!=NULL)
		{
		fptemp=fphead;
		lvtemp=lvhead;
     printf("\n----->In Function \"%s\" of Class \"%s\" in File \"%s\" ",mftemp->name,mftemp->classname,mftemp->filename);
 fprintf(fop,"\n----->In Function \"%s\" of Class \"%s\" in File \"%s\" ",mftemp->name,mftemp->classname,mftemp->filename);
		while(fptemp!=NULL)
			{
			if(!strcmp(mftemp->name,fptemp->functionname))
				if(!strcmp(mftemp->classname,fptemp->classname))
					if(!strcmp(mftemp->filename,fptemp->filename))
						if(fptemp->cnt==0)
							{
							printf("\n\t\t Unused Parameter is --> %s",fptemp->name);
							fprintf(fop,"\n\t\t Unused Parameter is --> %s",fptemp->name);
							}
			fptemp=fptemp->next;
			}
                while(lvtemp!=NULL)
                        {
                        if(!strcmp(mftemp->name,lvtemp->functionname))
                                if(!strcmp(mftemp->classname,lvtemp->classname))
                                        if(!strcmp(mftemp->filename,lvtemp->filename))
                                                if(lvtemp->cnt==0)
                                                        {
                                                        printf("\n\t\t Unused Parameter is --> %s",lvtemp->name);
							fprintf(fop,"\n\t\t Unused Parameter is --> %s",lvtemp->name);
                                                        }
                        lvtemp=lvtemp->next;
                        }
		mftemp=mftemp->next;
		}
/*Solution to 5TH Question*/
 	mvtemp=mvhead;
	ctemp=chead;
	printf("\n\n\n\n\nThese are Dependencies among the Various Classes of the Project\n");
	printf("\n---> These are the Dependencies in the Member Variable Section\n");
        fprintf(fop,"\n\n\n\n\nThese are Dependencies among the Various Classes of the Project\n");
        fprintf(fop,"\n---> These are the Dependencies in the Member Variable Section\n");
	while(ctemp!=NULL)
		{
		while(mvtemp!=NULL)
			{
			if(!strcmp(mvtemp->type,ctemp->name))
				{
			        printf("\n\t The \"%s\" class is (%s) making use of \"%s\" class in File \"%s\" ",
							mvtemp->classname,mvtemp->name,ctemp->name,mvtemp->filename);
  	                        fprintf(fop,"\n\t The \"%s\" class is (%s) making use of \"%s\" class in File \"%s\" ",
						        mvtemp->classname,mvtemp->name,ctemp->name,mvtemp->filename);
			        if(!strcmp(mvtemp->classname,ctemp->name))
					{
					printf("-->This is a self reference");	
					fprintf(fop,"-->This is a self reference");
					}
			    	}
			mvtemp=mvtemp->next;
			}
		mvtemp=mvhead;
		ctemp=ctemp->next;
		}
	printf("\n\n---> These are the Dependencies in the Local Variable Section(in a Member Function )\n");
	fprintf(fop,"\n\n---> These are the Dependencies in the Local Variable Section(in a Member Function )\n");
	lvtemp=lvhead;
	ctemp=chead;	
	while(ctemp!=NULL)
                {
                while(lvtemp!=NULL)
                        {
                        if(!strcmp(lvtemp->type,ctemp->name))
                        	{
                                printf("\n\t The \"%s\" class is (%s) making use of \"%s\" class in File \"%s\"  ",
							lvtemp->classname,lvtemp->name,ctemp->name,lvtemp->filename);
			        fprintf(fop,"\n\t The \"%s\" class is (%s) making use of \"%s\" class in File \"%s\" ",
							lvtemp->classname,lvtemp->name,ctemp->name,lvtemp->filename);
                                if(!strcmp(lvtemp->classname,ctemp->name))
                                	{
					printf("-->This is a self reference"); 
					fprintf(fop,"-->This is a self reference");
					}
                                }
                        lvtemp=lvtemp->next;
                        }
                lvtemp=lvhead;
                ctemp=ctemp->next;
                }
	printf("\n\n\t\t\t\t\t\tThank Q\n\n");
	fprintf(fop,"\n\n\t\t\t\t\tThank Q\n\n");
	fclose(syt);
	remove("syt.txt");
	free(chead);free(mfhead);free(mvhead);free(fphead);free(lvhead);
	fclose(fop);
        }
