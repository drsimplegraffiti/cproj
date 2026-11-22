/*
 * Chapter 6 - Contact Management System
 * contact.h - Contact data structure and constants.
 */

#ifndef CONTACT_H
#define CONTACT_H

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
} Contact;

#endif
