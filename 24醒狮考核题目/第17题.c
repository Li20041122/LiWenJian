#include<stdio.h>
#define VALUE_B 217
#define VALUE_C 219.321
static int alpha;
static float beta;
void STDRxCallback(int* b, float* c)
{
   *b = VALUE_B;
   *c = VALUE_C;
}
void (*callback)(int* c, float* b);
int main()
{
	//∏≥÷µ 
	callback=STDRxCallback;
	//≥ı ºªØ 
	callback(&alpha,&beta);
	printf("alpha:%d\n",alpha);
	printf("beta:%.3f\n",beta);
	return 0;
}
