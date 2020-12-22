#include "blockchain.h"

/**
 * hash_matches_difficulty -  checks whether a given hash matches
 * a given difficulty
 * @hash: the hash to check
 * @difficulty: the minimum difficulty the hash should match
 *
 * Return: 1 if the difficulty is respected, or 0 otherwise
 */
hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
			uint32_t difficulty)
{
	uint8_t hash_buf[SHA256_DIGEST_LENGTH] = {0};
	block_t const _genesis = GENESIS_BLOCK;

	if (!block || (!prev_block && block->info.index != 0))
		return (1);
	if (block->info.index == 0)
		return (memcmp(block, &_genesis, sizeof(_genesis)));
	if (block->info.index != prev_block->info.index + 1)
		return (1);
	if (!block_hash(prev_block, hash_buf) ||
	    memcmp(hash_buf, prev_block->hash, SHA256_DIGEST_LENGTH))
		return (1);
	if (memcmp(prev_block->hash, block->info.prev_hash,
		   SHA256_DIGEST_LENGTH))
		return (1);
	if (!block_hash(block, hash_buf) ||
	    memcmp(hash_buf, block->hash, SHA256_DIGEST_LENGTH))
		return (1);
	if (block->data.len > BLOCKCHAIN_DATA_MAX)
		return (1);
	return (0);
}
