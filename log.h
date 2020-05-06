typedef struct LogEntry
{
    int turn;
    char player;
    int location[2];
}LogEntry;

typedef struct LogNode
{
    LogEntry * logEntry;
    LogEntry * next;


}LogNode;

typedef struct LogList
{
    LogEntry * head;
}LogList;

LogList* CreateLog();
