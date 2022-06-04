void    ft_ultimate_ft(int *********nbr);

int main () {

   int  var;
   int  *ptr;
   int  **pptr;
   int  ***ppptr;
   int  ****pppptr;
   int  *****ppppptr;
   int  ******pppppptr;
   int  *******ppppppptr;
   int  ********pppppppptr;
   int  *********ppppppppptr;

   var = 3000;
   ptr = &var;
   pptr = &ptr;
   ppptr = &pptr;
   pppptr = &ppptr;
   ppppptr = &pppptr;
   pppppptr = &ppppptr;
   ppppppptr = &pppppptr;
   pppppppptr = &ppppppptr;
   ppppppppptr = &pppppppptr;

   ft_ultimate_ft(ppppppppptr);

   printf("%d", var);

   return 0;
}

void    ft_ultimate_ft(int *********nbr)
{
    *********nbr = 42;
}
