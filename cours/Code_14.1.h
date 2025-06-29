#ifndef HASHTABLE_H
#define HASHTABLE_H

/* Structure of the hashtable */
typedef struct hashtable hashtable_s;
/* Creates a new hashtable and initializes eventual variables
   Return     : the pointer to the new empty hashtable */
hashtable_s *hashtable_create();
/* Add the given value to the hashtable
   Parameters : a new (key,value) to add
                the address of the current hashtable
   Asserts    : if the hashtable is already created */
void hashtable_add(char *key, int value,hashtable_s *hashtbl);
/* Add the given value to the hashtable. If the entry already exists then replace its value.
   Parameters : a new (key,value) to add
                the address of the current hashtable
   Asserts    : if the hashtable is already created */
void hashtable_replace(char *key,int value,hashtable_s *hashtbl); 
/* Return the value of the given key from the given hashtable 
   Parameters : a key
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : the value associated to the key or INT_MIN if nothing is found */
int hashtable_find(char *key, hashtable_s *hashtbl);
/* Decide if the given key already exits on the given hashtable
   Parameters : a key
                the address of the current hashtable
   Asserts    : if the hashtable is already created 
   Return     : true if the hashtable has an entry associated to key, false otherwise */
bool hashtable_mem(char *key, hashtable_s *hashtbl);
/* Return the length the given hashtable 
   Parameters : the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : the length */
int hashtable_length(hashtable_s *hashtbl);
/* Remove the entry associated to the given key
   Parameters : a key
                the address of the current hashtable
   Asserts    : if the hashtable is already created
   Return     : the address of the updated hashtable */
void hashtable_remove(char *key, hashtable_s *hashtbl);
/* Erase the hashtable
   Parameters : the address of the current hashtable
   Asserts    : if the hashtable is already created */
void hashtable_delete(hashtable_s *hashtbl);
/* Affiche le contenu de la table de hachage.
   Parameters : the address of the current hashtable
   Asserts    : if the hashtable is already created */
void hashtable_print(hashtable_s *hashtbl);

#endif // HASHTABLE_H
