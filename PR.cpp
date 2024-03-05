#include <stdio.h>
#include <stdlib.h>

struct Data {
    int age;
    struct Data *next; 
    struct data *prev;
};

struct data *head = NULL;
struct data *tail = NULL;

struct Data *create_node(int age) {
    struct Data *node = (struct Data*)malloc(sizeof(struct Data));
    node->next = NULL;
    node->prev = NULL;
    node->age = age;
    
    return node;
}

struct Data *push_mid(struct Data *head, int age){
	if (head == NULL) {
        return create_node(age); 
    }

    int count = 0;
    struct Data *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int middle = count / 2;

  
    temp = head;
    for (int i = 0; i < middle; i++) {
        temp = temp->next;
    }

    struct Data *new_node = create_node(age);

    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}

struct Data *pop_search(struct Data *head, int target_age) {
    struct Data *prev = NULL;
    struct Data *temp = head;
    
    while (temp != NULL) {
        if (temp->age == target_age) {
            if (prev == NULL) { 
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    
    return head;
}

void push_mid(int age){
    struct data *node = create_node(age);

    struct data *mid = head;
    struct data *ahead = head->next;

    while (ahead != NULL && ahead->next != NULL) {
        mid = mid->next;
        ahead = ahead->next->next;
    }

    node->prev = mid;
    node->next = mid->next;
    if (mid->next != NULL)
        mid->next->prev = node;
    mid->next = node;

    if (mid == tail)
        tail = node;
}

void pop_search(int age){
	struct data *temp = head;
    while (temp != NULL) {
        if (temp->age == age) {
            printf("Age %d found.\n", age);
            return;
        }
        temp = temp->next;
    }
}

void print_linked_list(struct Data *head) {
    struct Data *temp = head;
    int count = 1;
    while(temp != NULL) {
        printf("data ke-%d: %d\n", count, temp->age);
        temp = temp->next;
        count++;
    }
}

int main() {
    struct Data *head;
    head = create_node(10);
   
   	head = push_mid(head,3);

    push_mid(3);
    	
    head = pop_search(head, 3);
    
    pop_search(3);
    print_linked_list(head);

    return 0;
}

