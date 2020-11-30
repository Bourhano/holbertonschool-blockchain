#include "hblk_crypto.h"

/**
 * ec_from_pub - Creat an EC_KEY opaque structure given a public key
 * @pub: address at which the public key is stored
 *
 * Return: pointer to the EC_KEY structure
 **/
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY *key;
	const EC_POINT *pt = NULL;

	if (pub == 0)
		return (0);
	key = EC_KEY_new_by_curve_name(EC_CURVE);
	pt = EC_POINT_new(EC_KEY_get0_group(key));
	if (EC_POINT_oct2point(EC_KEY_get0_group(key),
			       (EC_POINT *)pt, pub, EC_PUB_LEN, NULL) == 0)
	{
		EC_POINT_free((EC_POINT *)pt);
		return (0);
	}
	EC_KEY_set_public_key(key, pt);
	EC_POINT_free((EC_POINT *)pt);
	return (key);
}
