
#import <pthread.h>
#import <stdlib.h>
#import <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>


#include "MessageHelper.h"
#define MSGSZ     128
/*
 * Declare the message structure.
 */

typedef struct msgbuf {
    long    mtype;
    char    mtext[MSGSZ];
} message_buf;

namespace MessageHelper
{
    bool SendMessage(MessageType::MessageEnum messageTypeEnum)
    {
        std::string message;
        
        if(!MessageType::GetMessageString(messageTypeEnum,message))
            {
                //Not a valid message
                return false;
            }
            int msqid;
            int msgflg = IPC_CREAT | 0666;
            key_t key;
            message_buf sbuf;
            size_t buf_length;
            
            key = 1234;
            
            if ((msqid = msgget(key, msgflg )) < 0) {
                perror("msgget");
                
                return 0;
            }
            sbuf.mtype = 1;
        
            strcpy(sbuf.mtext, message.c_str());
            buf_length = strlen(sbuf.mtext) + 1 ;
            
            /*
             * Send a message.
             */
            if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
                printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
                perror("msgsnd");
                return 0;
            }
        return true;
            
    }
}
