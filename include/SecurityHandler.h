/**
 * @file SecurityHandler.h
 * @brief Abstract Handler interface for Chain of Responsibility
 * @version 5.0
 * @date 03/12/2025
 *
 * @authors
 * - 220201047: Security System - Chain of Responsibility (Interface)
 *
 * @patterns Chain of Responsibility
 */

#ifndef SECURITYHANDLER_H
#define SECURITYHANDLER_H

class SecurityHandler
{
protected:
    SecurityHandler *next;

public:
    SecurityHandler();
    virtual ~SecurityHandler();

    void setNext(SecurityHandler *nextHandler);
    virtual void handleRequest();
};

#endif // SECURITYHANDLER_H
