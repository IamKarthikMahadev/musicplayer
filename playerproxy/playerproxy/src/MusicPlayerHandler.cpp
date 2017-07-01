


#include "Settings.h"
#include "MusicPlayerHandler.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define MSGSZ     128


/*
 * Declare the message structure.
 */

typedef struct msgbuf {
    long    mtype;
    char    mtext[MSGSZ];
} message_buf;

namespace MusicPlayer
{
    void* MusicPlayerHandlerThread(void* intArg)
    {
        int msqid;
        key_t key;
        message_buf  rbuf;
        
        /*
         * Get the message queue id for the
         * "name" 1234, which was created by
         * the server.
         */
        key = 1234;
        
        do {

            
            if ((msqid = msgget(key, 0666)) < 0) {
                perror("msgget");
                return 0;
            }
            
            
            /*
             * Receive an answer of message type 1.
             */
            if (msgrcv(msqid, &rbuf, MSGSZ, 1, 0) < 0) {
                perror("msgrcv");
                return 0;
            }
            
            /*
             * Print the answer.
             */
            printf("Got %s\n", rbuf.mtext);
            //return 0;
            

        } while (1);
        
       
        return 0;
        
    }
}
