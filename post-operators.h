#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#define ONE 1
#define ZERO 0
#define TRUE 1


//Post
void post(char* post, POST* head, char* username)
{
    POST* next_head_post = head->next_post;

    int counter = 0;
    while(next_head_post)
    {
        if(!strcmp(next_head_post->owner, username)) counter++;
        head = head->next_post;
        next_head_post = next_head_post->next_post;
    }
    next_head_post = (POST*)calloc(ONE, sizeof(POST));
    next_head_post->post_id = ++counter;
    strcpy(next_head_post->owner, username);
    strcpy(next_head_post->post, post);
    next_head_post->next_post = NULL;
    head->next_post = next_head_post;
}

//Deleting post
void delete_post(int post_id, char* username, POST* head)
{
    POST* current = head->next_post;
    POST* prev = head;
    POST* next = current->next_post;

    int counter;
    while(current != NULL)
    {
        if(!strcmp(current->owner, username) && ((current->post_id) == post_id))
        {
            counter++;
            prev = next;
            current = NULL;
            break;
        }
        prev = current;
        current = next;
        next = next->next_post;
    }
    if(counter == 0) printf("The post that you want is not available\n");
}


//Like posts
int like(char* username, int post_id, POST* head)
{
    int counter;
    POST* next_head_post = head->next_post;

    while(next_head_post != NULL)
    {
        if(!strcmp(next_head_post->owner, username))
        {
            counter++;
            if(next_head_post->post_id == post_id)
            {
                (next_head_post->like)++;
                counter++;
            }
        }
        next_head_post = next_head_post->next_post;
    }
    
    switch(counter)
    {
        case 0:
            printf("This user is not available!\n");
            break;
        case 1:
            printf("This post is not available from %s user\n", username);
            break;
    }
}


