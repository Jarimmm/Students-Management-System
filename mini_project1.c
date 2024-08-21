/*
 * mini_project1.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mariam Samy
 */
#include<stdio.h>//contains printf and scanf functions
#include<stdlib.h>// contains malloc and free functions
#include<string.h>//contains string functions
#include<assert.h>

struct student{//declaration of new type of data names student
	int id;
	char name[50];
	int age;
	float gpa;
};

struct node{//declaration of the new type of data names node
	struct student data;
	struct node *next;
};

struct node *head = NULL ;//defining the head pointer



void addStudent(const struct student *const ptr){//defining a function that adds nodes
struct node *link= (struct node *)malloc(sizeof(struct node));
assert(link!=NULL);//testing whether there is enough space in heap for allocating a new node dynamically
struct node *current=head;//
    link->data.id=ptr->id;
    for(int i=0;i<50;i++)//adding member values for the new node
    link->data.name[i]=ptr->name[i];
    link->data.age=ptr->age;
    link->data.gpa=ptr->gpa;
    link->next=NULL;

if(head==NULL){//testing the special case if it is the first node inside the linked list
	head=link;
	return;
}
while(current->next!=NULL){//checking if the entered id is reserved
if(link->data.id==current->data.id){
	printf("\nThe student id you entered already exists in the system\n");
	free(link);
	return;
}
current=current->next;//my counter

}
//now our current pointer points to the last node
if(link->data.id==current->data.id){//checking on the last node in the linked list
	printf("\nThe student id you entered already exists in the system\n");
	free(link);
	return;
}

current->next=link;

}

void  displayStudents (void){//a function displays all the nodes in the linked list
	struct node *ptr=head;//a pointer for looping over the linked list
	if(head==NULL){//checking if the linked list is empty
		printf("\nNo student exist in the list, it is empty\n");
		return;
	}
	while(ptr!=NULL){//looping over the linked list with the help of a ptr pointer
		    printf("\nThe student id:%d",ptr->data.id);
			printf("\nThe student name:%s",ptr->data.name);
			printf("\nThe student age:%d",ptr->data.age);
			printf("\nThe student GPA:%f",ptr->data.gpa);
		    ptr=ptr->next;//my counter
	}
//now ptr pointer to Null
}
void searchStudentByID(int id){//a function search for a node "student" by the id
	struct node *ptr=head;//looping using ptr pointer
	while(ptr!=NULL){
		if(ptr->data.id==id){// in case we found the id, display all info
		    printf("\nThe student id:%d",ptr->data.id);
            printf("\nThe student name:%s",ptr->data.name);
		    printf("\nThe student age:%d",ptr->data.age);
			printf("\nThe student GPA:%f",ptr->data.gpa);
		    return;

	}
		ptr=ptr->next;
}
 printf("\nThe id you are searching for does not exist\n");
}

void updateStudent(int id){//a function that updates the info for a node"studet"
struct node *ptr=head;
while(ptr!=NULL){
	if(ptr->data.id==id){//in case we found the id, we get the new info

				printf("\nEnter new student name(without spaces, use underscores instead):");
				scanf(" %s",ptr->data.name);
				printf("\nEnter new student age:");
			    scanf(" %d",&ptr->data.age);
			    printf("\nEnter new student GPA:");
			    scanf(" %f",&ptr->data.gpa);
			    printf("\nThe student information updated successfully\n");
                return;
	}




                ptr=ptr->next;
}
printf("\nThe id you are searching for updating does not exist\n");
}

void deleteStudent(int id){//a function that deletes a node with the id given to it
	struct node *removednode =NULL;//a pointer for deleting
	struct node *ptr =head->next;//a pointer for looping
	struct node *pre =head;//a pointer behind-hand of ptr pointer by a node for linking this node with the new next node without losing it
	if(head->data.id==id){//checking for this special case if the id is found at the head
		removednode=head;
		head=head->next;
		free(removednode);
		printf("\nThe student with this id deleted successfully\n");
		return;
	}

	while(ptr!=NULL){
		if(ptr->data.id==id){
			pre->next=ptr->next;//linking prev node with the new next node without losing it
			removednode=ptr;
			free(removednode);
			printf("\nThe student with this id deleted successfully\n");
			return;
		}
		pre=ptr;//increasing the pointers counter
		ptr=ptr->next;


	}

	if(removednode==NULL){//checking if the removed-node initial value has not changed that means the id is not found
	printf("The student with this id does not exist, deletion is not executed\n");}
}

float calculateAverageGPA(void){// a function that calculates the average GPA
	struct node *ptr=head;
	float sum=0;//for getting the average correctly, or use casting with integer sum
	int count=0;
	float average;
	if(head==NULL){//if the linked list is empty average is 0

		return 0;
	}

	while(ptr!=NULL){
		sum+=ptr->data.gpa;
		count++;
		ptr=ptr->next;
	}

	average=sum/count;
	return average;
}

void searchHighestGPA(void){// a function that search for the student with highest GPA

	struct node *ptr=head;
	struct node * max=head;//a pointer to track the max GPA node

	if(head==NULL){
		printf("\nThe list is empty, no highest GPA\n");
		return;
	}

	while(ptr!=NULL){
		if(ptr->data.gpa>max->data.gpa){
			max=ptr;
		}



		ptr=ptr->next;
	}
    printf("\nThe student with the highest GPA information:");//printing all info about this max node
	printf("\nThe student id:%d",max->data.id);
	printf("\nThe student name:%s",max->data.name);
	printf("\nThe student age:%d",max->data.age);
	printf("\nThe student GPA:%f",max->data.gpa);
}



int main(void){//the start of my program
	    setvbuf(stdout, NULL, _IONBF, 0);//for fixing scanf and printf issue
		setvbuf(stderr, NULL, _IONBF, 0);
	struct student S;
     int choice;

    while(1){
    	printf("\n--------------------------------------------------------------------\n");
    	printf("1.Add student\n2.Display students\n3.search student by ID\n4.Update student information\n5.Delete student\n6.Calculate average GPA\n7.Search for the student with the highest GPA\n8.Exit\n ");
    	printf("Enter your choice:");
    	    scanf("%d",&choice);
    	    printf("\n--------------------------------------------------------------------");
    switch(choice){
    case 1:
    printf("\nEnter student id:");
	scanf("%d",&S.id);
	printf("\nEnter student name(without spaces, use underscores instead):");
	scanf("%s",S.name);//if the name contains a space in  it scanf will cause a troublesome
	printf("\nEnter student age:");
    scanf(" %d",&S.age);//no parentheses are needed and the dot operator has higher precedence over the address operator
    printf("\nEnter student GPA:");
    scanf(" %f",&S.gpa);
     addStudent(&S);//calling the function add, struct student is passed to it by reference(address)
    	break;

    case 2:
    	 displayStudents();
    	 break;

    case 3:
    	int id;
    	printf("\nEnter the student id you are searching for:");
        scanf("%d",&id);
         searchStudentByID(id);//calling the function  search
    	 break;

    case 4:
    	printf("\nEnter the student id you want to update:");
    	scanf("%d",&id);
    	 updateStudent(id);//calling the function update
    	 break;

    case 5:
    	if(head==NULL){//checking if the linked list is empty
    			printf("\nNothing exist to delete, an empty list\n");
    			continue;
    	}
    	printf("\nEnter the student id you want to delete:");
        scanf("%d",&id);
    	deleteStudent(id);//calling the function delete
         break;
    case 6:
    	printf("\nThe average of all students=%f",calculateAverageGPA());
        break;

    case 7:
    	searchHighestGPA();//calling the function for highest GPA
    	break;

    case 8:
    	printf("\nExit...");
        return 0;

    }}

        return 0;
}//end of my program
