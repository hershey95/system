#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef unsigned char* pointer;

bool is64bit()
{
	    return sizeof(long) == 8;
}

bool isBigEndian() {
    int a = 0x4567;
    if (*((char*)&a) == 0x67)
        return false;
    else
        return true;
}

void le_show_bytes(pointer x, size_t len)
{
    
    for (int i = len-1; i >= 0; i--)
    {
	printf("%.2X", x[i]);
    }
        printf("\n");
	return;
}

void be_show_bytes(pointer x, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%.2X", x[i]);
    }
        printf("\n");
        return;
}


int main(int argc, char* argv[])
{
	if(argc < 2){
		printf("Usage: ./a.out number\n");
		exit(0);
	}
	unsigned int a = atoi(argv[1]);

	printf("ARCH=%d\n", is64bit()? 64 : 32);
	printf("ORDERING=%s\n", isBigEndian()? "BIG_ENDIAN": "LITTLE_ENDIAN");

	printf("MYANS: DEC=%d HEX=", a);
	isBigEndian()? 
		//be_show_bytes(): le_show_bytes();
		be_show_bytes((pointer)&a, sizeof(unsigned int)): le_show_bytes((pointer)(&a), sizeof(unsigned int));

	printf("CHECK: DEC=%d HEX=%.8X\n", a, a);
	return 0;
}
