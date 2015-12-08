/*
 * Copyright 2012 Johan Eliasson (johane@cs.umu.se). TillÃ¥telse ges fÃ¶r anvÃ¤ndning 
 * pÃ¥ kurserna i Datastrukturer och algoritmer vid UmeÃ¥ Universitet. All annan 
 * anvÃ¤ndning krÃ¤ver fÃ¶rfattarens tillstÃ¥nd.
 */

#ifndef ARRAY_SIZE
#define ARRAY_SIZE 12000
#endif
#include <stdbool.h>
#include "table.h"
#include "array.h"


/* Creates a table.
 *  compare_function - Pointer to a function that is called for comparing
 *                     two keys. The function should return <0 if the left
 *                     parameter is smaller than the right parameter, 0 if
 *                     the parameters are equal, and >0 if the left
 *                     parameter is larger than the right item.
 * Returns: A pointer to the table. NULL if creation of the table failed. */
Table *table_create(CompareFunction *compare_function){
    MyTable *t = calloc(sizeof (MyTable),1);
    if (!t)
        return NULL;
    t->values=array_create(1, 0, ARRAY_SIZE);
    array_setMemHandler(t->values, free);
    t->cf = compare_function;
    return t;
}

/* Install a memory handling function responsible for removing a key when removed from the table
 *  table - Pointer to the table.
 *  freeFunc- Pointer to a function that is called for  freeing all
 *                     the memory used by keys inserted into the table*/
void table_setKeyMemHandler(Table *table, KeyFreeFunc *freeFunc){
    MyTable *t = (MyTable*)table;
    t->keyFree=freeFunc;
}


/* Install a memory handling function responsible for removing a value when removed from the table
 *  table - Pointer to the table.
 *  freeFunc- Pointer to a function that is called for  freeing all
 *                     the memory used by values inserted into the table*/
void table_setValueMemHandler(Table *table,ValueFreeFunc *freeFunc){
    MyTable *t = (MyTable*)table;
    t->valueFree=freeFunc;
}

/* Determines if the table is empty.
 *  table - Pointer to the table.
 * Returns: false if the table is not empty, true if it is. */
bool table_isEmpty(Table *table){
    //loop through the whole array and check if all Null pointers
    MyTable *t = (MyTable*)table;
    int i = 0;

    for ( int i = *((int*)array_inspectValue(array_low(t->values),0)); i > *((int*)array_inspectValue(array_high(t->values),0)); i++){
        if(!array_hasValue(t->values, i)){
            return 1;
        }
    }

    return 0;
}

/* Inserts a key and value pair into the table. If memhandlers are set the table takes
 * ownership of the key and value pointers and is responsible for 
 * deallocating them when they are removed.
 *  table - Pointer to the table.
 *  key   - Pointer to the key.
 *  value - Pointer to the value.
 */
void table_insert(Table *table, KEY key, VALUE value){
    MyTable *t = (MyTable*)table;
}

/* Finds a value given its key.
 *  table - Pointer to the table.
 *  key   - Pointer to the item's key.
 * Returns: Pointer to the item's value if the lookup succeded. NULL if the
 *          lookup failed. The pointer is owned by the table type, and the
 *          user should not attempt to deallocate it. It will remain valid
 *          until the item is removed from the table, or the table is
 *          destroyed. */
VALUE table_lookup(Table *table, KEY key){
    MyTable *t = (MyTable*)table;

}

/* Removes an item from the table given its key.
 *  table - Pointer to the table.
 *  key   - Pointer to the item's key.
 */
void table_remove(Table *table, KEY key);

/* Destroys a table, deallocating all the memory it uses.
 *  table - Pointer to the table. After the function completes this pointer
 *          will be invalid for further use. */
void table_free(Table *table){
    MyTable *t = (MyTable*)table;
    TableElement *i;
    dlist_position p=dlist_first(t->values);

        while (!dlist_isEnd(t->values,p)) {
            i=dlist_inspect(t->values,p);
            if(t->keyFree!=NULL)
                t->keyFree(i->key);
            if(t->valueFree!=NULL)
                t->valueFree(i->value);
            p=dlist_remove(t->values,p);
        }
        array_free(t->values);
        free(t);
}
