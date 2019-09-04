#include <stdio.h>
#include <conio.h>

void joomanji (int);

int main () {
   int n;

   scanf("%d", &n);

   joomanji(n);
   getch();
   return 0;
}

void joomanji (int n) {
//   printf("\t%d",n);
   int c, k;
   static int i = -2;
   if (n <= 0)
     return;

   k = n;
   i += 2;
//    printf("\n%d\n%d\n%d",n,k,i);
   for (c = 0; c < k; c++)
      printf("*");

   for (c = 0; c < i; c++)
      printf(" ");
   for (c = 0; c < k; c++)
        printf("*");

   printf("\n");

   joomanji(--n);
   if (n <= 0)
        return;
   n++;
   k = n ;

   i -= 2;
//    printf("\n%d\n%d\n%d",n,k,i);
   for (c = 0; c < k; c++)
      printf("*");

   for (c = 0; c < i; c++)
      printf(" ");
   for (c = 0; c < k; c++)
        printf("*");

   printf("\n");

}