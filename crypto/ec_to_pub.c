#include "hblk_crypto.h"

/**
 * ec_to_pub - Extracts the public key from an EC_KEY opaque structure
 * @key: pointer to the EC_KEY structure to retrieve the public key from
 * @pub: address at which to store the extracted public key
 *
 * Return: pointer to the public key @pub
 **/
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_POINT *pt;

	if (key == 0)
		return (0);
	pt = EC_KEY_get0_public_key(key);
	EC_POINT_point2oct(EC_KEY_get0_group(key),
			   pt, POINT_CONVERSION_UNCOMPRESSED,
			   pub, EC_PUB_LEN, NULL);
	return (pub);
}
