#include "hblk_crypto.h"

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
	unsigned int len = 0;

	if (key == 0 || msg == 0)
		return (NULL);
	sig = malloc(sizeof(sig_t));
	ECDSA_sign(0, (const unsigned char *)msg, (int)msglen,
		   (unsigned char *)sig, &len, (EC_KEY *)key);
	sig->len = (uint8_t)strlen((char *)sig->sig);
	printf("%d", (int)sig->len);
	return ((uint8_t *)sig->sig);
}
