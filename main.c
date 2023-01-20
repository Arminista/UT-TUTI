#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
#include "user-operators.h"
#include "post-operators.h"
#define ONE 1
#define ZERO 0
#define TRUE 1
#define TWITT_MAX_SIZE 400



// For finding what do you want from UT TUTI
// int find_operator(char* user_choice)
// {
//     user_choice = (char*)calloc(10, sizeof(char));
//     char* signup = (char*)calloc(10, sizeof(char));
//     strcpy(signup, "signup");
//     char* login = (char*)calloc(10, sizeof(char));
//     strcpy(login, "login");
//     char* find_user = (char*)calloc(10, sizeof(char));
//     strcpy(find_user, "find_user");
//     char* info_user = (char*)calloc(10, sizeof(char));
//     strcpy(info_user, "info");
//     char* post_user = (char*)calloc(10, sizeof(char));
//     strcpy(post_user, "post");
//     char* like_user = (char*)calloc(10, sizeof(char));
//     strcpy(like_user, "like");
//     char* logout_user = (char*)calloc(10, sizeof(char));
//     strcpy(logout_user, "logout");
//     char* delete = (char*)calloc(10, sizeof(char));
//     strcpy(delete, "delete");
//     char* quit = (char*)calloc(10, sizeof(char));
//     strcpy(quit, "quit");

//     if(!strcmp(user_choice, signup)) return 1;
//     else if(!strcmp(user_choice, login)) return 2;
//     else if(!strcmp(user_choice, find_user)) return 3;
//     else if(!strcmp(user_choice, info_user)) return 4;
//     else if(!strcmp(user_choice, post_user)) return 5;
//     else if(!strcmp(user_choice, like_user)) return 6;
//     else if(!strcmp(user_choice, logout_user)) return 7;
//     else if(!strcmp(user_choice, delete)) return 8;
//     else if(!strcmp(user_choice, quit)) return 9;
//     else return 0;
// }

void freeBuff()
{
    char c;
    do
    {
        c = getchar();
    } while(c != '\n' && c != EOF);
}

int post_counter(char* username, POST* head)
{
    int counter = 0;
    POST* next = head->next_post;
    while(next != NULL)
    {
        if(!strcmp(next->owner, username)) counter++;
        next = next->next_post;
    }
    return counter;
}


int main()
{

    printf("--------------------------Welcome to UT TUTI--------------------------\n");
    
    //Creating dummy nodes and base parameters
    FILE* accounts;
    FILE* posts;
    POST* post_dummy_node = (POST*)malloc(sizeof(POST));
    USER* user_dummy_node = (USER*)malloc(sizeof(USER));
    USER* online_user = (USER*)malloc(sizeof(USER));
    online_user = NULL;
    char* all_str = (char*)calloc(450, sizeof(char));
    char* order = (char*)calloc(10, sizeof(char));
    char* username = (char*)calloc(20, sizeof(char));
    char* pass = (char*)calloc(20, sizeof(char));
    char* twitt = (char*)calloc(TWITT_MAX_SIZE, sizeof(char));
    post_dummy_node->next_post = NULL;
    user_dummy_node->next_user = NULL;
    int post_id;
    int operator_int;
    // char* signup = (char*)calloc(10, sizeof(char));
    // strcpy(signup, "signup");
    // char* login_user = (char*)calloc(10, sizeof(char));
    // strcpy(login_user, "login");
    // char* find_user = (char*)calloc(10, sizeof(char));
    // strcpy(find_user, "find_user");
    // char* info_user = (char*)calloc(10, sizeof(char));
    // strcpy(info_user, "info");
    // char* post_user = (char*)calloc(10, sizeof(char));
    // strcpy(post_user, "post");
    // char* like_user = (char*)calloc(10, sizeof(char));
    // strcpy(like_user, "like");
    // char* logout_user = (char*)calloc(10, sizeof(char));
    // strcpy(logout_user, "logout");
    // char* delete = (char*)calloc(10, sizeof(char));
    // strcpy(delete, "delete");
    // char* quit = (char*)calloc(10, sizeof(char));
    // strcpy(quit, "quit");

    while(TRUE)
    {

        // Get input from user
        gets(all_str);
        order = strtok(all_str, " ");
        // username = strtok(NULL, " ");
        // pass = strtok(NULL, " ");
        if(!strcmp("signup", order)) operator_int = 1;
        else if(!strcmp(order, "login")) operator_int = 2;
        else if(!strcmp(order, "find_user")) operator_int = 3;
        else if(!strcmp(order, "info")) operator_int = 4;
        else if(!strcmp(order, "post")) operator_int = 5;
        else if(!strcmp(order, "like")) operator_int = 6;
        else if(!strcmp(order, "logout")) operator_int = 7;
        else if(!strcmp(order, "delete")) operator_int = 8;
        else if(!strcmp(order, "quit")) operator_int = 9;
        else operator_int = 0;

        // After choosing
        if(operator_int == 9) break;
        switch(operator_int)
        {

            case 1: 
            {
                //Finding user and pass
                username = strtok(NULL, " ");
                pass = strtok(NULL, " ");
                if(!username)
                {
                    printf("Please enter correct value!\n");
                    break;
                }
                if(!pass)
                {
                    printf("Please enter correct value!\n");
                    break;
                }

                //Signing up
                int check_func = signup_user(username, pass, user_dummy_node);
            }

            case 2:
            {
                username = strtok(NULL, " ");
                pass = strtok(NULL, " ");
                if(!username)
                {
                    printf("Please enter correct value!\n");
                    break;
                }
                if(!pass)
                {
                    printf("Please enter correct value!\n");
                    break;
                }
                
                //Logging in
                online_user = login(username, pass, user_dummy_node);
                break;
            }

            case 3: 
            {
                USER* searched_user = (USER*)malloc(sizeof(USER));
                searched_user = NULL;
                if(!username)
                {
                    printf("Please enter correct value!\n");
                    break;
                }
                searched_user = search_user(username, user_dummy_node, post_dummy_node);
                break;
            }

            case 4:
            {
                if(online_user)
                {
                    info(online_user, post_dummy_node);
                }
                else printf("Please signup or login at first!\n");
                break;
            }

            case 5:
            {
                /*Codes for giving value to twitt*/
                if(online_user)
                {
                    
                    
                    post(twitt, post_dummy_node, (online_user->user_name));
                }
                else printf("Please login or signup at first!\n");
                break;
            }

            case 6:
            {
                /*Codes for finding user and post_id*/
                if(online_user) like(username, post_id, post_dummy_node);
                else printf("Please login or signup at first!\n");
                break;
            }

            case 7:
            {
                if(online_user) delete_post(post_id, username, post_dummy_node);
                else printf("Please login or signup at first!\n");
                break;
            }

            case 8:
            {
                //For giving value to post_id
                char* post_id_str = (char*)calloc(4 ,sizeof(char));
                post_id_str = strtok(NULL, " ");
                post_id = atoi(post_id_str);
                if(online_user) delete_post(post_id, (online_user->user_name), post_dummy_node);
                else printf("Please signup or login at first\n");
                free(post_id_str);
                break;
            }

            default:
            {
                printf("Please enter correct order:\n");
                break;
            }

        }
        free(all_str);
        free(username);
        free(pass);
        free(order);

    }

    //Save accounts
    POST* next_dummy_post = (POST*)malloc(sizeof(POST));
    next_dummy_post = post_dummy_node->next_post;
    USER* next_dummy_user = (USER*)malloc(sizeof(USER));
    next_dummy_user = user_dummy_node->next_user;
    accounts = fopen("accounts.txt", "w");
    while(next_dummy_user != NULL)
    {
        int all_posts = post_counter((next_dummy_user->user_name), post_dummy_node);
        fprintf(accounts, "%s %s %d\n", next_dummy_user->user_name, next_dummy_user->password, all_posts);
        next_dummy_user = next_dummy_user->next_user;
    }

    //Save posts
    posts = fopen("posts.txt", "w");
    while(next_dummy_post != NULL)
    {
        fprintf(posts, "%s %s %d\n", next_dummy_post->post, next_dummy_post->owner, next_dummy_post->like);
        next_dummy_post = next_dummy_post->next_post;
    }

    //Closing files
    fclose(accounts);
    fclose(posts);

    //Free memory after quit
    free(post_dummy_node);
    free(user_dummy_node);
    return 0;

}
