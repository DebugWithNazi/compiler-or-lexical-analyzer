#include<iostream>
#include<fstream>
#include<conio.h>
#include<map>
#define EE 1000
#define GE 1001
#define LE 1002
#define NE 1003
#define INCR 1004
#define DECR 1005
using namespace std;
	char outarray[100000];
	char outqarray[1000];
	char buff[10000000];
	char defarray[20];
	char temp[5]={};
	char temp1[5]={};
	int t=0;
	string look;
	int i=0;
	   int t1=0;
	char valarray[20];
	class environment{
	std::map<std::string, string>symbolm;
public:	environment * parent;
		

	std::map<std::string, string>::iterator s;
	environment (environment * p) {parent = p; }//constructor
	public:
		
		 void Add( string type, string symbol);
		 void Search (string Symbol);
};
environment *current ;
 environment *e;
void environment::Add( string symbol, string type){
	symbolm[symbol]=type;
	
}
void environment::Search (string Symbol) {
//	cout<<Symbol;
	int d=0;
s=symbolm.find(Symbol);
 //if(j!=m.end())
 //{
if(s==symbolm.end()){
//	cout<<Symbol;
	current =parent;
		e=current;
		e->Search(Symbol);
}

std::cout << s->first << " : " << s->second ;

 }
	void Nline(){
while(buff[i]=='\n'){
	
		i=i+1;
			while(buff[i]==' ' || buff[i]=='\t')
	{
	i++;
	}
		}
	}
	void space (){
	if(buff[i]==' '){
	
	while(buff[i]==' '){
		i++;
	}
}
else 
return;
}
void match(char ch){

	if(ch==buff[i]){
		cout<<ch;
		i++;
	}
	else {
	cout<<"syntax error"<<endl;}  
}
class parser{
	public:
		void num();
		void fact();	
		void restfact();
		void restexpr();
		void exp2();
		void term();
		void restterm();
		void expr();
	    void id();
	   
};
parser par;
void parser::num(){

	int v=buff[i]-'0';	
if(isdigit(buff[i])){		
		i++;
		while(isdigit(buff[i])){
			v=v*10+(buff[i]-'0');
			i++;
		}	
	cout<<v;

	//cout<<"me";		
}
else return;
//}
}
void parser::id(){
	char temp[100]={0};
	int k=0;
	
while(isalpha(buff[i]))
 {  
     temp[k]=buff[i];
     k++;
     i++;
 }	
 look=temp;
 cout<<look;
 if(buff[i]=='['){
 	cout<<"[";
 	i++;
 	num();
 	id();
 }
 else if(buff[i]==']'){
 	cout<<"]";
 	i++;
 }
 else return;
// cout<<lookahead;
}
	void parser::fact(){
	//	cout<<"me";
	exp2();
	id();
	restfact();
	}
void parser::restfact(){
	
 if(buff[i]=='^'){
 		i++;
 	exp2();
 	restfact();
 }
else
return ;

}
void parser::exp2()
{
	if(buff[i]=='('){
			i++;
		cout<<"(";
		expr();
			i++;
			cout<<")";				
	}
	else
	{
//cout<<"me";
	num();
}
}
void parser::term(){
//	cout<<"me";

	fact();
	restterm();
}
void parser::restterm()
{
char peer =buff[++i];
i--;
if(buff[i]=='*' || buff[i]=='/' || buff[i]=='%' || buff[i]=='<' || buff[i]=='>'){
		if(buff[i]=='=' && peer=='='){
					cout <<EE;
				i=i+2;
		     	}
		     	else if(buff[i]=='<' && peer=='='){
					cout <<LE;
				i=i+2;
		     	}
		     else if(buff[i]=='>' && peer=='='){
					cout <<GE;
					i=i+2;
		     	}
		     else if	(buff[i]=='!' && peer=='='){
					cout <<NE;
				i=i+2;
		     	}
		else if  (buff[i]=='+' && peer=='+'){
					cout <<INCR;
				i=i+2;
		     	}
		     else if(buff[i]=='-' && peer=='-'){
					cout <<DECR;
				i=i+2;
		     	}
		     	else{
		     	
	cout<<buff[i];
		i++;}
	fact();
	restterm();
}
else 
return ;
}
void parser::restexpr(){
		if(buff[i]=='+' || buff[i]=='-')
	{
		cout<<buff[i];
		i++;
		term();
		restexpr();
	}
	else 
	return;
}
void parser::expr(){	
//cout<<"me";
if(isalpha(buff[i]) || buff[i]=='_'){
	int k=0;
char temp[30]={0};
while(isalpha(buff[i]) || isdigit(buff[i]) || buff[i]=='_')
 {  
     temp[k]=buff[i];
     k++;
     i++;
  
 }
 look=temp;
 cout<<look;
 if(buff[i]=='=')
 {
 	cout<<buff[i];
 	i++;
 }
}

	term(); 
	restexpr();
		
}
void stmt(){
	par.expr();
}
void syntax(char l[]){
	string mine=l;
	if(mine=="if"){
	 cout<<mine;
	 i--;
		match('('); space(); par.expr(); space(); match(')'); Nline(); 
	
	}
	else 
	par.expr();
}	

string myfunc( char txtarray[])
{

		ifstream infile;
	infile.open(txtarray);
	char ch;
	ch=infile.get();
	int l=0;
	if(!infile.is_open())
	{
		cout<<"not open";
		
	}
	while(!infile.eof())
	{
	    outarray[l]=ch;
	    cout<<ch;
	    l++;
		ch=infile.get();
	}	
	infile.close();	
				
}
main(){
std::map<std::string, int> me;
std::map<std::string, int>::iterator jaz;

 string	decl[100]={"int","string","float","double","char"};
me["if"]=256;

me["for"]=258;
me["while"]=259;

	 int q=0;
 	int s=0;
 	int key=0;
 		int z=0;
     ifstream fin;
	char ch;
	

 int p=0;
	int arraysize=0;
	fin.open("myfile.dat");
	ch=fin.get();
	while(!fin.eof())
	{
	    buff[arraysize]=ch;
	    arraysize++;
		ch=fin.get();
	}
//string look;
	for(; i<arraysize ; i++)//j++)
	{
		while(buff[i] == ' '){
			i++;
	}

	 if (buff[i]=='#')
	{
		
		i++;
		while(buff[i]==' ')
		{
			i++;
		}
		if(buff[i]=='i')
		{
			i++;
			if (buff[i]=='n')
			{
				i++;
				if(buff[i]=='c')
				{
					i++;
					if(buff[i]=='l')
					{
						i++;
						if(buff[i]=='u')
						{
							i++;
							if(buff[i]='d')
							{
								i++;
								if(buff[i]='e')
								{
									i++;
									while(buff[i]==' ')
									{
									 i++;
									}
									 char newarray[100000];
                                      int nsize=0;
									
									if(buff[i]=='<'){
									i++;
										while(buff[i] == ' '){
		                             	i++;
                                         	}
						
									int k;
									for( k=0; buff[i]!='>'; k++)
									{
										newarray[k]=buff[i];
										cout<<newarray[k];
										i++;	
									}
									i--;
									 cout<<"****"<<newarray<<"****";
										myfunc(newarray);
											i=i+2;	
								}	
							
								else if(buff[i]=='"')
								{
									 i++;
									 	while(buff[i] == ' '){
		                             	i++;
                                         	}
									 char myarray[100000];
                                                    for (int l = 0; buff[i] !='"'; l++)
                                                    {
                                                        myarray[l] = buff[i];
                                                        cout<<myarray[l];
                                                        i++;
                                                    }
                                            
                                          	myfunc(myarray);      
								}
								else
								{
									cout<<"syntax error"<<endl;
								}
								
							}
						
						}
							}
						}
					}
				}
			}
				}
				else 
				{
					space();
					Nline();
		
	if(buff[i]=='{'){
		
					cout<<buff[i];
						i++;
					 		current=e;
 		e=new environment (current);
 //	cout<<buff[i];	
				
 	
	do{
 
	while(buff[i]==' ' || buff[i]=='\t')
	{
	cout<<buff[i];
	i++;
	}
	 while(buff[i]=='\n'){
 cout<<buff[i];
		i=i+1;
			while(buff[i]==' ' || buff[i]=='\t')
	{
	cout<<buff[i];
	i++;
	}

		}
		
	 if(buff[i]=='/')
	{
	         if(buff[i]=='/' && buff[i+1]=='/'){
			 	i=i+2;
			 
	 	     while(buff[i]!='\n'){
	 	    	i++;
	                           	}
            	}
    
	else if(buff[i]=='/' && buff[i+1]=='*'){
		i=i+2;
		while(buff[i]!='*' && buff[i++]!='/')
		i++; 
}

}
else if(isalpha(buff[i])|| buff[i]=='_')
{ 

int k=0;
char temp[30]={0};
while(isalpha(buff[i]) || isdigit(buff[i]) || buff[i]=='_')
 {  
     temp[k]=buff[i];
  //  cout<<buff[i];	
     k++;
     i++;
  
 } //cout<<temp<<endl;
 int g=0,z=0;
 int w=0;
 int l=0;
 	char ntemp[100]={0};
 while(g<5){
 	
 	if(decl[g]==temp){
 	//	cout<<decl[g];
 //	char ntemp[100]={0};	
 		while(buff[i]==' '){
 			i++;
 		}
 		while(buff[i]!=';'){
 		ntemp[z]=buff[i];
 		z++;
 		i++;
 	}
 //	current=e;
 cout<<temp<<" "<<ntemp;
  	e->Add(ntemp, temp);
  //cout<<"me";
 	l++;
 //	environment k=new environment();
 //	symbolm[ntemp]=temp;

 	}
 	g++;
 }
 
i++;
//cout<<temp;
jaz=me.find(temp); 
 if(jaz!=me.end()  && l<1)
 {

  syntax(temp);	

 	 w++;
 	
 }
else if(w<1 && l<1)
{	

 e->Search (temp);

 }
 

}


	
}while(buff[i]!='{' );

i--;
}

else if(buff[i]=='}')
{ 

 environment *l=new environment(current);
  l=l->parent;
 delete current;
 current=l;	
 i++;
}

	

}
}
	fin.close();
getch();
}
