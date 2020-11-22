#include "hblk_crypto.h"

/**
 * sha256 - Returns the pointer to the hash of the input sequence
 * @s: the sequence of bytes to be hashed
 * @len: the number of bytes to hash in @s
 * @digest: the pre-defined area to store the hash
 *
 * Return: pointer to the hash
 **/
uint8_t *sha256(int8_t const *s, size_t len,
		uint8_t digest[SHA256_DIGEST_LENGTH])
{
	size_t i = 0;

	if (digest == 0)
		return (0);
	for(i = 0; i < len; i++)
	{
		sprintf(digest + (i * 2), s[i]);
	}
	digest[len] = 0;
	return (digest);
}
