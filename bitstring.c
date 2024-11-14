#include<stdio.h>
int superSet[20],SuperSetSize=0,
SetA[20],SetASize=0,
SetB[20],SetBSize=0,
bitStringA[20],bitStringB[20],
bitStringUnion[20],bitStringIntersection[20];
int isBitStringReady=0;
int search(int a[],int size,int elem)
{
	for(int i=0;i<size;i++)
	{
		if(a[i]==elem) return i;
	}
	return -1;
}
void getSet(int a[],int size)
{
	printf("Enter Set Elements:");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
}
void printSet(int a[],int size)
{
	printf("{");
	for(int i=0;i<size;i++)
	{	
		printf("%d",a[i]);
		if(i<size-1) printf(",");
	}
	printf("}");
}
void printBitString(int bitString[])
{
	printf("{");
	for(int i=0;i<SuperSetSize;i++)
	{	
		printf("%d",bitString[i]);
		if(i<SuperSetSize-1) printf(",");
	}
	printf("}\n");
}
void generateBitString(int Set[],int SetSize,int bitString[])
{
	for(int i=0;i<SuperSetSize;i++) bitString[i]=0;//loop 5 times
	for(int i=0;i<SetSize;i++)//loo 3 times
	{
		int pos=search(superSet,SuperSetSize,Set[i]);
		if(pos>=0) bitString[pos]=1;
	}
}
void generateBitStrings() 
{
	generateBitString(SetA, SetASize, bitStringA); 
	generateBitString(SetB, SetBSize, bitStringB); 
	printf("\nSet A Bit String: ");
	printBitString(bitStringA);
	printf("Set B Bit String: ");
	printBitString(bitStringB);
	isBitStringReady = 1; 
}
void setUnion()//OR operation on 2 set AND Operation
{
	for(int i=0;i<SuperSetSize;i++)
	{
		bitStringUnion[i]=bitStringA[i]|bitStringB[i];
	}
}
void setIntersection() 
{
	for (int i = 0; i < SuperSetSize; i++)
	{
		bitStringIntersection[i] = bitStringA[i] & bitStringB[i];
   	}
}
void printResultAsSet(int bitString[]) 
{
	printf("{ ");
	int first = 1;
	for (int i = 0; i < SuperSetSize; i++) 
	{	
		if (bitString[i]) 
		{ 
			if (!first) printf(", "); 
			printf("%d", superSet[i]);
			first = 0; 
		}		
	}
	printf(" }\n");
}
int main()
{
	printf("Set Operations Using:Union and Intersection\n");
	printf("Enter Super Set Size:");
	scanf("%d",&SuperSetSize);
	getSet(superSet,SuperSetSize);
	printf("Enter Set A Size: ");
	scanf("%d", &SetASize);
	getSet(SetA, SetASize);
	printf("Enter Set B Size: ");
	scanf("%d", &SetBSize);
	getSet(SetB, SetBSize);
	generateBitStrings();
	if(isBitStringReady)
	{
		printf("\nSet Union: ");
		setUnion();
		printBitString(bitStringUnion); 
		printf("Print union as set: ");
		printResultAsSet(bitStringUnion); 
		printf("\nSet Intersection: ");
		setIntersection();
		printBitString(bitStringIntersection); 
		printf("Print intersection as set: ");
		printResultAsSet(bitStringIntersection);
	} 
	else 
	{
		printf("\nBit strings not generated!"); 
	}
	return 0;
}
