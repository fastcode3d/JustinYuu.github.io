---
layout: post
title: "CPP Programming Assignment Chapter17"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/04/11/
---
# CPP Programming Assignment Chapter17


	{% highlight ruby %}
	17.1.c
    #include <stdio.h>
    #include <stdlib.h>      /* has the malloc prototype      */
    #include <string.h>      /* has the strcpy prototype      */
    #define TSIZE    45      /* size of array to hold title   */

    struct film {
        char title[TSIZE];
        int rating;
        struct film * next;  /* points to next struct in list */
        struct film * prev;
    };
    char * s_gets(char * st, int n);
    int main(void)
    {
        struct film * head = NULL;
        struct film * prev, * current;
        char input[TSIZE];

        /* Gather  and store information          */
        puts("Enter first movie title:");
        while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
        {
            current = (struct film *) malloc(sizeof(struct film));
            if (head == NULL)       /* first structure       */
                {
                    head = current;
                    head->prev = NULL;
                }
            else                    /* subsequent structures */
                {
                    prev->next = current;
                    current->prev = prev;
                }
            current->next = NULL;
            strcpy(current->title, input);
            puts("Enter your rating <0-10>:");
            scanf("%d", &current->rating);
            while(getchar() != '\n')
                continue;
            puts("Enter next movie title (empty line to stop):");
            prev = current;
        }
        /* Show list of movies                    */
        if (head == NULL)
            printf("No data entered. ");
        else
            printf ("Here is the movie list:\n");
        current = head;
        while (current != NULL)
        {
            printf("Movie: %s  Rating: %d\n",
                   current->title, current->rating);
            prev = current;
            current = current->next;
        }

        if (head != NULL)
        {
            printf("\n Here is the movie list in reverse order:\n");
            current = prev;
            while (current != NULL)
            {
            printf("Movie: %s  Rating: %d\n",
                   current->title, current->rating);
            current = current->prev;
            }
        }
        printf("Bye!\n");

        return 0;
    }

    char * s_gets(char * st, int n)
    {
        char * ret_val;
        char * find;

        ret_val = fgets(st, n, stdin);
        if (ret_val)
        {
            find = strchr(st, '\n');   // look for newline
            if (find)                  // if the address is not NULL,
                *find = '\0';          // place a null character there
            else
                while (getchar() != '\n')
                    continue;          // dispose of rest of line
        }
        return ret_val;
    }

	{% endhighlight %}
	
---

	{% highlight ruby %}
	17.2.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "list_17_3.h"


    static void CopyToNode(Item item, Node * pnode);

    void InitializeList(List * plist)
    {
        plist->head = NULL;
        plist->end = NULL;
    }

    bool ListIsEmpty(const List * plist)
    {
        if (plist->head == NULL)
            return true;
        else
            return false;
    }

    bool ListIsFull(const List * plist)
    {
        Node * pt;
        bool full;

        pt = (Node *)malloc(sizeof(Node));
        if (pt == NULL)
            full = true;
        else
            full = false;
        free(pt);
        return full;
    }

    unsigned int ListItemCount(const List * plist)
    {
        unsigned int count = 0;
        Node * pnode = plist->head;

        while (pnode != NULL)
        {
            ++count;
            pnode = pnode->next;
        }

        return count;
    }

    bool AddItem(Item item, List * plist)
    {
        Node * pnew;
        Node * scan = plist->head;

        pnew = (Node *)malloc(sizeof(Node));
        if (pnew == NULL)
            return false;

        CopyToNode(item, pnew);
        pnew->next = NULL;
        if (scan == NULL)
            plist->head = pnew;
        else
            plist->end->next = pnew;
        plist->end = pnew;
        return true;
    }

    void Traverse(const List * plist, void(*pfun)(Item item))
    {
        Node * pnode = plist->head;
        while (pnode != NULL)
        {
            (*pfun)(pnode->item);
            pnode = pnode->next;
        }
    }

    void EmptyTheList(List * plist)
    {
        Node * psave;
        while (plist->head != NULL)
        {
            psave = plist->head->next;
            free(plist->head);
            plist->head = psave;
        }
    }

    static void CopyToNode(Item item, Node * pnode)
    {
        pnode->item = item;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	17.3.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "list_17_3.h"


    static void CopyToNode(Item item, Item * pnode);

    void InitializeList(List * plist)
    {
        plist->items = 0;
    }

    bool ListIsEmpty(const List * plist)
    {
        if (plist->items == 0)
            return true;
        else
            return false;
    }

    bool ListIsFull(const List * plist)
    {
        if (plist->items < MAXSIZE)
            return false;
        else
            return true;
    }

    unsigned int ListItemCount(const List * plist)
    {
        return plist->items;
    }

    bool AddItem(Item item, List * plist)
    {
        int i = plist->items;
        if (i < MAXSIZE)
        {
            CopyToNode(item, &plist->entries[i]);
            plist->items++;
            return true;
        }

        return false;
    }

    void Traverse(const List * plist, void(*pfun)(Item item))
    {
        int i;
        for (i = 0; i < plist->items; i++)
            (*pfun)(plist->entries[i]);
    }

    void EmptyTheList(List * plist)
    {
        plist->items = 0;
    }

    static void CopyToNode(Item item, Node * pnode)
    {
        pnode->item = item;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	17.4.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "queue.h"
    #define MIN_PER_HR 60.0

    bool newcustomer(double x);
    Item customertime(long when);

    int main(void)
    {
        Queue line1, line2;
        Item temp;
        int hours;
        int perhour;
        long cycle, cyclelimit;
        long turnaways = 0;
        long customers = 0;
        long served1 = 0, served2 = 0;
        long sum_line1 = 0, sum_line2 = 0;
        int wait_time1 = 0, wait_time2 = 0;
        double min_per_cust;
        long line_wait1 = 0, line_wait2 = 0;

        InitQueue(&line1);
        InitQueue(&line2);

        srand((unsigned)time(NULL));

        puts("Case Study: Sigmund Lander's Advice Booth");
        puts("Enter the number of simulation hours:");
        scanf("%d", &hours);
        cyclelimit = MIN_PER_HR * hours;

        puts("Enter the average number of customers per hour: ");
        scanf("%d", &perhour);
        min_per_cust = perhour / MIN_PER_HR;
        printf("%.2lf\n", min_per_cust);
        int i = 0;
        for (cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                i++;
                if (QueueIsFull(&line1) && QueueIsFull(&line2))
                    turnaways++;
                else
                {
                    customers++;
                    temp = customertime(cycle);
                    if (QueueItemCount(&line1) < QueueItemCount(&line2))
                        EnQueue(temp, &line1);
                    else
                        EnQueue(temp, &line2);
                }
            }
            if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
            {
                DeQueue(&temp, &line1);
                wait_time1 = temp.processtime;
                line_wait1 += cycle - temp.arrive;
                served1++;
            }
            if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
            {
                DeQueue(&temp, &line2);
                wait_time2 = temp.processtime;
                line_wait2 += cycle - temp.arrive;
                served2++;
            }
            if (wait_time1 > 0) wait_time1--;
            if (wait_time2 > 0)   wait_time2--;
            sum_line1 += QueueItemCount(&line1);
            sum_line2 += QueueItemCount(&line1);
        }
        if (customers > 0)
        {
            printf("customers accepted: %ld\n", customers);
            printf("   customers served: %ld\n", served1 + served2);
            printf("         turn aways: %ld\n", turnaways);
            printf("average queue size: %.2f\n", (double)(sum_line1 + sum_line2) / cyclelimit);
            printf("average wait time: %.2f minutes\n", (double)(line_wait1 + line_wait2) / (served1 + served2));
        }
        else
            puts("No customers!");

        printf("i = %d\n", i);
        return 0;
    }

    bool newcustomer(double x)
    {
        if (rand()*x / RAND_MAX < 1)
            return true;
        else
            return false;
    }

    Item customertime(long when)
    {
        Item cust;

        cust.processtime = rand() % 3 + 1;
        cust.arrive = when;

        return cust;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	17.5.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "17.5.h"

    static void CopyToNode(Item item, Node * pn);
    static void CopyToItem(Node * pn, Item * pi);

    void InitStack(Stack * ps)
    {
        ps->bottom = ps->top = NULL;
    }
    bool StackIsFull(const Stack * ps)
    {
        Node * temp;
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
            return true;
        else
            free(temp);
        return false;
    }
    bool StackIsEmpty(const Stack * ps)
    {
        return ps->top == NULL;
    }
    bool push(Item item, Stack * ps)
    {
        Node * pnew;

        if (StackIsFull(ps))
            return false;
        pnew = (Node *)malloc(sizeof(Node));
        if (pnew == NULL)
        {
            fprintf(stderr, "Unable to allocate memory!\n");
            exit(1);
        }
        CopyToNode(item, pnew);
        if (StackIsEmpty(ps))
        {
            pnew->next = NULL;
            ps->bottom = pnew;
        }
        else
            pnew->next = ps->top;
        ps->top = pnew;

        return true;
    }
    bool Pop(Item * pitem, Stack * ps)
    {
        Node * pt;

        if (StackIsEmpty(ps))
            return false;
        CopyToItem(ps->top, pitem);
        pt = ps->top;
        ps->top = ps->top->next;
        free(pt);
        if (ps->top == NULL)
            ps->bottom = NULL;
        return true;
    }
    static void CopyToNode(Item item, Node * pn)
    {
        pn->item = item;
    }
    static void CopyToItem(Node * pn, Item * pi)
    {
        *pi = pn->item;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	17.5.h
    #ifndef _STACK_H_
    #define _STACK_H_
    #include <stdbool.h>

    typedef char Item;

    typedef struct node
    {
        Item item;
        struct node * next;
    } Node;

    typedef struct stack{
        Node * top;
        Node * bottom;
    }Stack;

    void InitStack(Stack * ps);
    bool StackIsFull(const Stack * ps);
    bool StackIsEmpty(const Stack * ps);
    int StackItemCount(const Stack * ps);
    bool push(Item item, Stack * ps);
    bool Pop(Item * pitem, Stack * ps);

    #endif
	{% endhighlight %}
	
---

	{% highlight ruby %}
	17.6.c
    #include <stdio.h>

    int search(int table[], int max, int number);

    #define M 10

    int main(void)
    {
        int i ;
        int table[M] = { 1, 3, 5, 6, 9, 13, 19, 21, 34, 45 };
        printf("Hello!\n");
        for (i = 0; i<100; i++)
        if (search(table, M-1, i))
            printf("%d ", i);
        printf("\n");
        return 0;
    }

    int search(int table[], int max, int number)
    {
        int min = 0, half;
        int i = 0;
        while (1)
        {
            i++;
            half = (min + max) / 2;
            if (number > table[half])
            {
                min = half + 1;
            }
            else
            {
                if (number < table[half])
                    max = half - 1;
                else
                    return 1;
            }

            if (min + 1 == max)
            {
                if (number == table[min] || number == table[max])
                    return 1;
                else
                    return 0;
            }
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	17.8.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "17.8.h"

    typedef struct pair
    {
        Node * parent;
        Node * child;
    }Pair;

    static bool AddListItem(const Item * pi, Node * root);
    static List * MakeListNode(const Item * pi);
    static Node * MakeTreeNode(const Item * pi);
    static void AddTreeNode(Node * new_node, Node * root);
    static Pair SeekItem(const Item * pi, const Tree * ptree);
    static bool ToLeft(const Item * i1, const Item * i2);
    static bool ToRight(const Item * i1, const Item * i2);
    static bool SeekListItem(const Item * pi, List * pl);
    static void DeNode(const Item * pi, Node ** ptr);
    static List * DeListNode(const Item * pi, List * pl);
    static void InOrder(const Node * root, void(*pfun)(List * list));
    static void DeleteAllNodes(Node * root);
    static void DeList(List * list);
    static void DeleteAllList(Node * root);


    static bool AddListItem(const Item * pi, Node * root)
    {
        List * new_listnode, *temp = root->list;
        new_listnode = MakeListNode(pi);
        if (new_listnode == NULL)
        {
            fprintf(stderr, "New member generated failure!\n");
            return false;
        }
        while (NULL != temp->next)
            temp = temp->next;
        temp->next = new_listnode;
        root->list_size++;
        return true;
    }
    static List * MakeListNode(const Item* pi)
    {
        List * new_list;
        new_list = (List *)malloc(sizeof(List));
        if (new_list != NULL)
        {
            new_list->item = *pi;
            new_list->next = NULL;
        }
        return new_list;
    }
    static Node * MakeTreeNode(const Item * pi)
    {
        Node * new_node;
        List * new_list_node;

        new_list_node = MakeListNode(pi);
        if (new_list_node == NULL)
            return NULL;
        new_node = (Node *)malloc(sizeof(Node));
        if (new_node != NULL)
        {
            new_node->list = new_list_node;
            new_node->list_size = 1;
            new_node->left = NULL;
            new_node->right = NULL;
        }
        return new_node;
    }
    static void AddTreeNode(Node * new_node, Node * root)
    {
        if (ToLeft(&new_node->list->item, &root->list->item))
        {
            if (NULL == root->left)
                root->left = new_node;
        }
        else if (ToRight(&new_node->list->item, &root->list->item))
        {
            if (NULL == root->right)
                root->right = new_node;
        }

    }
    static bool ToLeft(const Item * i1, const Item * i2)
    {
        if (strcmp(i1->petname, i2->petname) < 0)
            return true;
        return false;
    }
    static bool ToRight(const Item * i1, const Item * i2)
    {
        if (strcmp(i1->petname, i2->petname) > 0)
            return true;
        return false;
    }
    static bool SeekListItem(const Item * pi, List * pl)
    {
        List * temp = pl;
        while (NULL != temp)
        {
            if (strcmp(pi->petkind, temp->item.petkind) == 0)
                return true;
            temp = temp->next;
        }

        return false;
    }
    static Pair SeekItem(const Item * pi, const Tree * ptree)
    {
        Pair look;
        look.parent = NULL;
        look.child = ptree->root;

        if (NULL == look.child)
            return look;
        while (NULL != look.child)
        {
            if (ToLeft(pi, &look.child->list->item))
            {
                look.parent = look.child;
                look.child = look.child->left;
            }
            else if (ToRight(pi, &look.child->list->item))
            {
                look.parent = look.child;
                look.child = look.child->right;
            }
            else
            {
                break;
            }

        }
        return look;
    }
    static void DeNode(const Item * pi, Node ** ptr)
    {
        Node * temp;
        if (1 == (*ptr)->list_size)
        {
            if (NULL == (*ptr)->left)
            {
                temp = *ptr;
                *ptr = (*ptr)->right;
                free(temp);
            }
            else if (NULL == (*ptr)->right)
            {
                temp = *ptr;
                *ptr = (*ptr)->left;
                free(temp);
            }
            else
            {
                temp = (*ptr)->left;
                while (NULL != temp->right)
                    temp = temp->right;
                temp->right = (*ptr)->right;
                temp = *ptr;
                *ptr = (*ptr)->left;
                free(temp);
            }
        }
        else if ((*ptr)->list_size > 1)
        {
            (*ptr)->list = DeListNode(pi, (*ptr)->list);
            (*ptr)->list_size--;
        }
    }
    static List * DeListNode(const Item * pi, List * pl)
    {
        List * phead = pl;
        List * temp;
        if (strcmp(pi->petkind, phead->item.petkind) == 0)
        {
            phead = pl->next;
            free(pl);
        }
        else
        {
            do
            {
                temp = pl;
                pl = pl->next;
            } while (strcmp(pi->petkind, pl->item.petkind) != 0);

            temp->next = pl->next;
            free(pl);
        }
        return phead;
    }
    static void InOrder(const Node * root, void(*pfun)(List * list))
    {
        if (root != NULL)
        {
            InOrder(root->left, pfun);
            (*pfun)(root->list);
            InOrder(root->right, pfun);
        }
    }
    static void DeleteAllNodes(Node * root)
    {
        Node * temp = root;

        if (root != NULL)
        {
            temp = root->right;
            DeleteAllNodes(root->left);
            DeList(root->list);
            free(root);
            DeleteAllNodes(temp);
        }
    }
    static void DeList(List * list)
    {
        List * temp;

        while (list != NULL)
        {
            temp = list;
            list = list->next;
            free(temp);
        }

    }


    void InitTree(Tree * ptree)
    {
        ptree->root = NULL;
        ptree->size = 0;
    }
    bool TreeIsEmpty(const Tree * ptree)
    {
        return ptree->root == NULL;
    }
    bool TreeIsFull(const Tree * ptree)
    {
        return ptree->size >= TREEMAX;
    }
    int TreeItemCount(const Tree * ptree)
    {
        return ptree->size;
    }
    bool InTree(const Item * pi, const Tree * ptree)
    {
        Pair look = SeekItem(pi, ptree);
        return look.child != NULL && SeekListItem(pi, look.child->list);
    }
    bool AddTreeItem(const Item * pi, Tree * ptree)
    {
        Node * new_node;
        Pair seek;

        if (TreeIsFull(ptree))
        {
            fprintf(stderr, "Tree is ull\n");
            return false;
        }
        seek = SeekItem(pi, ptree);
        if (seek.child != NULL)
        {
            if (AddListItem(pi, seek.child));
            return true;
            return false;
        }
        new_node = MakeTreeNode(pi);
        if (new_node == NULL)
        {
            fprintf(stderr, "Couldn't create node\n");
            return false;
        }
        if (ptree->root == NULL)
            ptree->root = new_node;
        else
            AddTreeNode(new_node, ptree->root);
        ptree->size++;

        return true;
    }
    bool DeleteItem(const Item * pi, Tree * ptree)
    {
        Pair look;
        look = SeekItem(pi, ptree);
        int i = TreeItemCount(ptree);
        if (NULL == look.child)
            return false;
        if (!SeekListItem(pi, look.child->list))
            return false;
        DeNode(pi, &look.child);
        int j = TreeItemCount(ptree);
        if (i == j)
            ptree->size--;
        if (ptree->size == 0)
            ptree->root = NULL;

        return true;
    }
    void Traverse(const Tree * ptree, void(*pfun)(List * list))
    {
        if (ptree->root != NULL)
            InOrder(ptree->root, pfun);
    }
    void DeleteAll(Tree * ptree)
    {
        if (ptree->root != NULL)
            DeleteAllNodes(ptree->root);
        ptree->size = 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	17.8.h
    #ifndef _TREE_H
    #define _TREE_H
    #include <stdbool.h>
    #define TREEMAX 20

    typedef struct item
    {
        char petname[20];
        char petkind[20];
    }Item;

    typedef struct node_list
    {
        Item item;
        struct node_list * next;
    }List;
    typedef struct node_tree
    {
        List * list;
        int list_size;
        struct node_tree * left;
        struct node_tree * right;
    }Node;

    typedef struct tree
    {
        Node * root;
        int size;
    }Tree;


    void InitTree(Tree * ptree);
    bool TreeIsEmpty(const Tree * ptree);
    bool TreeIsFull(const Tree * ptree);
    int TreeItemCount(const Tree * ptree);
    bool InTree(const Item * pi, const Tree * ptree);
    bool AddTreeItem(const Item * pi, Tree * ptree);
    bool DeleteItem(const Item * pi, Tree * ptree);
    void Traverse(const Tree * ptree, void(*pfun)(List * list));
    void DeleteAll(Tree * ptree);
    #endif
	{% endhighlight %}
	
---

	{% highlight ruby %}
	17.8.test.c
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include "17.8.h"

    char menu(void);
    void addpet(Tree * pt);
    void droppet(Tree * pt);
    void showpets(const Tree * pt);
    void findpet(const Tree * pt);
    void printitem(List * list);
    void uppercase(char * str);
    int ListItemCount(Node * root);

    int main(void)
    {
        Tree pets;
        char choice;
        int conut=0, temp=0;

        InitTree(&pets);
        while ((choice = menu()) != 'q')
        {
            switch (choice)
            {
            case 'a': addpet(&pets);
                break;
            case 'l': showpets(&pets);
                break;
            case 'f': findpet(&pets);
                break;
            case 'n':
                conut = ListItemCount(pets.root);
                conut -= temp;
                temp += conut;
                printf("%d pets in club\n", conut);
                break;
            case 'd': droppet(&pets);
                break;
            default: puts("Switching error");
            }
        }
        DeleteAll(&pets);
        puts("Bye.");

        return 0;
    }

    char menu(void)
    {
        int ch;

        puts("Nerfville pet Club Membership Program");
        puts("Enter the letter corresponding to your choice: ");
        puts("a)add a per     l)show list of pets");
        puts("n)number of pets    f)find pets");
        puts("d)delete a pet        q)quit");
        while ((ch = getchar()) != EOF)
        {
            while (getchar() != '\n')
                continue;
            ch = tolower(ch);
            if (strchr("alrfndq", ch) == NULL)
                puts("Please enter an a, l, f, n, d, or q: ");
            else
                break;
        }
        if (ch == EOF)
            ch = 'q';

        return ch;
    }

    void addpet(Tree * pt)
    {
        Item temp;

        if (TreeIsFull(pt))
            puts("No room in the club!");
        else
        {   //
            puts("Please enter name of pet: ");
            gets(temp.petname);
            puts("Please enter pet kind: ");
            gets(temp.petkind);
            uppercase(temp.petname);
            uppercase(temp.petkind);
            AddTreeItem(&temp, pt);
        }
    }

    void showpets(const Tree * pt)
    {
        if (TreeIsEmpty(pt))
            puts("No entries!");
        else
            Traverse(pt, printitem);
    }

    void printitem(List * list)
    {
        while (list != NULL)
        {
            printf("pet: %-19s kind: %-19s\n", list->item.petname,
                list->item.petkind);
            list = list->next;
        }
    }

    void findpet(const Tree * pt)
    {
        Item temp;

        if (TreeIsEmpty(pt))
        {
            puts("No entries!");
            return;
        }

        puts("Please enter name of pet you wish to find: ");
        gets(temp.petname);
        puts("Please enter pet kind: ");
        gets(temp.petkind);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        printf("%s the %s ", temp.petkind, temp.petname);
        if (InTree(&temp, pt))
            printf("is a member.\n");
        else
            printf("is not a member .\n");
    }

    void droppet(Tree * pt)
    {
        Item temp;

        if (TreeIsEmpty(pt))
        {
            puts("No entries!");
            return;
        }
        puts("Please enter name of pet you wish to delete: ");
        gets(temp.petname);
        puts("Please enter pet kind: ");
        gets(temp.petkind);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        printf("%s the %s ", temp.petname, temp.petkind);

        if (DeleteItem(&temp, pt))
            printf("is dropped from the club.\n");
        else
            printf("is not a member.\n");
    }

    void uppercase(char * str)
    {
        while (*str)
        {
            *str = toupper(*str);
            str++;
        }
    }

    int ListItemCount(Node * root)
    {
        static int conut = 0;

        if (root != NULL)
        {
            ListItemCount(root->left);
            conut += root->list_size;
            ListItemCount(root->right);
        }

        return conut;
    }
	{% endhighlight %}
	
---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
