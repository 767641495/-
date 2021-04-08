#include "HeadFile.h"

void BinaryFindMinMax(const int *arr, int left, int right, int *min, int *max, int len)
{
   *min = *max = arr[0];
   int i;
   for (i = 1; i < len; i++)
   {
      *max = arr[i] > *max ? arr[i] : *max;
      *min = arr[i] < *min ? arr[i] : *min;
   }
}