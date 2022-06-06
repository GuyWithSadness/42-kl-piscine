#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book, Book2;

int main( ) {
   /* book 1 specification */
   strcpy( Book.title, "C Programming");
   strcpy( Book.author, "Nuha Ali");
   strcpy( Book.subject, "C Programming Tutorial");
   Book.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;

   /* print Book1 info */
   printf( "Book 1 title : %s\n", Book.title);
   printf( "Book 1 author : %s\n", Book.author);
   printf( "Book 1 subject : %s\n", Book.subject);
   printf( "Book 1 book_id : %d\n", Book.book_id);

   /* print Book2 info */
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);

   return 0;
}
