#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

struct ll{
    int size;
    struct node *head;
};

//insertes by index
void insert_node(int ind, int val, struct ll *list){
    list->size++;
    struct node * cn = list->head;
    for (int i = 0; i < ind; i++){
        cn = cn->next;
    }
    
    struct node *ti = malloc(sizeof(struct node));
    ti->val = val;
    ti->next = cn->next;
    cn->next = ti;
}

//deletes by index
void delete_node(int ind, struct ll * list){
    list->size--;
    struct node * cn = list->head;
    for (int i = 0; i < ind; i++){
        cn = cn->next;
    }
    struct node *td = cn->next;
    cn->next = cn->next->next;
    free(td);
}

//prints the given list
void print_list(struct ll *list){
    struct node * cn = list->head;
    for(int i = 0; i < list->size; i++){
        cn = cn->next;
        printf("%d ", cn->val);
    }
}

int main(){
    struct node head;
    struct ll list = {.size = 0, .head = &head};
    for(int i = 0; i < 10; i++){
        insert_node(i/2, i, &list);
        print_list(&list);
        printf("\n");
    }
    for(int i = 9; i >= 0; i--){
        delete_node(i/2, &list);
        print_list(&list);
        printf("\n");
    }
	
	return 0;
}
