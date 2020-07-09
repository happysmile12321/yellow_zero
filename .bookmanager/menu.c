#include "menu.h"
#include <stdio.h>
#include "utils.h"


void menu_main()
{
	int choice;
	printf("************************************************\n");
	printf("***************BOOK MANAGER SYSTEM**************\n");
	printf("************************************************\n");
	printf("\n");
	printf("\t1.Add a book\n");
	printf("\t2.Delete a book\n");
	printf("\t3.Search Book\n");
	printf("\t4.Reload database\n");
	printf("\t5.Exit\n");
	printf("\tPlease input your choice.(1~5):");
	switch((choice = menu_choice(5)))
	{
		case 1:
			menu_add();
			break;
		case 2:
			menu_delete();
			break;
		case 3:
			menu_search();
			break;
		case 4:
			menu_reload();
			break;
		case 5:
			menu_exit();
			break;
		default:
			menu_error();
	}


}

static int menu_choice(const int max)
{
	int c=0;
	scanf("%d",&c);
	while(c < 1 || c > max)
	{
		printf("Please input num in (1~%d):",max);
		scanf("%d",&c);
	}
	return c;
}

static void menu_add()
{
	char name[LEN_BOOK_NAME]="\0";
	char author[LEN_BOOK_AUTHOR]="\0";
	char publisher[LEN_BOOK_PUBLISHER]="\0";
	int page;
	int year_p,month_p,day_p;
	int year_i,month_i,day_i;
	Timeinfor date_publish;
	Timeinfor date_input;
	printf("Please input book data:\n");
 	printf("Name:");
	scanf("%s",name);
	printf("Author:");
	scanf("%s",author);
	printf("Publisher:");
	scanf("%s",publisher);
	printf("page:");
	scanf("%d",&page);
	printf("publish time:");
	scanf("%d-%d-%d",&year_p,&month_p,&day_p);
	set_time_info(&date_publish, year_p, month_p, day_p);
	printf("input time:");
	scanf("%d-%d-%d",&year_i,&month_i,&day_i);
	set_time_info(&date_input, year_i,month_i,day_i);
	bookadd(name, author, publisher, page, &date_publish, &date_input);
	LOG_ACTIVITY("Success to add a book\n");	
	menu_main();
}
static menu_delete()
{
	int choice = 0;
	char tmp[LEN_BUFFER]={0};
	int year,month,day;
	Timeinfor tmp_time;
	printf(
		"\n"
		"\t1.Delete book by name\n"
		"\t2.Delete book by author\n"
		"\t3.Delete book by publisher\n"
		"\t4.Delete book published before a date\n"
		"\t5.Delete book imported before a date\n"
		"\t6.Go back.\n"
		"\nPlease select your choice(0~5):"
		);
	choice = menu_choice(6);
	switch()
	{
		case 1:
			printf("Input the name:");
			scanf("%s",tmp);
			book_delete_by_name(tmp);
			break;
		case 2:
			printf("Input the author:");
			scanf("%s",tmp);
			book_delete_by_author(tmp);
			break;
		case 3:
			printf("Input the publish:");
			scanf("%s",tmp);
			book_delete_by_pub(tmp);
			break;
		case 4:
			printf("Input the date(yyyy-mm-dd):");
			scanf("%d-%d-%d",&year,&month,&day);
			set_time_info(&tmp_time, year, month,  day);
			book_delete_by_pub_time(&tmp_time);
			break;
		case 5:
			printf("Input the date(yyyy-mm-dd):");
			scanf("%d-%d-%d",&year,&month,&day);
			set_time_info(&tmp_time, year, month,  day);
			book_delete_by_input_time(&tmp_time);
			break;
		case 6:
			menu_main();
			break;
		default:
			menu_error();

	}
	LOG_ACTIVITY("Success to delete books.");
	menu_delete();
}



int main(int argc, char *argv[])
{
	menu_add();		
	return 0;
}
