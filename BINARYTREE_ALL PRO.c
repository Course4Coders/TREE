#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

#define MAX1 20





struct bs
{
int data;
struct bs* lf;
struct bs* rt;	
};








struct stack
{
int top;	
struct bs**arr;
};





struct queue
{
int front;
int rear;
struct bs**arr;	
};





struct stack*createstack()
{

struct stack*q=(struct stack*)malloc(sizeof(struct stack));	
q->top=-1;	
q->arr=(struct bs**)malloc(sizeof(struct bs*)*MAX1);

}



struct queue*createqueue()
{
	
struct queue*z=(struct queue*)malloc(sizeof(struct queue));
z->front=z->rear=-1;
z->arr=(struct bs**)malloc(sizeof(struct bs*)*MAX1);

}



int isqueuefull(struct queue*q)
{
return(q->rear==MAX1);	
}






int isstackfull(struct stack*q)
{
return(MAX1==q->top-1);	
}





int isqueueempty(struct queue*q)
{
return(q->front==-1);	
}





int isstackempty(struct stack*q)
{
return(q->top==-1);	
}






void enqueue(struct queue*q,struct bs*m)
{
	if(isqueuefull(q))
	  {
	  	printf("QUEUE is FULL");
	  	return;
	  }
	 
	   q->arr[++q->rear]=m;
	   
	   if(q->front==-1)
	       {
	     	q->front=q->rear;
		   }  
}





void push(struct stack*q,struct bs*m)
{
  if(isstackfull(q))
    {
    	printf("STACK IS FULL\n");
    	return;
	}

  q->arr[++q->top]=m;	
}







struct bs* dequeue(struct queue*q)
{
	
	struct bs*temp;
	
	if(isqueueempty(q))
	  {
	  	printf("QUEUE is EMPTY");
	  	return NULL;
	  }
	 
	   temp=q->arr[q->front];
	   
	   if(q->front==q->rear)
	       {
	   
	       q->rear=q->front=-1;
             return temp;   
		   }
	    else
		    ++q->front;	
			
		    return temp;		  
}





struct bs* pop(struct stack*q)
{
	if(isstackempty(q))
	  {
	  	printf("STACK IS EMPTY\n");
	  	return NULL;
	  }
	
	return(q->arr[q->top--]);
}







struct bs*front(struct stack*q)
{ 
    return(q->arr[q->top]);	
}



struct bs*newNode(int data)
{
struct bs*q=(struct bs*)malloc(sizeof(struct bs));
q->data=data;
q->lf=NULL;
q->rt=NULL;	
return q;
}






void preorder(struct bs*q)
{
	if(!q)
	 return;
	else
	 {
	 	printf(" %d",q->data);
		preorder(q->lf);
		preorder(q->rt);
	 } 
}






void inorder(struct bs*q)
{
	if(!q)
	 return;
	else
	 {
		inorder(q->lf);
		printf(" %d",q->data);
		inorder(q->rt);
	 } 
}




void postorder(struct bs*q)
{
	if(!q)
	 return;
	else
	 {
		postorder(q->lf);
		postorder(q->rt);
		printf(" %d",q->data);
	 } 
}




void levelorder(struct bs*q)
 {
 	
  struct queue*z=createqueue();	
 	
 	if(!q)
    return;
    enqueue(z,q);
    
    while(1)
	    {
	      if(isqueueempty(z))
		      break; 	
	    	 q=dequeue(z);
	    	printf(" %d",q->data);
	   	 if(q->lf)
	   	  enqueue(z,q->lf);
	   	 if(q->rt)
		  enqueue(z,q->rt); 
		}  
		
		
}




void preOrderIterative(struct bs*q)
{
	
	struct stack*s=createstack();
	if(!q)
	  {
	  	printf("EMPTY\n");
	  	return;
	  }
    
	  
	while(1)
	    {
	  	 while(q)
	  	     {
	  	   	  printf(" %d",q->data);
	  	   	  push(s,q);
	  	   	   q=q->lf;
			 }
			 if(isstackempty(s))
			     break;
			     q=pop(s);
			     q=q->rt;
		}  
	  
}










void inOrderIterative(struct bs*q)
{
	
	struct stack*s=createstack();
	if(!q)
	  {
	  	printf("EMPTY\n");
	  	return;
	  }
    
	  
	while(1)
	    {
	  	 while(q)
	  	     {
	  	   	  
	  	   	  push(s,q);
	  	   	   q=q->lf;
			 }
			 if(isstackempty(s))
			     break;
			     q=pop(s);
			     printf(" %d",q->data);
			     q=q->rt;
		}  
	  
}





void postOrderIterative_twostack(struct bs*q)
      {
      	struct stack*s1=createstack();
      	struct stack*s2=createstack();
      	
      	  if(!q)
      	    {
      	  	 printf("EMPTY POST ORDER\n");
      	  	 return;
			}
		      push(s1,q);
		    
		   while(!isstackempty(s1))
		       {
		        q=pop(s1);
		        
		        push(s2,q);
		        
		        if(q->lf)
		          push(s1,q->lf);
				if(q->rt)
				  push(s1,q->rt);   	
				   	
			   } 	
			while(!isstackempty(s2))
			     {
			     	printf(" %d",pop(s2)->data);
				 }
			
	  }

void displaystack(struct stack*s)
{
	int i;
	printf("\n");
  for(i=0;i<=s->top;i++)	
 printf(" %d",s->arr[i]->data);
 printf("\n");	
}










void postOrderIterative_onestack(struct bs*q)
    {
       int i;
	   struct stack*s=createstack();	
	        	
    	if(!q)
    	  {
    	  	printf("EMPTY\n");
    	  	return;
		  }	  
		  while(1)
		     {
		     	i=1;
		       while(q)
			       {
			       	if(q->rt)
			       	push(s,q->rt);
					push(s,q);
					q=q->lf;   
				   }
				  
				   q=pop(s);
				  
			    while(i)
			      {      
			      	     i=0;
				          if(q->rt==front(s))
				             {
							  struct bs*temp=pop(s);
				              push(s,q);
				              q=temp;
			                 }
			              else
				             {
				              printf(" %d",q->data);
				              	  
				              if(isstackempty(s))
				              {
				              	return;//don't break here otherwise you have to give outside also
				              }
				               q=pop(s);  
				            
					           i=1; 	
				             }
			      }
			 }  
	}







int main()
{
  struct bs* root = NULL;
    root = newNode(1);
    root->lf = newNode(2);
    root->rt = newNode(3);
    root->lf->lf = newNode(4);
    root->lf->rt = newNode(5);
    root->rt->lf = newNode(6);
    root->rt->rt = newNode(7);
    
	/*
    printf("PRE-ORDER ");
    preorder(root);printf("\n");
    printf("IN-ORDER ");
    inorder(root);printf("\n");
    printf("POST-ORDER ");
    postorder(root);printf("\n");
    printf("LEVEL-ORDER ");
    levelorder(root);printf("\n");     
    printf("In order traversal of binary tree is :\n");
    inOrderIterative(root);
    printf("post order traversal of binary tree using two_stack is :\n");
    postOrderIterative_twostack(root); 
    printf("post order traversal of binary tree using one_stack is :\n");
    postOrderIterative_onestack(root);
    */
    
   return 0;
}
