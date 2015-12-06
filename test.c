#include "table.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*Compare function used to compare two int values (pointed to by ip and ip2) are equal
 * ip, ip2 - pointers to two integers
 * Returns
 *    0 if values are equal, nonzero otherwize
 */
int compareInt(void *ip,void *ip2){
    return (*(int*)ip) - (*(int*)ip2);
}

int main(void){
    Table *table = table_create(compareInt);
    if(table_isEmpty(table)){
        printf("The table is empty\n");
    } else {
        printf("The table is not empty\n");
    }

    return 0;
}