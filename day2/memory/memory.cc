#include <stdio.h>
#include <iostream>

int global_a;

void test0(){
	int test0_local_a;
	printf("&test0_local_a = %p\n",&test0_local_a);
}

int main(int argc,char** argv){
	int local_a;
	static int static_a;

	printf("test0     = %p\n",test0);
	printf("&static_a = %p\n",&static_a);
	printf("&global_a = %p\n",&global_a);
	printf("&local_a  = %p\n",&local_a);
	
	return 0;
}
