
#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choose = 0;
    StrList* p = StrList_alloc();
    int howmuchworld = 0;
    int in = 0;
    int i = 0;
    int index = 0;
    char* stir = NULL;
    char* stri = NULL;
    char* strin = NULL;
    int count = 0;
    int y=0;
    int x=0;
    do{
      scanf("%d", &choose);

    switch (choose) {
        case 1:
            scanf("%d", &howmuchworld);
            for (int i = 0; i < howmuchworld; i++) {
                char* userInput = malloc(sizeof(char) * 100);
                scanf("%s\n", userInput);
                if (userInput != NULL) {
                    StrList_insertLast(p, userInput);
                    free(userInput);
                }
            }
            break;

        case 2:
            scanf("%d", &in);
            stri = malloc(sizeof(char) * 100);
            if(stri!=NULL){
                scanf("%s", stri);
                StrList_insertAt(p, stri, in);
                free(stri);
             }
            break;

        case 3:
            if(p==NULL);
            else{StrList_print(p);}
            printf("\n");
            break;

        case 4:
            x=StrList_size(p);
            printf("%d",x);
            printf("\n");
            break;

        case 5:
            scanf("%d", &i);
            StrList_printAt(p, i);
            printf("\n");
            break;

        case 6:
            y=StrList_printLen(p);
            printf("%d",y);
            printf("\n");
            break;

        case 7:
            strin = malloc(sizeof(char) * 100);
            scanf("%s", strin);
            if (strin != NULL) {
                count = StrList_count(p, strin);
                printf("%d", count);
                printf("\n");
                free(strin);
            }
            break;

        case 8:
            stir = malloc(sizeof(char) * 100);
            if (stir != NULL) {
                scanf("%s", stir);
                StrList_remove(p, stir);
                free(stir);
            }
            break;

        case 9:
            scanf("%d", &index);
            StrList_removeAt(p, index);
            break;

        case 10:
            StrList_reverse(p);
            break;

        case 11:
            StrList_free(p);
            p=StrList_alloc();
            break;

        case 12:
            StrList_sort(p);
            break;

        case 13:
            printf("%s\n", StrList_isSorted(p) ? "true" : "false");
            break;

            default:
            break;
    }
    }
    while(choose!=0);
    

    // Free the entire linked list and associated memory
    StrList_free(p);

    return 0;
}
