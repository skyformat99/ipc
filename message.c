#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"

Message* messageCreate(char* data, size_t len){
  Message* ret = malloc(sizeof(Message));
  ret->data = data;
  ret->len = len;
  ret->type = CONN_TYPE_ALL;
}

void messageSetPID(Message* msg, pid_t pid){
  if(msg->type == CONN_TYPE_SUB){
    free(msg->subject);
  }
  msg->type = CONN_TYPE_PID;
  msg->pid = pid;
}

void messageSetSubject(Message* msg, char* subject){
  if(msg->type == CONN_TYPE_SUB){
    free(msg->subject);
  }
  msg->type = CONN_TYPE_SUB;
  msg->subject = malloc(strlen(subject));
  memcpy(msg->subject, subject, strlen(subject));
}

void messageDestroy(Message* msg){
  if(msg->type == CONN_TYPE_SUB){
    free(msg->subject);
  }
  free(msg);
}
