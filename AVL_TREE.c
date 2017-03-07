#include<stdio.h>
#include<malloc.h>

struct avl
{
int data;
struct avl*lf;
struct avl*rt;	
int height;
};


int height(struct avl*p)
{
	if(p==NULL)
	 return -1;
	return p->height; 
}



int max(int a,int b)
{
	return a>b?a:b;
}




void preorder(struct avl*q)
{
	if(q==NULL)
	 return;
	
printf(" %d",q->data);	
preorder(q->lf);
preorder(q->rt);
}


void inorder(struct avl*q)
{
	if(q==NULL)
	 return;
	
inorder(q->lf);
printf(" %d",q->data);		
inorder(q->rt);
}




void postorder(struct avl*q)
{
	if(q==NULL)
	 return;
	
postorder(q->lf);
postorder(q->rt);
printf(" %d",q->data);	
}


void levelrow(struct avl*p,int level)
{
	 if(level<=0||!p)
	    return;
	 
	if(level==1)
	   {
	   	printf(" %d",p->data);
	   	return;
	   }
	 levelrow(p->lf,level-1);
	 levelrow(p->rt,level-1);  
}


void levelorder(struct avl*p)
{ 
    if(!p)
      return;
	int h=height(p)+1,i;
	for(i=1;i<=h;i++)
	   {
	   	levelrow(p,i);
	   	printf("\n");
	   }
}


struct avl* leftleftrotation(struct avl*p)
{
	struct avl*q=p->lf;
	    p->lf=q->rt;
	    q->rt=p;
		q->height=max(height(q->lf),p->height)+1;
	    p->height=max(height(p->lf),height(p->rt))+1;
		return q; 
}



struct avl*rightrightrotation(struct avl*p)
{
	struct avl*q=p->rt;
	p->rt=q->lf;
	q->lf=p;
		q->height=max(height(q->lf),p->height)+1;
	    p->height=max(height(p->lf),height(p->rt))+1;
		return q; 
}




struct avl*leftrightrotation(struct avl*p)
{
p->lf=rightrightrotation(p->lf);
return leftleftrotation(p);	
}



struct avl*rightleftrotation(struct avl*p)
{
p->rt=leftleftrotation(p->rt);
return rightrightrotation(p);	
}


int getbalance(struct avl*p)
{
	if(p==NULL)
	  return 0;
	 return(height(p->lf)-height(p->rt)); 
}



struct avl* addele(struct avl*p,int data)
{
  if(p==NULL)
     {
     	p=(struct avl*)malloc(sizeof(struct avl));
     	p->data=data;
     	p->lf=NULL;
     	p->rt=NULL;
     	p->height=0;
     	return p;
     }   
  
  if(p->data>data)
    {
    p->lf=addele(p->lf,data);
	}   
  else
    {
    p->rt=addele(p->rt,data);
	}	
     
    p->height=max(height(p->lf),height(p->rt))+1;	
     
     
     int balance=getbalance(p);
     
   if(balance==2&&p->lf->data>data)
       {
      return leftleftrotation(p);	
	   }  
  else if(balance==2&&p->lf->data<data)
       {
      return leftrightrotation(p);	
	   } 
 else if(balance==-2&&p->rt->data<data)
       {
      return rightrightrotation(p);	
	   }  
 else if(balance==-2&&p->rt->data>data)
       {
      return rightleftrotation(p);	
	   } 
	   return p;   
}



struct avl*InorderSuccessor(struct avl*q)
  {
  	 while(q->lf!=NULL)
  	     { 
  	   	   q=q->lf;
		 }
		 return q;
  }


struct avl* delete_ele(struct avl*q,int data)
{
 if(q==NULL)
      {
  	    return NULL;
	  }	
 if(q->data>data)
    {
     	q->lf=delete_ele(q->lf,data);
	}	  
 else if(q->data<data)
    {
   		q->rt=delete_ele(q->rt,data);
    }	
  else
    {
    	struct avl*temp=q;
      if(q->lf&&!q->rt)
	        {
	       	 q=q->lf;
	       	 free(temp);
			}	
	  else if(!q->lf&&q->rt)
	        {
	        	q=q->rt;
	        	free(temp);
		    }
	  else if(q->lf&&q->rt)
	        {
	        	temp=InorderSuccessor(q->rt);
	        	q->data=temp->data;
	        	q->rt=delete_ele(q->rt,temp->data);
			}	
	  else if(!q->lf&&!q->rt)
	        {	
	          q=NULL;
	          free(temp); 	
			}
			int balance=getbalance(q);
			if(balance==2&&q->lf->data>data)
			   q=leftleftrotation(q);
			if(balance==2&&q->lf->data<data)
			   q=leftrightrotation(q);
			if(balance==-2&&q->rt->data<data)
			   q=rightrightrotation(q);
			if(balance==-2&&q->rt->data>data)
			   q=rightleftrotation(q);			      
	}  
	return q;
}


int main()
{
struct avl*q=NULL;

q=addele(q,10);
q=addele(q,6);
q=addele(q,16);
q=addele(q,4);
q=addele(q,9);
q=addele(q,13);
q=addele(q,7);
q=addele(q,2);
q=addele(q,5);
q=addele(q,11);
q=addele(q,15);
q=addele(q,28);
q=addele(q,3);

levelorder(q);

printf("\n#############\n");
q=delete_ele(q,10);

levelorder(q);
return 0;	
}
