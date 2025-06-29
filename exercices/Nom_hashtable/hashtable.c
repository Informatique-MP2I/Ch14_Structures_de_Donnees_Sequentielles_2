#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

/* const int MAX_SIZE_HASHTABLE = 100;*/
#define MAX_SIZE_HASHTABLE 100

/* Structure of the hashtable */
typedef struct hashtable{
  /* TODO */
} hashtable_s;

/* 
   Creates a new hashtable and initializes eventual variables
   Parameters : 
   Asserts    : 
   Return     : the pointer to the new empty hashtable
*/
hashtable_s *hashtable_create(){
  /* TODO */
  return NULL;
}

/* Hash function */
int hash(char *key){
  int h = 0;
  char c = key[0];
  while (c != '\0'){
    h = 31 * h + c;
    key++;
    c = *key;
  }
  return (h & INT_MAX) % MAX_SIZE_HASHTABLE;
}

/* 
   Add the given value to the hashtable
   Parameters : a new (key,value) to add
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : 
*/
void hashtable_add(char *key, int value, hashtable_s *hashtbl){
  /* TODO */
  return;
}

/* 
   Return the value of the given key from the given hashtable 
   Parameters : a key
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : the value associated to the key or INT_MIN if nothing is found
*/
int hashtable_find(char *key, hashtable_s *hashtbl){
  /* TODO */
  return 0;
}


/* 
   Decide if the given key already exits on the given hashtable
   Parameters : a key
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : true if the hashtable has an entry associated to key
                false else
*/
bool hashtable_mem(char *key, hashtable_s *hashtbl) {
  /* TODO */
  return false;
}

/* 
   Return the length the given hashtable 
   Parameters : the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : the length
*/
int hashtable_length(hashtable_s *hashtbl){
  /* TODO */
  return 0;
}

/* 
   Remove the entry associated to the given key from the given hashtable
   Parameters : a key
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : 
*/
void hashtable_remove(char *key, hashtable_s *hashtbl){
  /* TODO */
  return;
}

/* 
   Erase the hashtable
   Parameters : the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     :
*/
void hashtable_delete(hashtable_s *hashtbl){
  /* TODO */
  return;
}
