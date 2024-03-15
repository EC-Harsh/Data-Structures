# include<stdio.h>

int prec(char a){ // returning precedence
	if(a=='^')
		return 3;
	else if(a=='*'||a=='/')
		return 2;
	else if(a=='+'||a=='-')
		return 1;
	else 
		return 0;	
	}
char  change(char x){
	if(x=='[')
		return ']';
	else if(x==']')
		return '[';
	else if(x=='{')
		return '}';
	else if (x=='}')
		return '{';
	else if(x=='(')
		return ')';
	else if(x==')')
		return '(';
	else 
		return x;
}

char * rev(char *str){ // for prefix we have to reverse the expression
	int i ;
    for(i=0;str[i]!='\0';i++){
    	str[i]=change(str[i]);
    }
    char *s=str,*e=str+i-1;
    while(s<e){
        char t=*s;
        *s=*e;
        *e=t;
        s++;
        e--;

    }
    return str;
    
}
char * convert(char *exp,char *ex ,int n){ // exp is the expression and ex is the changed expression
// n is the choice for postfix or prefix(at n==1)
	if(n==1)
		exp=rev(exp); // for prefix we have to reverse the expression
	int c=0, i=0,top=-1,j=0;
	for(c=0;exp[c]!='\0';c++);
	char st[c];
	while(exp[i]!='\0'){
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
			top++;
			st[top]=exp[i];
			i++;
		}
		
		if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
			while(st[top]!='('&&st[top]!='{'&&st[top]!='['){
				//printf("%c",st[top]);
				ex[j++]=st[top];
				top--;
			}
			
			top--;
			i++;
			//st[top]=exp[i];
		}
		
		if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'||exp[i]=='^'){
		
		if(prec(st[top]) < prec(exp[i])){ // if precedence of the element in expression is higher than the element in the stack then push that element into stack.
			top++;
			st[top]=exp[i];
			
		}
		else if(prec(st[top])> prec(exp[i])){ 
		//if precendence of the elemnt in stack is higher pop out element and print that elemnt
			while(!(prec(st[top])<prec(exp[i]))){
			//printf("%c",st[top]);
			ex[j++]=st[top];
				top-=1;
			}
			st[top]=exp[i];
						
		}
		
		}
	else{
		//printf("%c",exp[i]);
		ex[j++]=exp[i];
	}
	i++;
		
	} 
	// at last print all the elements from the stack
	while(top!=-1){
		//printf("%c",st[top]);
		ex[j++]=st[top];
		top--;
	}
	ex[j]='\0';
    if(n==1){
    	ex=rev(ex);
    	return ex;
    }
    return ex;
    
}

void main(){
	char s[100],ce[100];
	int n;
	printf("Enter The Expression: ");
	scanf("%[^\n]s",s);
	printf("Enter 1 for Prefix aur any other number for postfix: ");
	scanf("%d",&n);
	convert(s,ce,n);
	printf("\nThe Converted Expression is: %s\n",ce);
	
	
}


