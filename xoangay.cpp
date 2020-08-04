#include <iostream>
using namespace std;

int a[5];

int main()
{
   int n;
   cin >> n;
   int inp;
   for (int i = 1; i <= n; i++)
   {
      cin >> inp;
      a[inp]++;
   }

   int taxi = 0;

   if (a[3] >= a[1])
   {
      taxi += a[1];
      a[3] -= a[1];
      a[1] = 0;
   }
   else
   {
      taxi += a[3];
      a[1] -= a[3];
      a[3] = 0;
   }

   taxi += a[2] / 2;
   a[2] = a[2] % 2;

   if (a[2] > (a[1] / 2))
   {
      taxi += a[1] / 2;
      a[2] -= a[1] / 2;
      a[1] = a[1] % 2;
      if (a[1] > 0)
      {
         a[2]--;
         taxi++;
         a[1] = 0;
      }
   }
   else
   {
      taxi += a[2];
      a[1] -= a[2] * 2;
      a[2] = 0;
   }

   taxi += a[1] / 4;
   a[1] = a[1] % 4;
   if (a[1] > 0)
   {
      taxi++;
      a[1] = 0;
   }

   for (int i = 1; i <= 4; i++)
   {
      taxi += a[i];
   }

   cout << taxi;
}