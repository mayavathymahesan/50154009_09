#include <stdio.h>
#include <fcntl.h>    /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <mqueue.h>
#include<string.h>

mqd_t pmq;
struct mq_attr pmq_attr;
char buff[128];
int msg_prio;

int main(int argc, char const *argv[])
{
    pmq_attr.mq_flags = 0;
    pmq_attr.mq_maxmsg = 6;
    pmq_attr.mq_msgsize = 128;
    pmq_attr.mq_curmsgs = 0;

    pmq = mq_open("/pmq", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR, &pmq_attr);

    mq_receive(pmq, buff, 128, &msg_prio);
    printf("Reieved stings: %s\n length of string : %d\n", buff, strlen(buff));

    mq_close(pmq);
    return 0;
}