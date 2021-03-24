#include <stdio.h>
#include <stdlib.h>

struct Array
{
//	int *A;
//u use also A[size];
    int A[10];
	int size;
	int length;
};

void Display(struct Array arr)
{
	printf("elements are\n");
	for(int i=0;i<arr.length;i++)
	printf("%d",arr.A[i]);
}

      /* ADD the end of the array length element */

void Append(struct Array *arr, int x)
{
	//1st check the arr have size or not
	if(arr->length<arr->size)
	//then add element an length position (if length is 5 then add 5th position to elem)
	arr->A[arr->length++]=x;
}

    /* Insert(add) any position of an element in Given Array */

void Insert(struct Array *arr, int index, int x )
{
    int i;
    //1st we check given element b/w the length of arr (0 to length)
    if(index >= 0 && index <= arr->length)
    {
	for(i=arr->length;i>index;i--)
	// index to right shift of all element then Insert the element
	   arr->A[i]=arr->A[i-1];
	   //Insert the element
	   arr->A[index]=x;
	   //increase length
	   arr->length++;
}
	}

	/* Delete operation */
void Delete(struct Array *arr, int index)
{
	//initialize delete element x is zero(0)
	int x=0;
	int i=0;
	if(index >=0 && index<=arr->length)
	{
		x=arr->A[index];
		//left shift all elements to delete index element using for loop
		for(i=index;i<arr->length-1;i++)
		arr->A[i]=arr->A[i+1];
		arr->length--;
		//return x; void fun se value nhi return hogi
	}

}

	     /*Linear Search */

int LinearSearch(struct Array arr,int key)
{
	int i;
	for(i=0;i<arr.length;i++)
	{
	  if(key==arr.A[i])
	  return i;
    }
	  return -1;
}

     /* Swap function */

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

   /* Improvement of LinearSearch */

int LinearSearch1(struct Array *arr,int key)
{
    int i;
	for(i=0;i<arr->length;i++)
	{
		if(key==arr->A[i])
		{
		// This is Transposition method its faster
		 swap(&arr->A[i],&arr->A[i-1]);
		 return i;
	    }
	    return -1;
	}
}

	     /* Binary Search */
	     /* iterative version*/

int BinarySearch(struct Array *arr,int key)
{
	int mid;
	int l=0;
	int h=arr->length-1;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr->A[mid])
		return mid;
		else if(key<arr->A[mid])
		h=mid-1;
		else
		l=mid+1;
	}
	return -1;
}

     /* Recursive version*/

int  RBinarySearch(struct Array *arr,int l,int h,int x)
{
	int mid;
	 l=0;
	 h=arr->length-1;
	if(l<=h)
	{
		mid=(l+h)/2;
		if(x==arr->A[mid])
		return mid;
		else if(x<arr->A[mid])
		return RBinarySearch(arr,l,mid-1,x);
		else
		return RBinarySearch(arr,mid+1,h,x);
	}
	return -1;
}
void Get(struct Array arr,int index)
{

    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array arr,int index,int key)
{

    if(index>=0 && index<arr.length)
    return arr.A[index]=key;
    return -1;

}
int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
      if(max<arr.A[i])
        max=arr.A[i];
    }
    return max;
}
int min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(min>arr.A[i])
            min=arr.A[1];
    }
     return min;
}

int sum(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
    {
        sum=sum+arr.A[i];
    }
     return sum;
}

float Avg(struct Array arr)
{
    return sum(arr)/arr.length;
}

      /* Reverse of Array m-1 */
void Reverse(struct Array *arr)
{
	int *B;
	int i,j;
	B=(int *)malloc(arr->length*sizeof(int));
	
	for(i=arr->length-1,j=0;i>=0;i--,j++)
	   B[j]=arr->[i];
	   for(i=0;i<arr->length;i++)
	   arr->[i]=B[i];
}      
      /*Revers Array m-2*/
void Reverse2(struct Array arr)
{
	int i,j;
	for(i=0,j=arr->length-1;i<j;i++,j--)
	   swap(&arr->A[i],&arr->A[j]);
}  
     /*Insertion an element of Sorted Array*/
void Insert(struct Array *arr,int indexele)
{
	int i=arr->length-1;
	if(arr->length==arr->size)
	   return ;
	   while(arr->A[i]>indexele)
	   {
	   	arr->A[i+1]=arr->A[i];
	   	i--;
	   }
	   arr->A[i+1]=indexele;
	   arr->length++;
}  

/* Check the Given Array is sort or not*/   

void isSort(struct Array arr)
{
	for(int i=0;i<length;i++)
	{
		if(arr->A[i]>arr->A[i+1])
		return 0;
	}
	return 1;
}
   /* All negative ele leftsize and positive on Right size*/
void REarrange(struct Array *arr)
{
	int i=0;j=arr->length;
	while(i<j)
	{
		while(arr->A[i]<arr->A[j]) i++;
		while(arr->A[i]>arr->A[j]) j--;
		if(i<j)
		swap(&arr->A[i],&arr->A[j]);
	}
}

   /* Marge operation of Array and its time complexity O(n+m)*/ 
void Marge(struct Array *arr1,struct Array *arr2)
{
	int i,j,k;
	struct Array *arr3=(struct Array *)malloc(sizeof(Array));
	while(i<arr1->length &&j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
		arr3->A[k++]=arr1->A[i++];
		else
		arr3->A[k++]=arr2->A[j++];
	}
	for(;i<arr1->length;i++)
	  arr3->A[k++]=arr1->A[i];
	for(;j<arr2->length;j++)
	  arr3->A[k++]=arr2->A[j];
	  
	arr3->length=arr1->length + arr2->length;  
	arr->size=10;
	return arr3;
}

       /* Union opretion using marge process */
    
 void Union(struct Array *arr1,struct Array *arr2)
{
	int i,j,k;
	struct Array *arr3=(struct Array *)malloc(sizeof(Array));
	while(i<arr1->length && j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
		  arr3->A[k++]=arr1->A[i++];
		else if(arr2->A[j]<arr1->A[i])
		  arr3->A[k++]=arr2->A[j++];
		else
		{ 
		   arr3->A[k++]=arr1[i++];
		   j++;
	    }
	}
	for(;i<arr1->length;i++)
	  arr3->A[k++]=arr1->A[i];
	for(;j<arr2->length;j++)
	  arr3->A[k++]=arr2->A[j];
	  
	arr3->length=k;  
	arr->size=10;
	return arr3;
}

       /*Intersection of Array using marge process */
       
void Intersection(struct Array *arr1, struct Array *arr2)
{
	int i,j,k;
	struct Array *arr3=(struct Array *)malloc(sizeof(Array));
	while(i<arr1->length && j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
		    i++;
		else if(arr2->A[j]<arr1->A[i])
		    j++;
		else
		{ 
		   arr3->A[k++]=arr1[i++];
		   j++;
	    }
	}
	for(;i<arr1->length;i++)
	  arr3->A[k++]=arr1->A[i];
	  
	arr3->length=k;  
	arr->size=10;
	return arr3;
}       
     /*Diffenence(A-B Array ) Operation using marge process*/  
void Diffenence(struct Array *arr1,struct Array *arr2)
{
	int i,j,k;
	struct Array *arr3=(struct Array *)malloc(sizeof(Array));
	while(i<arr1->length &&j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
		    arr3->A[k]=arr1->A[i++];
		else if(arr2->A[j]<arr1->A[i])
		    j++;
		else
		{ 
		    i++;
		   j++;
	    }
	}
	arr3->length=k;  
	arr->size=10;
	return arr3;
}      	   
	     
int main() 
{
	struct Array arr1;
	int ch;
	int x,index;
	printf("enter Size of arr1");
	scanf("%d",&arr1.size);
	arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;
    
    //for mrage to difference we use two more Array
    struct Array arr2;
    printf("enter Size of arr2");
	scanf("%d",&arr2.size);
	arr2.A=(int *)malloc(arr2.size*sizeof(int));
    arr2.length=0;
    
    struct Array arr3;
    printf("enter Size of arr3");
	scanf("%d",&arr3.size);
	arr3.A=(int *)malloc(arr3.size*sizeof(int));
    arr3.length=0;
do
 {
    printf("Menu Options\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. LinearSearch\n");
	printf("4. Sum\n");
	printf("5. Display\n");
	printf("6. Append\n");
	printf("7. LinearSearch1\n");
	printf("8. BinarySearch\n");
	printf("9. RBinarySearch\n");
	printf("10. Get\n");
	printf("11. Set\n");
	printf("12. Max\n");
	printf("13. Min\n");
	printf("14. Avg\n");
	printf("15. Reverse\n");
	printf("16. Reverse2\n");
	printf("17. isSort\n");
	printf("18. REarrange\n");
	printf("19. Marge\n");
	printf("20. Union\n");
	printf("21. Intersection\n");
	printf("22. Diffenence\n");

    printf("enter you choice ");
    scanf("%d",&ch);
  switch(ch)
   {
        case 1: printf("Enter an element and index");
                scanf("%d%d",&x,&index);
                Insert(&arr1,index,x);
                 break;
        case 2: printf("Enter index ");
                scanf("%d",&index);
                x=Delete(&arr1,index);
                printf("Deleted Element is %d\n",x);
                 break;
        case 3:printf("Enter element to search ");
               scanf("%d",&x);
               index=LinearSearch(&arr1,x);
               printf("Element index %d",index);
                break;
        case 4:printf("Sum is %d\n",Sum(arr1));
                break;
        case 5:Display(arr1);
                break;
        case 6:printf("Enter element to Add");
               scanf("%d",&x);
               printf("add element is",Append(&arr1,x));
                break;
        case 7:printf("Enter element to search ");
               scanf("%d",&x);
               index=LinearSearch1(&arr1,x);
               printf("Element index %d",index);
                break;
        case 8:printf("Enter element to search ");
               scanf("%d",&x);
               index=BinarySearch(&arr1,x);
               printf("Element index %d",index);
                break;
        case 9:printf("Enter element to search ");
               scanf("%d",&x);
               index=RBinarySearch(&arr1,x);
               printf("Element index %d",index);
                break;
        case 10:printf("Enter index ");
                scanf("%d",&index);
                x=Get(&arr1,index);
                printf("Element is %d\n",x);
                 break;
        case 11:printf("Enter an element and index");
                scanf("%d%d",&x,&index);
                Set(&arr1,index,x);
                 break;
        case 12:printf("Max is %d\n",Max(arr1));
                 break;
        case 13:printf("Min is %d\n",Min(arr1));
                 break;
        case 14:printf("Avg is %d\n",Avg(arr1));
                 break;
        case 15:printf("Enter an element of Array");
                scanf("%d",&arr1);
                Reverse(&arr);
                 break;
        case 16:printf("Enter an element of Array");
                scanf("%d",&arr1);
                Reverse2(&arr);
                 break;
        case 17:isSort(arr1);
                 break
        case 18:REarrange(&arr1);
                Display(arr1);
                 break;
        case 19:Marge(&arr1,&arr2);
                Display(arr3);
                 break;
        case 20:Union(&arr1,&arr2);
                Display(arr3);
                 break;
        case 21:Intersection(&arr1,&arr2);
                Display(arr3);
                 break;
        case 22:Union(&arr1,&arr2);
                Display(arr3);
                 break;
                
}
}while(ch<23);
    
	return 0;
}
