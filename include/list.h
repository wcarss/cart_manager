#ifndef _wlist
#define _wlist

typedef struct _list list;
typedef struct _list * List;

typedef struct _node node;
typedef struct _node * Node;

#define str_size 256
struct _node
{
  struct _node *next;
  struct _node *prev;
  void *v;
  int n;
  int id;
  char str[str_size];
  int (*free)(void *);
};

struct _list
{
  struct node *root;
  struct node *current;
  int size;
  int id;
  char name[str_size];
};

#endif
