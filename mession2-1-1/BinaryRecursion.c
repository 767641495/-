#include "HeadFile.h"

void binaryFindMinMax(const int *arr, int left, int right, int *min, int *max)
{
   if ((right - left) == 1)
   {
      *max = arr[left];
      *min = arr[right];
      if (arr[left] < arr[right])
      {
         *max = arr[right];
         *min = arr[left];
      }
   }
   else if ((right - left) == 0)
      *max = *min = arr[left];
   else
   {
      int min1, min2, max1, max2;
      binaryFindMinMax(arr, left, (right - left) / 2 + left, &min1, &max1);
      binaryFindMinMax(arr, (right - left) / 2 + 1 + left, right, &min2, &max2);
      min1 > min2 ? (*min = min2) : (*min = min1);
      max1 > max2 ? (*max = max1) : (*max = max2);
   }
}