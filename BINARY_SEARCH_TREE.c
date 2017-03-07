#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct bst
{
int data;
struct bst*lf;
struct bst*rt;
};


struct dll
{
int data;
struct dll*prev;
struct dll*next;	
};


void dlladd(int data,struct dll**head)
{
	 struct dll*temp,*z;
	if((*head==NULL))
	   {
	   	temp=(struct dll*)malloc(sizeof(struct dll));
	   	temp->data=data;
	   	temp->prev=NULL;
	   	temp->next=NULL;
	   	(*head)=temp;
	   	return;
	   }
	   temp=(*head);
	   while(temp->next!=NULL)
	      {
	      	temp=temp->next;
	      	z=temp;
		  }
		  temp->next=(struct dll*)malloc(sizeof(struct dll));
		  temp=temp->next;
		  temp->data=data;
		  temp->next=NULL;
		  temp->prev=z;
}


struct bst* addele(struct bst*q,int data)
{
	if(q==NULL)
	 {
	 	 q=(struct bst*)malloc(sizeof(struct bst));
	 	 q->data=data;
		 q->lf=q->rt=NULL;
	 	return q;
	 }
	 
	else
	   {
	     if(q->data>data)
		 q->lf=addele(q->lf,data);
		 else
		 q->rt=addele(q->rt,data);	
	   } 
}


int  height_tree(struct bst*q)
{	
	if(!q)
	return -1;
   int z1=height_tree(q->lf);
   int z2=height_tree(q->rt);
   if(z1>z2)
     return z1+1;
   else
     return z2+1;  
}


void levelorder_rowwise(struct bst*p,int level)
{
	if(p==NULL)
	  return;
	if(level==1)
	  printf(" %d",p->data);
	else
	{
		levelorder_rowwise(p->lf,level-1);
		levelorder_rowwise(p->rt,level-1);
	}
	      
}


void levelorder(struct bst*p)
{
	int m=height_tree(p)+1;//+1 here because height of tree in geeksforgeeks start from 0 and i from -1
	int i;
	for(i=1;i<=m;i++)
	{
	 levelorder_rowwise(p,i);
	 printf("\n");
    }
}



void preorder(struct bst*q)
{
	if(q==NULL)
	   return;
	
	printf(" %d",q->data);
	
	preorder(q->lf);
	
	preorder(q->rt); 
}


void inorder(struct bst*q)
{
	if(q==NULL)
	   return;
	
	inorder(q->lf);
	
	printf(" %d",q->data);
	
	inorder(q->rt); 
}



void postorder(struct bst*q)
{
	if(q==NULL)
	   return;
	
	
	postorder(q->lf);
	
	postorder(q->rt);
	 
	printf(" %d",q->data);
}



int search(struct bst*q,int data)
{
  if(q==NULL)
    return 0;	
  if(q->data==data)
     return 1;
  else
    {
    	if(q->data>data)
    	 return search(q->lf,data);
    	else
		 return search(q->rt,data); 
	}	 	
}

int searchwithoutrec(struct bst*q,int data)
{
	if(q==NULL)
	 return 0;
	 while(q!=NULL)
	    {
	   	 if(q->data==data)
	   	    return 1;
	   	 else
			 {
			 if(q->data>data)
			   q=q->lf;
			 else
			   q=q->rt;  	
			 }   
		} 
	 if(!q)
	    return 0;	
}




int minele(struct bst*q)
{

if(q->lf==NULL)
  return q->data;
  	
minele(q->lf);	

}




int minelewithoutrec(struct bst*q)
{

if(q==NULL)
  return 0;

while(q->lf!=NULL)
 {
 	q=q->lf;
 }
   	
return q->data;  	
}



int maxele(struct bst*q)
{
	
if(q->rt==NULL)	
 return q->data;
 
 maxele(q->rt);
}






int maxelewithoutrec(struct bst*q)
{

if(q==NULL)
  return 0;

while(q->rt!=NULL)
 {
 	q=q->rt;
 }
   	
return q->data;  	
}




struct bst* del(struct bst*q,int data)
{
	int m;
	struct bst*temp;
	if(q==NULL)
	 return NULL;
	
	if(q->data!=data)
	 {
	if(q->data>data)
	  {
	  	q->lf=del(q->lf,data);
	  }
	else
	  {
	    q->rt=del(q->rt,data);
	  }
      }
     else
	    {
	   	 if(!q->lf)
	   	      {
	   	       temp=q;
			   q=q->rt;
			   free(temp);
			   return q;	   	
			  }
		 else if(!q->rt)
		      {
		       temp=q;
			   q=q->lf;
			   free(temp);
			   return q;	
			  }	  
		  else
		      {
		       m=maxele(q->lf);
		        q->data=m;
			   del(q->lf,m);  	
			  }	  
		} 
		return q;
}








struct bst*lca(struct bst*q,int n,int m)
{
if(q==NULL)
return NULL;

if(q->data>=n&&m>=q->data||q->data>=m&&n>=q->data)
  return q;
if(q->data>n)
return lca(q->lf,n,m);    	
	
else
return lca(q->rt,n,m);    	
}




int height(struct bst*q,int m)
{
	
	int i=0;
if(q==NULL)
 return 0;

   while(q->data!=m)
      {
       	++i;
		if(q->data>m)
		  q=q->lf;
		else
		  q=q->rt;        	
	  }
 	
	return i;
}






int isbst(struct bst*q)
{
if(q==NULL)
  return 1;
  
if(q->lf&&q->lf->data>q->data)
   return 0;
if(q->rt&&q->rt->data<q->data)
   return 0;
if(!isbst(q->lf)||!isbst(q->rt))
   return 0;
 return 1;          	
	
}





int isbstinorder(struct bst*root,int prev)
{
if(!root)
  return 1;
  
if(!isbstinorder(root->lf,prev)) 
  	return 0;
  if(root->data<prev)
     return 0;
     prev=root->data;
if(!isbstinorder(root->rt,prev)) 
    return 0;	 	
}




void bst_to_dll(struct bst*root,struct bst**head)
{
static struct bst*prev=NULL;
	
if(root==NULL)
   return;
   
  bst_to_dll(root->lf,head);
  if(prev==NULL) 
         {
     	   *head=root;
		 }	
	else
	    {
	      root->lf=prev;
		  prev->rt=root;	
		}
		prev=root;	 
   bst_to_dll(root->rt,head);		
}


void printdll(struct dll*q)
{
	
	while(q!=NULL)
	 {
	 	printf(" %d",q->data);
	 	q=q->next;
	 }
}


void bst_to_cirdll(struct bst*root,struct bst**head,struct bst**last)
{
	static struct bst*prev=NULL;
	if(root==NULL)
	  return;
    
	  bst_to_cirdll(root->lf,head,last);
	 if(prev==NULL)	 
	    {
	   	 *head=root;
		} 
	 else
	    {
	    	
	     root->lf=prev;	
	     prev->rt=root;
		}	
		prev=root;
		 if(root)
		*last=root;
	    bst_to_cirdll(root->rt,head,last);	
	   
}


void print_cir(struct bst*root)
 {
 	struct bst*temp=root;
 	do
	 {
	 	printf(" %d",temp->data);
	 	temp=temp->rt;
	 }
	 while(temp!=root);
	 
 }


int countdll(struct dll*p)
{
	int i=0;
	while(p!=NULL)
	   {
	   	i++;
	   	p=p->next;
	   }
	   return i;
}



struct bst*newnode(int data)
{
	struct bst*temp=(struct bst*)malloc(sizeof(struct bst));
	temp->data=data;
	temp->lf=NULL;
	temp->rt=NULL;
	return temp;
}


struct bst* dll_to_bst(struct dll**p,int n)
{
	struct bst*temp,*left;
     if(n<=0)
	   return NULL;
	 left=dll_to_bst(p,n/2);
	 temp=newnode((*p)->data);
	 temp->lf=left;
	 *p=(*p)->next;
	 temp->rt=dll_to_bst(p,n-n/2-1);

	 return temp;  	
}




struct bst*array_to_bst(int a[],int n)
{
	struct bst*temp,*left;
	static int i=0;
 if(n<=0)
  return NULL;
  	left=array_to_bst(a,n/2);
  	temp=newnode(a[i]);
  	++i;
  	temp->lf=left;
  	temp->rt=array_to_bst(a,n-n/2-1);
  	return temp;
 	
}



int min_kth_ele(struct bst*temp,int k,int *count)
{
	int p;
	if(temp==NULL)
	 return 0;
	              
	          if(temp->lf) 
	             {
		          p= min_kth_ele(temp->lf,k,count);
	             }
	                
					 if(*count==k)
	                    {
	                      return p;	
		                } 
	  
	                        ++(*count);
	                        
	                     if(*count==k)
	                    {
	                      return temp->data;	
		                }    
	
	    return min_kth_ele(temp->rt,k,count);	 
}

/*
void kth_fun(struct bst*q,int k)
{
	static int i=0;
  if(q==NULL)
    return;
    
	kth_fun(q->lf,k);
	 ++i;
	 if(i==k)
	   {
	     printf("The %d Element is as %d",k,q->data);
	     return;
       }
	kth_fun(q->rt,k);  
}
*/

void kth_fun2(struct bst*q,int k,int *count)
{

  if(q==NULL)
    return;
	kth_fun2(q->lf,k,count);
	 ++(*count);
	 if(*count==k)
	   {
	  printf("The %d Element is as %d",k,q->data);
	  return;
       }
	kth_fun2(q->rt,k,count);  
}


struct bst *kth_fun(struct bst *q,int k)
{
struct bst *knode=NULL;
static int i=0;
if(!q || !k)
return NULL;

knode=kth_fun(q->lf,k);
if(knode)
return knode;
++i;
if(i==k)
return q;
knode=kth_fun(q->rt,k);
return knode;
}

static int result=0;

void findKSmallest(struct bst *root,const int k)
{
	static int num=0;
if (root==NULL)
return;
findKSmallest(root->lf,k);
++num;
if(num>k)
 {
 	return;
 }
if (num==k)
{
result=root->data;
return;
}
findKSmallest(root->rt,k);
}


int main() 
{
struct bst*q=NULL;

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
/*
printf("THIS IS CALLED INORDER TRAVERSAL:- ");
inorder(q);

printf("\n\nTHIS IS CALLED PREORDER TRAVERSAL:- ");
preorder(q);

printf("\n\nTHIS IS CALLED POSTORDER TRAVERSAL:- ");
postorder(q);

int i=search(q,16);
if(i)
 printf("\n ITEM FOUND");
else
 printf("\n ITEM NOT FOUND"); 
 
 
 
 int i=searchwithoutrec(q,19);
if(i)
 printf("\n ITEM FOUND");
else
 printf("\n ITEM NOT FOUND"); 
 
 
printf(" %d",minele(q));
 
printf(" %d",maxele(q));

printf(" %d",minelewithoutrec(q));


printf(" %d",maxelewithoutrec(q));



q=del(q,10);

printf("\n\nTHIS IS CALLED PREORDER TRAVERSAL:- ");
preorder(q);



if(lca(q,10,1)==NULL)
printf("COMMING NULL");
else
printf("the lowest common ancestor %d\n",lca(q,10,1)->data);

int m=height(q,lca(q,10,1)->data);


printf("DISTANCE BETWEEN 10 and 1 is %d",height(q,10)+height(q,1)-2*m);



isbst(q)?printf("YES"):printf("NO");



isbstinorder(q,0)?printf("YES"):printf("NO");



struct bst*head=NULL;
bst_to_dll(q,&head);

printdll(head);
*/
      /*For binary search tree to circular double linked list*/
/*struct bst*head=NULL;
struct bst*temp=NULL;
bst_to_cirdll(q,&head,&temp);
temp->rt=head;//for circular
head->lf=temp;//for circular
print_cir(head);
*/  
      /*For double linked list to binary search tree*/ 

/*
struct dll*p=NULL;
dlladd(100,&p);
dlladd(200,&p);
dlladd(300,&p);
dlladd(400,&p);
dlladd(500,&p);
dlladd(600,&p);
dlladd(700,&p);
dlladd(800,&p);
dlladd(900,&p);
dlladd(1000,&p);

printdll(p);
struct bst*temp=dll_to_bst(&p,countdll(p));
printf("THE POSTORDER BINARY SEARCH TREE:- ");
postorder(temp);
printf("THE HEIGHT OF TREE IS %d",height_tree(temp));
levelorder(temp);
*/

      /*For binary search tree to circular double linked list*/
 
 /*
    int a[]={10,20,30,40,50,60,70,80,90,100};
 
    struct bst*temp= array_to_bst(a,sizeof(a)/sizeof(a[0]));     
    levelorder(temp);
  */
      
            /*For Kth smallest element in the binary search tree*/
       
      /*
	    kth_fun(q,11);//using static
     
	    int count=0;     
        kth_fun2(q,10,&count);//using without static
	    
	    printf("THE ELEMENT IS AS=> %d",kth_fun(q,10)->data);//best method ever
	    
		printf("THE ELEMENT IS AS=> %d",min_kth_ele(q,7,&count));    //not best dont prefer it
     */
     
     findKSmallest(q,5);
     printf(" %d",result);
return 0;
}
