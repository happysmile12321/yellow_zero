#define LEN_BOOK_NAME 100
#define LEN_BOOK_AUTHOR 100
#define LEN_BOOK_PUBLISHER 100
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



