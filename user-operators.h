#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "structs.h"
#define ONE 1
#define ZERO 0
#define TRUE 1



//Signing up!
int signup_user(char* username, char* password, USER* head)
{
    USER* new_user = (USER*)calloc(ONE, sizeof(USER));
    if(!new_user) return 1;
    new_user->user_name = username;
    new_user->password = password;
    new_user->next_user = NULL;

    USER* next = head->next_user;
    
    int counter = 0;
    while(next)
    {
        if(!strcmp((next->user_name), username)) counter++;
        head = head->next_user;
        next = next->next_user;
    }
    

    if(counter != 0)
    {
        printf("Username is already taken!\n");
        return 0;
    }

    else
    {
        head->next_user = new_user;
        printf("User %s signed up successfuly\n", username);
        return 0;
    }
}

//Login function
USER* login(char* username, char* password, USER* head)
{
    USER* next = head->next_user;
    int counter = 0;
    while(next)
    {
        if(!strcmp((next->user_name), username))
        {
            counter++;
            if(!strcmp((next->password), password))
            {
                counter++;
                break;
            }
        }
        next = next->next_user;
    }
    switch(counter)
    {
        case 0:
            printf("User doesn't exist please enter correct username!\n");
            break;
        
        case 1:
            printf("Password is incorrect!\n");
            break;

        case 2:
        {
            printf("User %s logged in\n", username);
            return next;
            break;
        }
    }
}


//Searching user!
USER* search_user(char* username, USER* head, POST* post_head)
{
    USER* next = head->next_user;
    POST* next_head_post = post_head->next_post;

    int counter = 0;
    int post_counter = 0;
    while(next != NULL)
    {
        if(!strcmp(next->user_name, username))
        {
            printf("Owner: %s", username);
            counter++;
            while(next_head_post != NULL)
            {
                if(!strcmp(next_head_post->owner, username))
                {
                    post_counter++;
                    printf("Post: %s\npost_id: %d\nlike: %d\n------------\n", next_head_post->post, next_head_post->post_id, next_head_post->like);
                }
                next_head_post = next_head_post->next_post;
            }
            if(post_counter == 0) printf("This user don't have any posts!\n");
        }
        next = next->next_user;
    }


    if(counter == ZERO) 
    {
        printf("This user is not available!\n");
        return NULL;
    }
}

//User info
void info(USER* user, POST* post_head)
{
    POST* next_head_post = post_head->next_post;
    int post_counter;
    printf("Username: %s\nPassword: %s\n", user->user_name, user->password);

    while(next_head_post != NULL)
    {
        if(!strcmp((next_head_post->owner), (user->user_name)))
        {
            post_counter++;
            printf("Post: %s\npost_id: %d\nlike: %d\n------------------\n", next_head_post->post, next_head_post->post_id, next_head_post->like);
        }
        next_head_post = next_head_post->next_post;
    }
    if(post_counter == ZERO) printf("You don't have any posts!\n");
}


//Logout
int logout(USER* user, USER* head)
{
    USER* next = head->next_user;
    char* username = user->user_name;
    char* pass = user->password;
    user->user_name = "0";
    user->password = "0";
    while((next->user_name != "0") && (next->password != "0"))
    {
        next = next->next_user;
    }
    (next->next_user)->user_name = username;
    (next->next_user)->password = pass;
}
