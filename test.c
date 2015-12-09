#include "table.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "array.h"
#include <string.h>

/*Compare function used to compare two string values (pointed to by ip and ip2) are equal
 * ip, ip2 - pointers to two integers
 * Returns
 *    0 if values are equal, nonzero otherwize
 */
int compareString(void *ip,void *ip2){
    return strcmp((char*)ip, (char*)ip2);
}

/*Compare function used to compare two int values (pointed to by ip and ip2) are equal
 * ip, ip2 - pointers to two integers
 * Returns
 *    0 if values are equal, nonzero otherwize
 */
int compareInt(void *ip,void *ip2){
    return (*(int*)ip) - (*(int*)ip2);
}



/* Helper function to allocate memory for and initialize a integer pointer
 * the value pointed to will be i
 *   i the value to point at
 * Returns
 *   a int pointer to i
 */
int *intPtrFromInt(int i){
    int *ip=malloc(sizeof(int));
    *ip=i;
    return ip;
}



int main(void) {

    Table *table = table_create(compareString);
    //table_setKeyMemHandler(table, free);
    //table_setValueMemHandler(table,free);
    //char *key1 = "key1";
    //char *key2 = "key2";
    //char *value1 = "value1";
    //char *value2 = "value2";

    if(table_isEmpty(table)){
        printf("The table is empty\n");
    } else {
        printf("The table is not empty\n");
    }

    //printf("key 101 has value %d\n", *((int*)table_lookup(table, intPtrFromInt(101))));
    //table_insert(table, key1, value1);
    //table_insert(table, key2, value2);
    //table_remove(table, key1);

    //if (table_isEmpty(table)) {
    //    printf("The table is empty\n");
    //} else {
    //    printf("The table is not empty\n");
    //}

    //printf("key 101 has value %s\n", ((char *) table_lookup(table, key2)));
    table_free(table);
    //free(table);

    return 0;
}