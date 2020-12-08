#include "blockchain.h"

/**
 * blockchain_create - Creates a Blockchain structure, and initializes it
 *
 * Return: pointer to the blockchain structure
 **/
blockchain_t *blockchain_create(void)
{
	blockchain_t *blkchn;
	block_t genesis = {
		{ /* info */
			0 /* index */,
			0, /* difficulty */
			1537578000, /* timestamp */
			0, /* nonce */
			"\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0"
			"\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0\x0"
			/* prev_hash */
		},
		{ /* data */
			"", /* buffer */
			(uint32_t)16 /* len */
		},
		{"\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a"
		 "\x97\xd4"
		 "\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51"
		 "\x58\x03"} /*hash*/
	};
	llist_t *head ;

	blkchn = malloc(sizeof(blockchain_t));
	head = llist_create(MT_SUPPORT_TRUE);
	llist_add_node(head, &genesis, ADD_NODE_FRONT);
	blkchn->chain = head;
	return (blkchn);
}
