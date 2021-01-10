#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "blockchain.h"

/**
 * struct Visitor - visitor struct for collect sender's unspent
 * @sender_unspent: list to collect sender's unspent tx
 * @sender_pub: sender's public key
 * @total_amount: of unspent tx
 * @amount: amount to send
 */
typedef struct Visitor
{
	llist_t *sender_unspent;
	uint8_t *sender_pub;
	uint64_t total_amount;
	uint64_t amount;

} visitor_t;

#endif
