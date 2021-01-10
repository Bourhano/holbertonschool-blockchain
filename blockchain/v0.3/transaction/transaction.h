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

/**
 * struct Validation_Visitor - visitor struct for tx validation
 * @in_amount: total txi amount
 * @out_amount: total txo amount
 * @valid: 1 if tx valid else 0
 * @all_unspent: all unspent txs
 * @tx: the tx to validate
 * @block_index: the block index cointaining tx
 */
typedef struct Validation_Visitor
{
	long in_amount;
	long out_amount;
	int valid;
	llist_t *all_unspent;
	transaction_t const *tx;
	uint32_t block_index;
} validation_vistor_t;

#endif
