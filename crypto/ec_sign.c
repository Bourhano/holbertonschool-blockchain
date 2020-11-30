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
	const ECDSA_SIG *signature;

	signature = ECDSA_do_sign(msg, msglen, (EC_KEY *)key);
	sig = malloc(sizeof(sig_t));
	i2d_ECDSA_SIG(signature, (unsigned char **)&sig);
	sig->len = strlen((char *)sig->sig);
	return ((uint8_t *)sig->sig);
}
