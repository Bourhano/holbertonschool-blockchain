#include "hblk_crypto.h"

/**
 * ec_create - Creates a new EC key pair
 *
 * Return: pointer to the EC_key structure
 **/
EC_KEY *ec_create(void)
{
	EC_KEY *k;

	k = EC_KEY_new_by_curve_name(EC_CURVE);
	EC_KEY_generate_key(k);
	return (k);
}
