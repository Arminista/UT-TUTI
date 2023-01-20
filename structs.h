#include <stdio.h>
#include <stdlib.h>

#ifndef USER_POST
#define USER_POST

typedef struct user_info USER;
typedef struct user_post POST;

struct user_info
{
    char* user_name;
    char* password;
    USER* next_user;
};

struct user_post
{
    char* owner;
    char* post;
    int like;
    int post_id;
    POST* next_post;
};

#endif