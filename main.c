#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define train_count (sizeof(train)/sizeof(train[0]))

float train[][2] = {
	{0, 0},
	{1, 4},
	{2, 8},
	{3, 12},
	{4, 16},
	{5, 20}
};

float rand_float(void)
{
	return (float)rand() / (float)RAND_MAX;
}

float cost(float w)
{
	float result = 0.0f;
	
	for(size_t i = 0; i < train_count; ++i)
	{
		float x = train[i][0];
		float y = x*w;
		float d = y - train[i][1];
		result += d*d;
	}
	result /= train_count;
	
	return result;
}

int main()
{
	srand(time(0 ));

	float w = rand_float()*10.0f;

	float eps = 1e-3;
	float rate = 1e-3;

	for(int i = 0; i < 100*100; ++i)
	{
		float dcost = (cost(w + eps) - cost(w))/eps;
		w -= rate*dcost;

		printf("cost: %f, w: %f\n", cost(w), w);
	}
	printf("-----------------------------\n");
	printf("%f\n", w);
	
	return 0;
}
