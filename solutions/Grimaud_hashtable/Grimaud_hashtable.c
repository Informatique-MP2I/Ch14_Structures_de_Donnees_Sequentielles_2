#include <stdio.h>
#include <stdbool.h>
#include "hashtable.h"

int main(int argc, char **argv){
  hashtable_s* my_ht = hashtable_create();

  /* luce, biLl, elie = 35 */
  hashtable_add("luce", 1, my_ht);
  hashtable_add("bILl", 2, my_ht);
  hashtable_add("elie", 3, my_ht);
  hashtable_add("fares", 4, my_ht);
  hashtable_add("nadir", 5, my_ht);

  printf("arsene - %d\n", hashtable_find("arsene", my_ht));
  printf("luce - %d\n", hashtable_find("luce", my_ht));
  printf("fares - %d\n", hashtable_find("fares", my_ht));
  hashtable_add("fares", 6, my_ht);
  printf("fares - %d\n", hashtable_find("fares", my_ht));
  
  printf("baptiste - %s\n", hashtable_mem("baptiste", my_ht) ? "true" : "false");
  hashtable_add("baptiste", 7, my_ht);
  printf("baptiste - %s\n", hashtable_mem("baptiste", my_ht) ? "true" : "false");

  printf("Length - %d\n", hashtable_length(my_ht));
  hashtable_add("nadir", 8, my_ht);
  printf("Length - %d\n", hashtable_length(my_ht));
  hashtable_add("adil", 9, my_ht);
  printf("Length - %d\n", hashtable_length(my_ht));

  hashtable_remove("elie", my_ht);
  hashtable_remove("nadir", my_ht);
  hashtable_remove("adil", my_ht);
  printf("Length - %d\n", hashtable_length(my_ht));

  hashtable_replace("luce", 3, my_ht);
  
  hashtable_print(my_ht);
  
  hashtable_delete(my_ht);
  
  return 0;
}
