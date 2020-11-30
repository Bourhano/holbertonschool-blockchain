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
	if (digest == 0)
		return (0);
	return (SHA256((const unsigned char *)s, len, digest));
}

/**
 * ec_sign - Signs a given set of bytes, using a given EC_KEY private key
 * @key: EC key pair already generated
 * @msg: message to be signed
 * @msglen: length of that message
 * @sig: pointer to save the signature into
 *
 * Return: pointer to the signature on sucess, NULL on failure
 **/
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
		 sig_t *sig)
{
	uint8_t hash[SHA256_DIGEST_LENGTH];

	if (key == 0 || msg == 0 || sig == 0)
		return (NULL);
	if (sha256((int8_t *)msg, msglen, hash) == 0)
		return (0);
	if (ECDSA_sign(0, (const unsigned char *)hash, SHA256_DIGEST_LENGTH,
		       (unsigned char *)sig->sig, (unsigned int *)&(sig->len),
		       (EC_KEY *)key) == 0)
		return (0);
	return (sig->sig);
}
