#include "hblk_crypto.h"


/**
 * ec_verify - Verifies a given set of bytes, using a given EC_KEY private key
 * @key: EC key pair already generated
 * @msg: message to be signed
 * @msglen: length of that message
 * @sig: pointer to save the signature into
 *
 * Return: pointer to the signature on sucess, NULL on failure
 **/
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
		 sig_t const *sig)
{
	uint8_t hash[SHA256_DIGEST_LENGTH];

	if (key == 0 || msg == 0 || sig == 0)
		return (0);
	if (SHA256(msg, msglen, hash) == 0)
		return (0);
	if (ECDSA_verify(0, (const unsigned char *)hash, SHA256_DIGEST_LENGTH,
		       (unsigned char *)sig->sig, (int)(sig->len),
		       (EC_KEY *)key) == 0)
		return (0);
	return (1);
}
