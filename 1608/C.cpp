#include "os2021_thread_api.h"
struct itimerval Signaltimer;

int OS2021_ThreadCreate(char *job_name, char *p_function, int priority, int cancel_mode)
{
    JsonNode *t = HEAD;
    bool findit = false;
    while (t != NULL)
    {
        if (strcmp(t->name, job_name) == 0)
        {
            findit = true;
            break;
        }
        t = t->next;
    }
    char priority_chr = Priority_int2Char(priority);
    // Global Variable
    PIDindex++;
    if (!findit)
    {
        JsonNode *Node = JsonNode_Create(job_name, p_function, priority_chr, cancel_mode, PIDindex, "READY");
        HEAD = JsonNode_Insert(HEAD, Node);
        READY_QUEUE[priority] = Queue_PUSH(READY_QUEUE[priority], Node, "READY");
    }
    CreateContext(&temp->dispatch_context, NULL, &Dispatcher);
    return PIDindex;
}

void OS2021_ThreadCancel(char *job_name)
{
}

void OS2021_ThreadWaitEvent(int event_id)
{
    // From RUN To Waiting Queue
    printf("%s wants to wait for event %d\n", RUN_QUEUE->Thread->name, event_id);
    RUN_QUEUE->Thread->event_id = event_id;
    JsonNode *tt = RUN_QUEUE->Thread;
    int priority = Priority_Char2int(RUN_QUEUE->Thread->C_priority);
    if (priority > 0) // NOT HIGH
    {
        if (RUN_QUEUE->Thread->Quantum > 0)
        {
            printf("The priority of the thread %s is change from %c to %c\n",
                   RUN_QUEUE->Thread->name,
                   RUN_QUEUE->Thread->C_priority,
                   Priority_int2Char(priority - 1));
            RUN_QUEUE->Thread->C_priority = Priority_int2Char(priority - 1);
        }
    }
    RUN_QUEUE->Thread->Quantum = 0;
    WAIT_QUEUE[priority] = Queue_PUSH(WAIT_QUEUE[priority], RUN_QUEUE->Thread, "WAITING");
    GOTO_RUN_QUEUE();
    RUN_QUEUE->Thread->Quantum = Priority_Time[Priority_Char2int(RUN_QUEUE->Thread->C_priority)];
    swapcontext(&tt->dispatch_context, &RUN_QUEUE->Thread->dispatch_context);
}

void OS2021_ThreadSetEvent(int event_id)
{
    //From Waiting to Ready
    Queue *t, *last;
    JsonNode *jt;
    bool find = false;
    for (int i = 0; i < 3; ++i)
    {
        if (WAIT_QUEUE[i] == NULL)
            continue;
        if (WAIT_QUEUE[i]->Thread->event_id == event_id)
        {
            jt = t->Thread;
            WAIT_QUEUE[i] = WAIT_QUEUE[i]->next;
            find = true;
            break;
        }
        else // Not Head
        {
            t = WAIT_QUEUE[i], last = WAIT_QUEUE[i];
            while (t != NULL)
            {
                if (t->Thread->event_id == event_id)
                {
                    jt = t->Thread;
                    last->next = t->next; // WAIT_QUEUE
                    find = true;
                    break;
                }
                last = t, t = t->next;
            }
        }
        if (find)
        {
            printf("%s changes the status of %s to READY.\n", jt->name, RUN_QUEUE->Thread->name);
            int priority = Priority_Char2int(jt->C_priority);
            READY_QUEUE[priority] = Queue_PUSH(READY_QUEUE[priority], jt, "READY");
            break;
        }
    }
}

void OS2021_ThreadWaitTime(int msec)
{
}

void OS2021_DeallocateThreadResource()
{
}

void OS2021_TestCancel()
{
}

void CreateContext(ucontext_t *context, ucontext_t *next_context, void *func)
{
    getcontext(context);
    context->uc_stack.ss_sp = malloc(STACK_SIZE);
    context->uc_stack.ss_size = STACK_SIZE;
    context->uc_stack.ss_flags = 0;
    context->uc_link = next_context;
    makecontext(context, (void (*)(void))func, 0);
}

void ResetTimer()
{
    Signaltimer.it_value.tv_sec = 0;
    Signaltimer.it_value.tv_usec = 10;
    if (setitimer(ITIMER_REAL, &Signaltimer, NULL) < 0)
    {
        printf("ERROR SETTING TIME SIGALRM!\n");
        exit(-1);
    }
}

void Dispatcher()
{
    if (strcmp(RUN_QUEUE->Thread->entry, "Function1") == 0)
        return (void)Function1();
    if (strcmp(RUN_QUEUE->Thread->entry, "Function2") == 0)
        return (void)Function2();
    if (strcmp(RUN_QUEUE->Thread->entry, "Function3") == 0)
        return (void)Function3();
    if (strcmp(RUN_QUEUE->Thread->entry, "Function4") == 0)
        return (void)Function4();
    if (strcmp(RUN_QUEUE->Thread->entry, "Function5") == 0)
        return (void)Function5();
    if (strcmp(RUN_QUEUE->Thread->entry, "ResourceReclaim") == 0)
        return (void)ResourceReclaim();
}
int Priority_Char2int(char ch)
{
    int priority = 0;
    switch (ch)
    {
    case 'L':
        priority++;
    case 'M':
        priority++;
    case 'H':;
    }
    return priority;
}
char Priority_int2Char(int priority)
{
    if (priority <= 0)
        return 'H';
    else if (priority == 1)
        return 'M';
    else if (priority >= 2)
        return 'L';
    else
        return 'L';
}
void Queue_INIT()
{
    READY_QUEUE = (Queue **)malloc(3 * sizeof(Queue *));
    READY_QUEUE[0] = NULL;
    READY_QUEUE[1] = NULL;
    READY_QUEUE[2] = NULL;
    WAIT_QUEUE = (Queue **)malloc(3 * sizeof(Queue *));
    WAIT_QUEUE[0] = NULL;
    WAIT_QUEUE[1] = NULL;
    WAIT_QUEUE[2] = NULL;
    RUN_QUEUE = (Queue *)malloc(sizeof(Queue));
    RUN_QUEUE->next = NULL;
    RUN_QUEUE->Thread = (JsonNode *)malloc(sizeof(JsonNode));
}
void StartSchedulingSimulation()
{
    Priority_Time[0] = 100, Priority_Time[1] = 200, Priority_Time[2] = 300;
    Signaltimer.it_interval.tv_usec = 10;
    Signaltimer.it_interval.tv_sec = 0;
    ResetTimer();
    temp = HEAD->next;
    Queue_INIT();
    PIDindex = 0;
    int priority = 0;
    while (temp != NULL)
    {
        priority = Priority_Char2int(temp->priority);
        temp->PID = OS2021_ThreadCreate(temp->name, temp->entry, priority, temp->cancel_mode);
        READY_QUEUE[priority] = Queue_PUSH(READY_QUEUE[priority], temp, "READY");
        temp = temp->next;
    }
    temp = HEAD;
    priority = Priority_Char2int(temp->priority);
    temp->PID = OS2021_ThreadCreate(temp->name, temp->entry, priority, temp->cancel_mode);
    READY_QUEUE[priority] = Queue_PUSH(READY_QUEUE[priority], temp, "READY");
    GOTO_RUN_QUEUE();
    Start_Scheduling();
}
void Start_Scheduling()
{
    RUN_QUEUE->Thread->Quantum = Priority_Time[Priority_Char2int(RUN_QUEUE->Thread->C_priority)];
    swapcontext(&main_context, &RUN_QUEUE->Thread->dispatch_context);
}
JsonNode *ReadJson()
{
    char buffer[1024], mode[30], name[30], entry[30], priority, cancel_mode;
    bool Count_thread = false;
    FILE *fp = fopen("init_threads.json", "r");
    // Create Node
    JsonNode *Head = JsonNode_Create("reclaimer", "ResourceReclaim", 'L', 1, 0, "READY");
    init_thread_num = 1;
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        sscanf(buffer, "%s", mode);
        if (!Count_thread)
        {
            if (mode[0] == '{')
                Count_thread = true;
        }
        else
        {
            if (mode[0] == '{')
                continue;
            sscanf(buffer, " \"%s\" ", mode);
            switch (mode[0])
            {
            case 'n':
                sscanf(buffer, " \"name\" : \"%2s", name);
                break;
            case 'e':
                sscanf(buffer, " \"entry function\" : \"%9s", entry);
                break;
            case 'p':
                sscanf(buffer, " \"priority\": \"%c ", &priority);
                break;
            case 'c':
                sscanf(buffer, " \"cancel mode\": \"%c ", &cancel_mode);
                Head = JsonNode_Insert(Head, JsonNode_Create(name, entry, priority, cancel_mode - '0', 0, "READY"));
                init_thread_num += 1;
                break;
            default:
                break;
            }
        }
    }
    fclose(fp);
    printf("# of init Thread %d\n", init_thread_num);
    return Head;
}
JsonNode *JsonNode_Create(char *name, char *entry, char priority, int cancel_mode, int PID, char *state)
{
    JsonNode *news = (JsonNode *)malloc(sizeof(JsonNode));
    news->name = (char *)malloc(20 * sizeof(char));
    news->entry = (char *)malloc(15 * sizeof(char));
    news->priority = priority;
    news->C_priority = priority;
    news->cancel_mode = cancel_mode;
    news->next = NULL;
    news->PID = PID;
    news->state = (char *)malloc(15 * sizeof(char));
    news->W_Time = 0;
    news->Q_Time = 0;
    news->count = 0;
    news->event_id = -1;
    strcpy(news->name, name);
    strcpy(news->entry, entry);
    strcpy(news->state, state);
    return news;
}
JsonNode *JsonNode_Insert(JsonNode *Head, JsonNode *news)
{
    JsonNode *t = Head;
    while (t->next != NULL)
        t = t->next;
    t->next = news;
    return Head;
}
JsonNode *Queue_FRONT(Queue *qu)
{
    return qu->Thread;
}
Queue *Queue_POP(Queue *qu)
{
    return qu->next;
}
Queue *Queue_NODE(JsonNode *now, char *state)
{
    Queue *t = (Queue *)malloc(sizeof(Queue));
    t->next = NULL;
    t->Thread = now;
    t->Thread->state = (char *)malloc(sizeof(state));
    t->Thread->state = state;
    return t;
}
Queue *Queue_PUSH(Queue *qu, JsonNode *now, char *state)
{
    if (qu == NULL)
        return Queue_NODE(now, state);
    Queue *t = qu;
    while (t->next != NULL)
        t = t->next;
    t->next = Queue_NODE(now, state);
    return qu;
}
int Queue_SIZE(Queue *qu)
{
    Queue *t = qu;
    int result = 0;
    while (t != NULL)
        ++result, t = t->next;
    return result;
}
void Queue_ReadList(Queue *qu)
{
    Queue *t = qu;
    while (t != NULL)
        JsonNode_Read(t->Thread), t = t->next;
    return;
}
void GOTO_RUN_QUEUE()
{
    for (int i = 0; i <= 2; ++i)
    {
        if (READY_QUEUE[i] != NULL)
        {
            RUN_QUEUE->Thread = Queue_FRONT(READY_QUEUE[i]);
            RUN_QUEUE->Thread->state = (char *)malloc(10 * sizeof(char));
            strcpy(RUN_QUEUE->Thread->state, "RUNNING");
            READY_QUEUE[i] = Queue_POP(READY_QUEUE[i]);
            return;
        }
    }
    return;
}
void Signal_Ctrl_z(int sig)
{
    JsonNode *report = HEAD;
    printf("\n*****************************************************************************************\n");
    printf("*\tTID\tName\t\tState\tB_Priority\tC_Priority\tQ_Time\tW_Time\t*\n");
    while (report != NULL)
    {
        printf("*\t%d\t", report->PID);
        if (strlen(report->name) > 3)
            printf("%s\t", report->name);
        else
            printf("%s\t\t", report->name);
        printf("%s\t", report->state);
        printf("%c\t\t", report->priority);
        printf("%c\t\t", report->C_priority);
        printf("%llu\t", report->Q_Time);
        printf("%llu\t*\n", report->W_Time);
        report = report->next;
    }
    printf("*****************************************************************************************\n");
    // WaitQUEUE();
}
void Signal_Clock_10ms(int sig)
{
    Queue *t, *tt;
    for (int i = 0; i <= 2; ++i)
    {
        t = READY_QUEUE[i];
        while (t != NULL)
            t->Thread->Q_Time += 1, t = t->next;
        tt = WAIT_QUEUE[i];
        while (tt != NULL)
            tt->Thread->W_Time += 1, tt = tt->next;
    }
    RUN_QUEUE->Thread->Quantum -= 10;
    if (RUN_QUEUE->Thread->Quantum < 0)
    {
        // Context Switch
    }
}
void JsonNode_ReadList(JsonNode *Head)
{
    while (Head != NULL)
        JsonNode_Read(Head), Head = Head->next;
}
void JsonNode_Read(JsonNode *Head)
{
    printf("%9s %15s %c %2d %d %s\n", Head->name, Head->entry, Head->priority, Head->cancel_mode, Head->PID, Head->state);
}
void WaitQUEUE()
{
    Queue *tt;
    for (int i = 0; i <= 2; ++i)
    {
        tt = WAIT_QUEUE[i];
        while (tt != NULL)
            printf("Wait[%d] = %s\n", i, tt->Thread->name), tt = tt->next;
    }
}