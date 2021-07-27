#include<stdio.h>
#include<stdlib.h>

struct Node {
    int num;
    struct Node* next;
} *first, * cur, * pre, * newrec;

void mfree(struct Node* first) {
    struct Node* temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        free(temp);
        temp = NULL;
    }
}

int main(void) {
    int num;
    first = NULL;

    while (scanf_s("%d", &num) != EOF) {
        newrec = malloc(sizeof(struct Node));
        newrec->num = num;
        newrec->next = NULL;

        if (first == NULL) {
            first = newrec;
        }
        else {
            cur = first;
            while (cur != NULL) {
                if (newrec->num > cur->num) {
                    pre = cur;
                    cur = cur->next;
                }
                else {
                    break;
                }
            }
            if (cur == first) {
                first = newrec;
            }
            else {
                pre->next = newrec;
            }
            newrec->next = cur;
        }
    }
    cur = first;
    while (cur != NULL) {
        printf("%d ", cur->num);
        cur = cur->next;
    }

    mfree(first);
    
    return 0;
}