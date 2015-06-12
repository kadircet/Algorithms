#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0

struct _follows
{
	struct _user *usr;
	
	struct _follows *next, *prev;
};

struct _message
{
	unsigned long id;
	
	struct _user *auth;
	struct _message *next, *prev;
};

struct _user
{
	unsigned long id;
	int active;
	char *name;
	
	struct _user *next, *prev;
	struct _follows *head;
	struct _message *msgs;
};

typedef struct _user user;
typedef struct _message message;
typedef struct _follows follows;

void printF(user *usr)
{
	follows *cur = usr->head;
	if(usr->head==NULL)
		return;
	
	do
	{
		printf("%s follows %s\n", cur->usr->name, usr->name);
		cur = cur->next;
	}
	while(cur!=usr->head);
}

void init(char *name, user **root)
{
	user *head;
	
	head = (user*)malloc(sizeof(user));
	head->next = head->prev = head;
	head->head = NULL;
	head->msgs = NULL;
	head->name = name;
	head->active = 1;
	head->id = 1;
	*root = head;
	
	if(DEBUG)
		printf("Initiated with: %lu - %s\n", head->id, head->name);
}

void addUser(char *name, user *head)
{
	user *root = head;
		
	head = head->prev;
	head->next = (user*)malloc(sizeof(user));
	head->next->prev = head;
	head->next->id = head->id+1;
	head = head->next;
	head->name = name;
	head->active = 1;
	head->head = NULL;
	head->msgs = NULL;
	head->next = root;
	root->prev = head;
	
	if(DEBUG)
		printf("User Added: %lu - %s\n", head->id, head->name);
}

user* getUserId(int id, user *head)
{
	while(id!=head->id)
		head = head->next;
	
	return head;
}

user* getUserName(char *name, user *head)
{
	while(strcmp(name, head->name))
		head = head->next;
	
	return head;
}

void follow(char *name1, char *name2, user *head)
{
	user *usr = getUserName(name2, head);
	user *usr2 = getUserName(name1, head);
	follows *root = usr->head;
	follows *cur;
	
	if(usr->head==NULL)
	{
		usr->head = (follows*)malloc(sizeof(follows));
		usr->head->usr = usr2;
		usr->head->next = usr->head->prev = usr->head;
		
		if(DEBUG)
			printf("Followers for %s initiated with %s\n", usr->name, usr2->name);
		return;
	}
	
	cur=usr->head->prev;
	cur->next = (follows*)malloc(sizeof(follows));
	cur->next->prev = cur;
	cur = cur->next;
	cur->next = root;
	cur->usr = usr2;
	root->prev = cur;
	
	if(DEBUG)
		printf("%s added to followers of %s\n", usr2->name, usr->name);
		
	if(DEBUG)
		printF(usr);
}

void addMsg(user *usr, message msg)
{
	message *root = usr->msgs;
	message *cur, *fwd;	
	
	if(usr->active==0)
		return;
	
	if(usr->msgs==NULL)
	{
		usr->msgs = (message*)malloc(sizeof(message));
		usr->msgs->id = msg.id;
		usr->msgs->auth = msg.auth;
		usr->msgs->next = usr->msgs->prev = usr->msgs;
		if(DEBUG)
			printf("Initialized msg pool for %s\n", usr->name);
		
		return;
	}
	
	cur = usr->msgs->prev;
	while(cur->id > msg.id)
	{
		cur = cur->prev;
		if(cur==usr->msgs->prev)
			break;
	}
	
	cur = cur->next;

	fwd = cur->prev;
	cur->prev = (message*)malloc(sizeof(message));
	cur->prev->next = cur;
	cur = cur->prev;
	cur->id = msg.id;
	cur->auth = msg.auth;
	cur->prev = fwd;
	fwd->next = cur;
	if(cur->id < usr->msgs->id)
		usr->msgs = cur;
			
	if(DEBUG)
		printf("Added message %lu -> %s\n", msg.id, usr->name);
}

void sendMsg(char *name, unsigned long id, user *head)
{
	message *msg = (message*)malloc(sizeof(message));
	user *sender = getUserName(name, head);
	follows *cur = sender->head;
	
	msg->auth = sender;
	msg->id = id;
	
	if(DEBUG)
		printf("User: %s sending message %ld\n", sender->name, msg->id);
	
	addMsg(sender, *msg);
	if(cur==NULL)
		return;

	do
	{
		addMsg(cur->usr, *msg);
		cur = cur->next;
	}
	while(cur!=sender->head);
}

void resendMsg(char *name, int k, user *head)
{
	int i;
	message msg;
	user *sender = getUserName(name, head);
	follows *cur = sender->head;
	message *curm = sender->msgs;
	
	for(i=0;i<k;i++)
		curm = curm->prev;
	
	msg.id = curm->id;
	msg.auth = sender;
	
	addMsg(sender, msg);
	if(cur==NULL)
		return;
		
	do
	{
		addMsg(cur->usr, msg);
		cur = cur->next;
	}
	while(cur!=sender->head);
}

void inactivate(char *name, user *head)
{
	user *usr = getUserName(name, head);
	usr->active = 0;
}

void activate(char *name, user *head)
{
	user *usr = getUserName(name, head);
	usr->active = 1;
}

#define unlink(cur, fwd, bck)	\
{								\
	bck->next = fwd;			\
	fwd->prev = bck;			\
	free(cur);					\
}

void unfollow(char *name1, char *name2, user *head)
{
	user *usr1 = getUserName(name1, head);
	user *usr2 = getUserName(name2, head);
	message *curm, *fwdm, *bckm;
	follows *fwd, *bck;
	int toDel=0, del=0;
	
	follows *cur = usr2->head;
	while(cur->usr != usr1)
		cur = cur->next;
		
	if(DEBUG)
		printf("%s unfollowed %s\n", usr1->name, usr2->name);
	
	if(cur->next == cur)
	{
		free(usr2->head);
		usr2->head = NULL;
	}
	else
	{
		fwd = cur->next;
		bck = cur->prev;
		if(cur == usr2->head)
			usr2->head = fwd;
		unlink(cur, fwd, bck);
	}
	
	if(DEBUG)
		printF(usr2);
	
	curm = usr1->msgs;
	if(curm==NULL)
		return;
	do
	{
		toDel+=curm->auth==usr2;
		curm = curm->next;
	}
	while(curm!=usr1->msgs);
	
	do
	{
		if(curm->auth == usr2)
		{
			if(DEBUG)
				printf("Msg %lu deleted from %s\n", curm->id, usr1->name);
			if(curm==usr1->msgs)
			{
				if(curm->next==curm)
				{
					free(curm);
					usr1->msgs=NULL;
					break;
				}
				usr1->msgs = usr1->msgs->next;
			}
				
			fwdm = curm->next;
			bckm = curm->prev;
			unlink(curm, fwdm, bckm);
			del++;

			curm = fwdm;
			continue;
		}
		curm = curm->next;
	}
	while(del<toDel);
}

void print(user usr)
{
	printf("%lu:", usr.id);
	
	if(usr.msgs==NULL)
	{
		puts("");
		return;
	}
	
	message *curm = usr.msgs->prev;
	do
	{
		printf(" %lu", curm->id);
		curm = curm->prev;
	}
	while(curm != usr.msgs->prev);
	
	puts("");
}

char *getUser()
{
	int len=2, cur=0;
	char *buf = (char*)malloc(sizeof(char)*len);
	while((buf[cur]=getchar())==' ');
	cur++;
	while((buf[cur]=getchar())!=' ' && buf[cur]!='\n')
	{
		cur++;
		if(cur>=len)
		{
			len *= 2;
			buf = (char*)realloc(buf, sizeof(char)*len);
		}
	}
	buf[cur] = 0;
	
	if(DEBUG)
		printf("Name read: %d - %s\n", len, buf);
	
	return buf;
}

int main()
{
	unsigned long nMsg = 0;
	char *cmnd, *uname1, *uname2;
	int k;
	user *users = NULL;
	
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cmnd = (char*)malloc(sizeof(char)*10);
	while(scanf("%s", cmnd)!=EOF)
	{
		if(DEBUG)
			printf("cmnd read: %s\n", cmnd);
			
		if(!strcmp(cmnd, "ADD"))
		{
			uname1 = getUser();
			if(users==NULL)
				init(uname1, &users);
			else
				addUser(uname1, users);
		}
		else if(!strcmp(cmnd, "FOLLOW"))
		{
			uname1 = getUser(), uname2 = getUser();
			follow(uname1, uname2, users);
		}
		else if(!strcmp(cmnd, "SEND"))
		{
			uname1 = getUser();
			sendMsg(uname1, ++nMsg, users);
		}
		else if(!strcmp(cmnd, "RESEND"))
		{
			uname1 = getUser();
			scanf("%d", &k);
			resendMsg(uname1, k, users);
		}
		else if(!strcmp(cmnd, "INACTIVE"))
		{
			uname1 = getUser();
			inactivate(uname1, users);
		}
		else if(!strcmp(cmnd, "ACTIVE"))
		{
			uname1 = getUser();
			activate(uname1, users);
		}
		else //UNFOLLOW
		{
			uname1 = getUser(), uname2 = getUser();
			unfollow(uname1, uname2, users);
		}
	}
	
	user *cur = users;
	do
	{
		print(*cur);
		cur = cur->next;
	}
	while(cur!=users);
	
	return 0;
}

