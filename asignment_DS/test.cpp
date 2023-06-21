#include "test.h"
bool checkOperator(char s)
{
	if (s == '+' || s == '-' || s == '*' || s == '/'|| s == '^') return true;
	return false;
}
int precedence(char c)
{
	switch (c)
	{
	case '+': case '-': return 1;
	case '*': case '/' : return 2;
	case '^': return 3;
	default: return -1;
	}
}
string Infix2Postfix(string infix){
    if(checkDividedbyZero(infix)) return "DIVIDED BY 0 ERROR";
    if(checkUndefinedError(infix)) return "UNDEFINED ERROR";
    if(checkSyntaxError(infix)) return "SYNTAX ERROR";
    stack<char>st;
	string output;
	int i=0;
    while(i<(int)infix.size())
	{
        if(isalnum(infix[i]))
		    {
			while(isalnum(infix[i]))
			{
               output+=infix[i];
			   ++i;
			}
			output+=' ';
			continue;
			}
		else if (infix[i]=='(')
		    st.push(infix[i]);
		else if (infix[i]==')')
		{   
			while(st.top()!='(')
			{   
				output+=st.top();
				output+=' ';
				st.pop();
			}
			st.pop();
		}
		else if (checkOperator(infix[i]))
		{      
               int prece=precedence(infix[i]);
			   while(!st.empty()&&prece<=precedence(st.top()))
			   {
				output+=st.top();
				output+=' ';
				st.pop();
			   }
			   st.push(infix[i]);
		}
		++i;
	}
	if(!st.empty())
	{
		while(!st.empty())
		{   
			output+=st.top();
			output+=' ';
			st.pop();
		}
	}
return output;
}
string Infix2Prefix(string infix)
{
    if(checkDividedbyZero(infix)) return "DIVIDED BY 0 ERROR";
    if(checkUndefinedError(infix)) return "UNDEFINED ERROR";
    if(checkSyntaxError(infix)) return "SYNTAX ERROR";
	stack<char>st;
	string output;
	int i=(int)infix.size()-1;
	while(i>=0)
	{
		if(isalnum(infix[i]))
		{
			while(isalnum(infix[i]))
			{
               output+=infix[i];
			   --i;
			}
			output+=' ';
			continue;
		}
		else if(infix[i]==')')
          st.push(infix[i]);
		else if (infix[i]=='(')
		{
			while(st.top()!=')')
			{
				output+=st.top();
				output+=' ';
				st.pop();
			}
			st.pop();
		}
		else if(checkOperator(infix[i]))
		{
            int prece=precedence(infix[i]);
			   while(!st.empty()&&prece<precedence(st.top()))
			   {
				output+=st.top();
				output+=' ';
				st.pop();
			   }
			   st.push(infix[i]);
		}
		--i;
	}
		if(!st.empty())
	{
		while(!st.empty())
		{   
			output+=st.top();
			output+=' ';
			st.pop();
		}
	}
	reverse(output.begin(),output.end());
	output=output.substr(1);
	return output;
}
string PostfixPrefixCalculator(string input){
	stack<double>result;
    if(!checkOperator(input[0]))
	{
	  int i=0; 
	  while(i<(int)input.size())
	  {
		if(isalnum(input[i]))
		   {
			string temp;
			while(input[i]!=' ')
			{
		      temp+=input[i];
			  ++i;
			}
            result.push(stod(temp));
			continue;
		   }
		else if(checkOperator(input[i])) 
		{   
			double x = result.top();
		  	result.pop();
		    double y= result.top();
			result.pop();
			switch (input[i])
			{
			 case '+': result.push(y+x); break;
			 case '-': result.push(y-x); break;
			 case '*': result.push(y*x); break;
			 case '/': result.push(y/x); break;
			 case '^': result.push(pow(y,x));
		    }
	  	}
		++i;
	   }
	}
	else {
       int i=(int)input.size()-1;
	   while(i>=0)
	   {
		 if(isalnum(input[i]))
		   {
			string temp;
			while(input[i]!=' ')
			{
		      temp+=input[i];
			  --i;
			}
			reverse(temp.begin(),temp.end());
            result.push(stod(temp));
			continue;
		   }
		 else if(checkOperator(input[i])) {
			double x = result.top();
		  	result.pop();
		    double y= result.top();
			result.pop();
			switch (input[i])
			{
			 case '+': result.push(x+y); break;
			 case '-': result.push(x-y); break;
			 case '*': result.push(x*y); break;
			 case '/': result.push(x/y); break;
			 case '^': result.push(pow(x,y));
		    }
		 }
		 --i;
	   }
	}
if(((int)result.top()-result.top())==0) return to_string((int)result.top());
result.top()=round(result.top()*10000)/10000;
string temp=to_string(result.top());
int index=(int)temp.size()-1;
while(temp[index]=='0'){
    index--;
}
if(temp[index]=='.') return temp.substr(0,index);
return temp.substr(0,index+1);
}
bool isLogicOper(char c)
{
  return c=='&'||c=='~'||c=='|';
}
bool isChar(char c)
{
    return c>='a'&&c<='z';
}
int getPrecedence(char c)
{
    switch(c)
    {
        case '~': return 3;
        case '&': case '|': return 2;
        case '-':case '>': return 1;
        case '<' : return 0;
        default: return -1;
    }
}
string LogicInfix2Postfix(string infix)
{   
    if(checkErrorLogic(infix)) return "SYNTAX ERROR";
    stack<char>st;
    string output;
    int i=0; 
    while(i<(int)infix.size())
    {
      if(isChar(infix[i])) 
      {
        output+=infix[i];
      }  
      else if(infix[i]=='(') st.push(infix[i]);
      else if(infix[i]==')')
      {
        while(st.top()!='(')
			{   
				output+=st.top();
				st.pop();
			}
			st.pop();
      }
      else if(infix[i]=='<')
      { 
        int prece=getPrecedence(infix[i]);
        while(!st.empty()&&prece<=getPrecedence(st.top()))
        {
          output+=st.top();
          st.pop();
        }
        st.push(infix[i+2]);
        st.push(infix[i+1]);
        st.push(infix[i]);
        i+=3;
        continue;
      }
      else if(infix[i]=='-')
      { 
        int prece=getPrecedence(infix[i]);
        while(!st.empty()&&prece<=getPrecedence(st.top()))
        {
          output+=st.top();
          st.pop();
        }
        st.push(infix[i+1]);
        st.push(infix[i]);
        i+=2;
        continue;
      }
      else if(isLogicOper(infix[i])) {
        int prece=getPrecedence(infix[i]);
        while(!st.empty()&&prece<=getPrecedence(st.top()))
        {
            output+=st.top();
            st.pop();
        }
        st.push(infix[i]);
      }
      ++i;
    }
    while(!st.empty()) {
        output+=st.top(); 
        st.pop();
    }
    return output;
}
string LogicInfix2Prefix(string infix)
{
  if(checkErrorLogic(infix)) return "SYNTAX ERROR";
  stack<char>st;
  string output;
  int i=(int)infix.size()-1;
  while(i>=0)
  {
    if(isChar(infix[i])) output+=infix[i];
    else if(infix[i]==')') st.push(infix[i]);
    else if (infix[i]=='(')
    {
      while(st.top()!=')')
      {
        output+=st.top();
        st.pop();
      }
      st.pop();
    }
    else if(infix[i]=='>')
    {
      if(infix[i-2]=='<')
      {  int prece=getPrecedence(infix[i]);
        while(!st.empty()&&prece<=getPrecedence(st.top()))
        {
          output+=st.top();
          st.pop();
        }
        st.push(infix[i-2]);
        st.push(infix[i-1]);
        st.push(infix[i]);
        i-=3; continue;
      }
      else{
         int prece=getPrecedence(infix[i]);
        while(!st.empty()&&prece<getPrecedence(st.top()))
        {
          output+=st.top();
          st.pop();
        }
        st.push(infix[i-1]);
        st.push(infix[i]);
        i-=2;
        continue;
      }
    }
    else if(isLogicOper(infix[i])){
      int prece=getPrecedence(infix[i]);
      while(!st.empty()&&prece<getPrecedence(st.top()))
      {
        output+=st.top();
        st.pop();
      }
      st.push(infix[i]);
    }
    --i;
  }
  while(!st.empty())
  {
    output+=st.top();
    st.pop();
  }
 reverse(output.begin(),output.end());
  return output;
}
bool Implication(bool p, bool q){
  if(!p) return true;
  return q;
}
bool Biconditional(bool p, bool q)
{
  return p==q;
}
string LogicPostfixPrefixCalculator(string input,string varlue){
  string value(""); string variable;
  for(int i=0; i<(int)varlue.size();i++)
  {
    if(isChar(varlue[i])) variable+=varlue[i];
    else if(varlue[i]!=' ') value+=varlue[i];
  }
  stack<bool>result;
  if(isChar(input[0]))
  {
    int i=0;
    while(i<(int)input.size())
    {
      if(isChar(input[i])){
        int index=variable.find(input[i]);
        result.push(value[index]=='1'?true:false);
      }
      else if(input[i]=='~')
      {
        bool x=result.top();
        result.pop();
        result.push(!x);
      }
      else 
      {
        bool x=result.top(); result.pop();
        bool y=result.top(); result.pop();
        switch(input[i])
        {
          case '&': result.push(y&&x); break;
          case '|': result.push(y||x); break;
          case '<': i+=2; result.push(Biconditional(y,x)); break;
          case '-': i+=1; result.push(Implication(y,x));
        }
      }
      ++i;      
    }
  }
  else {
    int i=(int)input.size()-1;
    while(i>=0)
    {
      if(isChar(input[i]))
      {
        int index=variable.find(input[i]);
        result.push(value[index]=='1'?true:false);
      }
       else if(input[i]=='~')
      {
        bool x=result.top();
        result.pop();
        result.push(!x);
      }
      else{
        bool x=result.top(); result.pop();
        bool y=result.top(); result.pop();
        switch(input[i])
        {
          case '&': result.push(x&&y); break;
          case '|': result.push(x||y); break;
          case '>': 
          if(input[i-2]=='<') 
          { result.push(Biconditional(x,y)); i-=2;} 
          else{
            result.push(Implication(x,y)); i-=1;
          }
          break;
        }
      }
      --i;
    }
  }
  return result.top()?"TRUE":"FALSE";
}
bool checkUndefinedError(string s){
    int find=s.find("0^0");
    if(find!=-1) return true;
    for (int i=0; i<(int)s.size();i++)
    {
      if(checkOperator(s[i])&&checkOperator(s[i+1])){
          if((s[i]=='+'||s[i]=='-')&&s[i+1]==s[i]) continue;
          if(s[i]=='+'&&s[i+1]=='-') continue;
          if(s[i]=='-'&&s[i+1]=='+') continue;
          return true;
      }
    }
    return false;
}
bool checkSyntaxError(string s){
  int find=s.find(".");
  if(find!=-1) return true;
  for (int i=0; i<(int)s.size();i++){
    if(s[i]=='('&&checkOperator(s[i+1])) return true; 
  }
  return false;
}
bool checkErrorLogic(string s){
  for (int i=0; i<(int)s.size();i++){
    if(s[i]=='&'&&s[i]==s[i+1]) return true;
    if(s[i]=='|'&&s[i+1]==s[i]) return true;
    if(s[i]=='|'&&(s[i+1]=='<'||s[i+1]=='-')) return true;
    if(s[i]=='~'&&(s[i+1]=='&'||s[i+1]=='|')) return true;
  }
  return false;
}
bool checkDividedbyZero(string s){
  int find=s.find("/0");
  return find!=-1;
}