#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN_BOOK_NAME 100
#define LEN_BOOK_AUTHOR 100
#define LEN_BOOK_PUBLISHER 100
#define LEN_BUFFER 100
typedef struct{
	unsigned year : 16;
	unsigned month : 8;
	unsigned day : 8;
}Timeinfor;

typedef struct {
	char name[LEN_BOOK_NAME];
	char author[LEN_BOOK_AUTHOR];
	char publisher[LEN_BOOK_PUBLISHER];
	int serial;
	int page;

}BookInfo;
void set_time_info(Timeinfor *T,int year,int month,int day);
void bookadd(char* name,char* author,char* publisher,int page,Timeinfor* date_publish,Timeinfor* date_input);
//book delete 
void book_delete_by_name(char* name);
void book_delete_by_author(char* author);
void book_delete_by_pub(char* pub);
void book_delete_by_pub_time(Timeinfor *t);
void book_delete_by_input_time(Timeinfor *t);
