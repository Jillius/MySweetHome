/**
 * @file SecurityHandler.cpp
 * @brief Implementation of Security Handler interface
 * @version 5.0
 * @date 03/12/2025
 *
 * @authors
 * - 220201047: Security System - Chain of Responsibility (Interface)
 *
 * @patterns Chain of Responsibility
 */

#include "SecurityHandler.h"
#include <cstddef> // for NULL

SecurityHandler::SecurityHandler() : next(NULL) {}

SecurityHandler::~SecurityHandler() {}

void SecurityHandler::setNext(SecurityHandler *nextHandler)
{
    next = nextHandler;
}

void SecurityHandler::handleRequest()
{
    if (next != NULL)
    {
        next->handleRequest();
    }
}
