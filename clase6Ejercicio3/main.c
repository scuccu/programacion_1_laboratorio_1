#include <stdio.h>
#include <stdlib.h>

int main()
{
      int vector[5]={3,2,9,6,5};
      int auxiliar;
      int i;
      int j;

      for(i=0; i<4;i++)
      {
          for(j=i+1;j<5;j++)
          {
              if(vector[i]>vector[j])
              {
                    auxiliar=vector[i];
                    vector[i]=vector[j];
                    vector[j]=auxiliar;
              }
          }

      }

      for(i=0; i<5; i++)
      {
          printf("%d\n",vector[i]);
      }
    return 0;
}
