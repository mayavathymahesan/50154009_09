#include <stdio.h>
#include <fcntl.h>    /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <mqueue.h>

mqd_t pmq;
struct mq_attr pmq_attr;

int main(int argc, char const *argv[])
{
    pmq_attr.mq_flags = 0;
    pmq_attr.mq_maxmsg = 4;
    pmq_attr.mq_msgsize = 128;
    pmq_attr.mq_curmsgs = 0;

    pmq = mq_open("/pmq", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &pmq_attr);

    mq_send(pmq, "mstart", 6, 0);

    mq_close(pmq);
    return 0;
}