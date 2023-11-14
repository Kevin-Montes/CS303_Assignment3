#include <iostream>
#include <string>
#include <stack>
#include <vector>

 bool parenthesisCheck(std::string string)
{
std::stack<char> parenStack;

for(int i = 0; i < string.length(); i++){

  if(string[i] == '(' || string[i] == '[' || string[i] == '{' ){
    parenStack.push(string[i]);
    continue;
  }
  switch(string[i]){
    case ')':
      if (parenStack.empty())
        return false;


      if(!(parenStack.top() == '('))
        return false;
      parenStack.pop();
      break;

    case '}':
      if (parenStack.empty())
        return false;

      if(!(parenStack.top() == '{'))//if its not the proper parenthesis it must be a different one therefore unbalanced
        return false;
       parenStack.pop();
      break;

    case ']':
      if (parenStack.empty())
        return false;
      if(!(parenStack.top() == '['))
        return false;
      parenStack.pop();
      break;
  }
}//if its empty it is balanced, if it is not then unbalanced
  if (parenStack.empty())
    return true;
  return false;
}

int assignPriority(char operat)//self explanatory
{
  if(operat=='+'|| operat=='-')
    return 1;
  else if (operat =='*'||operat=='/'||operat=='%')
    return 2;
  else
    return 0;
}
std::string infixToPostfix(std::string infix)
{
  std::stack<char> stack;
  std::string postfix;
  for(int i = 0; i < infix.length(); i++)
  {
    char tempHolder=infix.at(i);
    if(tempHolder=='+'||tempHolder=='-'||tempHolder=='*'||tempHolder=='/'||tempHolder=='%')//checks for operators
    {
      if(!stack.empty())
      {
        if(assignPriority(stack.top())< assignPriority(tempHolder))
        {
        stack.push(tempHolder);
          
      }
        else
        {
           std::cout<<stack.top()<<"\n";
          postfix.push_back(stack.top());
          
          stack.pop();
          
          stack.push(tempHolder);
        
       
      }
      }
      else
      {
        stack.push(tempHolder);
      }
    }//puts beggining parenthesisi in stack
    else if(tempHolder=='('||tempHolder=='['||tempHolder=='{')
    {
      stack.push(tempHolder);
    }//goes until finds front parenthesis, does not need to know which kind as we checked for balance
    else if(tempHolder==')'||tempHolder==']'||tempHolder=='}')
    {
      while(stack.top()!='('&& stack.top()!='{' && stack.top()!='[')
        {
          tempHolder=stack.top();
          stack.pop();
          postfix.push_back(tempHolder);
        }
      stack.pop();//gets rid of beggining parenthesis
    }
    else
    {
      postfix.push_back(tempHolder);
    }
    
    
      
      
    
      
  }//returns rest of stack
  while(!stack.empty())
    {
      postfix.push_back(stack.top());
      stack.pop();
    }
  return postfix;
}//just removed first element
void dequeue(std::vector<int>& queue)
{
  std::vector<int> tempQueue;
  
  for(int i=1;i<queue.size();i++)
    {
      tempQueue.push_back(queue.at(i));
    }
  queue=tempQueue;
    
  
  
}

int main() 
{
  std::string infix;
  std::cout<<"Enter a statement to convert infix to postfix\n";
  std::cin>>infix;
  if(parenthesisCheck(infix))
    std::cout<<"in postfix: "<<infixToPostfix(infix)<<"\n";
  else
    std::cout<<"Not Balanced\n";
  
  std::vector<int> testQueue={1,2,3,4};
  dequeue(testQueue);
  for(int i=0;i<testQueue.size();i++)
    {
      std::cout<<testQueue.at(i);//proves that 1 got removed
    }
    std::cout<<"\n";
  std::cout<<"Elements in list: "<<testQueue.size()<<"\n";//prints num of elements
  std::cout<<testQueue.at(0)<<"\n";//first element
  testQueue.push_back(5);for(int i=0;i<testQueue.size();i++)
  {
    std::cout<<testQueue.at(i);//proves that 1 got removed
  }
  std::cout<<"\n";
  
  return 0;
};
 
