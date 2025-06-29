#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE_HASHTABLE 100
/* const int MAX_SIZE_HASHTABLE = 100; */

/* Structure of the hashtable */
typedef struct entry {
  char *key;
  int value;
  struct entry *next;
} entry_s;

typedef struct hashtable{
  int nb_entry;
  entry_s *bucket[MAX_SIZE_HASHTABLE];
} hashtable_s;

/* 
   Creates a new hashtable and initializes eventual variables
   Parameters : 
   Asserts    : 
   Return     : the pointer to the new empty hashtable
*/
hashtable_s *hashtable_create(){
  hashtable_s *ht=(hashtable_s *)malloc(sizeof(hashtable_s));
  assert(ht != NULL);
  for (int i = 0; i< MAX_SIZE_HASHTABLE; i++){
    ht->bucket[i] = NULL;
  }
  ht->nb_entry = 0;
  return ht;
}

/* Hash function */
int hash(char *key){
  unsigned int h = 0;
  char c = key[0];
  while (c != '\0'){
    h = 31 * h + c;
    key++;
    c = *key;
  }
  return h % MAX_SIZE_HASHTABLE;
}

/* 
   Add the given value to the hashtable
   Parameters : a new (key,value) to add
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : 
*/
void hashtable_add(char *key, int value, hashtable_s *hashtbl){
  assert(hashtbl != NULL);
  
  /* compute hash */
  int h = hash(key);

  /* create the new entry */
  entry_s *e=(entry_s *)malloc(sizeof(entry_s));
  assert(e != NULL);
  e->key = key;
  e->value = value;

  /* add the new entry */
  e->next = hashtbl->bucket[h];
  hashtbl->bucket[h] = e;
  hashtbl->nb_entry++;
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
  assert(hashtbl != NULL);
  
  /* compute hash */
  int h = hash(key);

  /* see if the key exists */
  entry_s *e = hashtbl->bucket[h];
  while (e!=NULL){
    if (strcmp(key, e->key) == 0) {
      return e->value;
    }
    e = e->next;
  }
  return INT_MIN;
}


/* 
   Decide if the given key already exits on the given hashtable
   Parameters : a key
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : true if the hashtable has an entry associated to key
                false otherwise
*/
bool hashtable_mem(char *key, hashtable_s *hashtbl) {
  assert(hashtbl != NULL);
  
  /* compute hash */
  int h = hash(key);

  /* see if the key exists */
  entry_s *e = hashtbl->bucket[h];
  while (e!=NULL){
    if (strcmp(key, e->key) == 0) {
      break;
    }
    e = e->next;
  }

  return (e != NULL);
}

/* 
   Return the length the given hashtable 
   Parameters : the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : the length
*/
int hashtable_length(hashtable_s *hashtbl){
  assert(hashtbl != NULL);
  return hashtbl->nb_entry;
}

/* 
   Remove the entry associated to the given key from the given hashtable
   Parameters : a key
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : 
*/
void hashtable_remove(char *key, hashtable_s *hashtbl){
  assert(hashtbl !=NULL);
  /* compute hash */
  int h = hash(key);

  /* see if the key exists */
  entry_s *e = hashtbl->bucket[h];
  entry_s **p = &hashtbl->bucket[h];

  while (e!=NULL){
    if (strcmp(key, e->key) == 0){
      break;
    }
    p = &(e->next);
    e = e->next;
  }
  assert(e!=NULL);
  *p = e->next;
  free(e);
  hashtbl->nb_entry--;
  
  return;
}

/* 
   Erase the hashtable
   Parameters : the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     :
*/
void hashtable_delete(hashtable_s *hashtbl){
  assert(hashtbl !=NULL);

  entry_s *e;
  entry_s *next;
  
  for(int i=0;i<MAX_SIZE_HASHTABLE;i++){
    e = hashtbl->bucket[i];
    while(e!=NULL){
      next = e->next;
      free(e);
      e = next;
    }
  }
  free(hashtbl);
  return;
}

/* 
   Affiche le contenu de la table de hachage.
   Parameters : the address of the current hashtable
   Asserts    : if the hashtable is already created
   Retrun     :
*/
void hashtable_print(hashtable_s *hashtbl) {
  assert(hashtbl != NULL);

  printf("Hashtable contents:\n");
  for (int i = 0; i < MAX_SIZE_HASHTABLE; i++) {
    entry_s *entry = hashtbl->bucket[i];
    if (entry != NULL) {
      printf("Bucket[%d]: ", i);
      while (entry != NULL) {
        printf("(%s, %d) ", entry->key, entry->value);
        entry = entry->next;
      }
      printf("\n");
    }
  }
} 

/* 
   Add the given value to the hashtable. If the already exists then replace its value.
   Parameters : a new (key,value) to add
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : 
*/
void hashtable_replace(char *key, int value, hashtable_s *hashtbl){
  assert(hashtbl != NULL);
  
  /* compute hash */
  int h = hash(key);

  /* see if the key already exists */
  entry_s *e = hashtbl->bucket[h];
  while (e!=NULL){
    if (strcmp(key, e->key) == 0) {
      break;
    }
    e = e->next;
  }

  /* if the key does not exists then create an entry */
  if (e == NULL){
      /* create a new entry */
      e=(entry_s *)malloc(sizeof(entry_s));
      assert(e != NULL);
      e->key = key;
      e->next = hashtbl->bucket[h];
      hashtbl->bucket[h] = e;
      hashtbl->nb_entry++;
  }
  e -> value = value;

  return;
}
